// CRT_SECURE 에 대한 에러를 무시하는 용도이다. 간단한 알고리즘에서는 CRT_SECURE는 필요없기에 무시해도 된다.
#define _CRT_SECURE_NO_WARNINGS
// C++ 의 기본이다.
#include <iostream> 
// 이번에는 없어도 되지만 편의를 위해 존재하고 있다.
#include <algorithm>
// 일반적으로 std 를 붙여가면서 할 것을 미리 명시하는 방식으로 편의를 위해 존재한다.
using namespace std;



int main()
{
	// 아래 세 줄은 입력과 출력의 시간을 줄여주기위해 존재한다.
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	int _max = 0;

	for (int i = 0; i < N; i++) {
		int A, B, C;
		cin >> A >> B >> C;
		int mon;

		// 3개의 주사위가 같은 눈
		if (A == B && A == C && B == C) {
			mon = 10000 + (A * 1000);
		}
		// A 와 B 가 같은 눈
		else if (A == B) {
			mon = 1000 + (A * 100);
		}
		// B 와 C 가 같은 눈
		else if (B == C) {
			mon = 1000 + (B * 100);
		}
		// A 와 C 가 같은 눈
		else if (A == C) {
			mon = 1000 + (C * 100);
		}
		// 3개 주사위가 전부 다르면
		else {
			// A 가 가장 클 때
			if (A > B && A > C) {
				mon = A * 100;
			}
			// B 가 가장 클 때
			else if (B > A && B > C) {
				mon = B * 100;
			}
			// C 가 가장 클 때
			else {
				mon = C * 100;
			}
		}

		if (_max < mon) { _max = mon; }
	}

	cout << _max;

	return 0;
}
