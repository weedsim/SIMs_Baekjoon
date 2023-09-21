// CRT_SECURE 에 대한 에러를 무시하는 용도이다. 간단한 알고리즘에서는 CRT_SECURE는 필요없기에 무시해도 된다.
#define _CRT_SECURE_NO_WARNINGS
// C++ 의 기본이다.
#include <iostream> 
// 이번에는 없어도 되지만 편의를 위해 존재하고 있다.
#include <algorithm>
// 계산용
#include <cmath>
// 일반적으로 std 를 붙여가면서 할 것을 미리 명시하는 방식으로 편의를 위해 존재한다.
using namespace std;



int main()
{
	// 아래 세 줄은 입력과 출력의 시간을 줄여주기위해 존재한다.
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int N, A, B;
    cin >> N >> A >> B;

    int round = 1;
    while (N > 1) {
        if (abs(A - B) == 1 && (A + B) % 4 == 3) {
            break;
        }

        A = (A + 1) / 2;
        B = (B + 1) / 2;
        N = (N + 1) / 2;
        round++;
    }

    if (round > 0) { 
        cout << round;
    }
    else {
        cout << -1;
    }

	return 0;
}
