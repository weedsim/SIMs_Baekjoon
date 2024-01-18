// CRT_SECURE 에 대한 에러를 무시하는 용도이다. 간단한 알고리즘에서는 CRT_SECURE는 필요없기에 무시해도 된다.
#define _CRT_SECURE_NO_WARNINGS
// C++ 의 기본이다.
#include <iostream> 
// 편의를 위해 존재하고 있다.
#include <algorithm>
// 제곱을 위해 사용
#include <cmath>
// 입력용
#include <vector>
// 일반적으로 std 를 붙여가면서 할 것을 미리 명시하는 방식으로 편의를 위해 존재한다.
using namespace std;



int main()
{
	// 아래 세 줄은 입력과 출력의 시간을 줄여주기위해 존재한다.
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, r, c;
	cin >> N >> r >> c;

	int maxRange = pow(2, N);

	vector<int> cntZ;
	cntZ.clear();

	while (maxRange > 1) {
		maxRange /= 2;

		if (r / maxRange == 1) {

			if (c / maxRange == 1) {
				cntZ.push_back(3);
			}
			else {
				cntZ.push_back(2);
			}

		}
		else {

			if (c / maxRange == 1) {
				cntZ.push_back(1);
			}
			else {
				cntZ.push_back(0);
			}

		}

		r %= maxRange;
		c %= maxRange;
	}

	int cnt = 0;
	int ans = cntZ.back();
	cntZ.pop_back();

	while (!cntZ.empty()) {
		cnt++;
		ans += (pow(4, cnt) * cntZ.back());
		cntZ.pop_back();
	}

	cout << ans;

	return 0;
}
