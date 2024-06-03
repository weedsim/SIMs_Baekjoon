// CRT_SECURE 에 대한 에러를 무시하는 용도이다. 간단한 알고리즘에서는 CRT_SECURE는 필요없기에 무시해도 된다.
#define _CRT_SECURE_NO_WARNINGS
// C++ 의 기본이다.
#include <iostream> 
// 편의를 위해 존재하고 있다.
#include <algorithm>
#include <cstdlib>
#include <cmath>
// 임시 저장용도
#include <vector>
// 일반적으로 std 를 붙여가면서 할 것을 미리 명시하는 방식으로 편의를 위해 존재한다.
using namespace std;




int main()
{
	// 아래 세 줄은 입력과 출력의 시간을 줄여주기위해 존재한다.
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int N;
    vector<int> heights;
    vector<int> ans;

    cin >> N;
    for (int i = 0; i < N; i++) {
        int n;
        cin >> n;
        heights.push_back(n);
    }

    // 건물 0번부터 해서 볼 수 있는 빌딩을 파악 시도한다.

    vector<int> temp;
    for (int main = 0; main < N; main++) {
        int Lcnt = 0;
        int Rcnt = 0;
        // 볼 수 있는 빌딩인지 파악하기 위해서는 해당 빌딩과 그 사이에 존재하는 빌딩이 가로 막는 것이 있는지 확인하면 된다.

        // main의 왼쪽이 target일때
        for (int target = 0; target < main; target++) {
            double y = static_cast<double>(heights[main]) - static_cast<double>(heights[target]);
            int x = main - target;
            if (heights[main] == heights[target]) {
                bool fail = false;
                for (int check = target + 1; check < main; check++) {

                    if (heights[main] <= heights[check]) {
                        fail = true;
                        break;
                    }

                }
                if (!fail) {
                    Lcnt++;
                }
                continue;
            }
            bool mainUp = ((heights[main] - heights[target]) > 0);
            double grad = y / x; // 실제 y/x의 절댓값 -> 타겟과 메인 사이의 기울기

            bool fail = false;
            for (int check = target + 1; check < main; check++) {

                if (mainUp) { // main이 오른쪽 위로 가있는 삼각형 
                    double checkGrad = (static_cast<double>(heights[check] - heights[target])) / (check - target);
                    if (checkGrad >= grad) {
                        fail = true;
                        break;
                    }
                }
                else { // main이 오른쪽 아래로 가있는 삼각형
                    double checkGrad = (static_cast<double>(heights[main] - heights[check])) / (main - check);
                    if (checkGrad <= grad) {
                        fail = true;
                        break;
                    }
                }

            }

            if (fail) {
                continue;;
            }

            Lcnt++;

        }

        // main의 오른쪽이 target일 때
        for (int target = main + 1; target < N; target++) {
            int R = 0;
            double y = static_cast<double>(heights[target]) - static_cast<double>(heights[main]);
            int x = target - main;
            double grad = y / x; // y/x
            if (heights[main] == heights[target]) {
                bool fail = false;
                for (int check = main + 1; check < target; check++) {

                    if (heights[main] <= heights[check]) {
                        fail = true;
                        break;
                    }

                }
                if (!fail) {
                    Rcnt++;
                }
                continue;
            }
            bool mainUp = ((heights[main] - heights[target]) > 0);

            bool fail = false;
            for (int check = main + 1; check < target; check++) {

                if (mainUp) { // main이 왼쪽 위로 가있는 삼각형

                    double checkGrad = (static_cast<double>(heights[target] - heights[check])) / (target - check);

                    if (checkGrad <= grad) {
                        fail = true;
                        break;
                    }

                }
                else { // main이 왼쪽 아래로 가있는 삼각형
                    double checkGrad = (static_cast<double>(heights[check] - heights[main])) / (check - main);

                    if (checkGrad >= grad) {
                        fail = true;
                        break;
                    }
                }

            }

            if (fail) {
                continue;
            }

            Rcnt++;

        }

        ans.push_back(Lcnt + Rcnt);

    }

    sort(ans.begin(), ans.end(), greater<int>());

    cout << ans[0];

	return 0;
}

