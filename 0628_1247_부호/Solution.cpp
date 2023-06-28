// CRT_SECURE 에 대한 에러를 무시하는 용도이다. 간단한 알고리즘에서는 CRT_SECURE는 필요없기에 무시해도 된다.
#define _CRT_SECURE_NO_WARNINGS
// C++ 의 기본이다.
#include <iostream> 
// 이번에는 없어도 되지만 편의를 위해 존재하고 있다.
#include <algorithm>
// 오버플로우를 위해
#include <climits>
// 일반적으로 std 를 붙여가면서 할 것을 미리 명시하는 방식으로 편의를 위해 존재한다.
using namespace std;



int main()
{
	// 아래 세 줄은 입력과 출력의 시간을 줄여주기위해 존재한다.
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int t = 0; t < 3; t++) {
		int N;
		cin >> N;
		
		long long _num = 0;
		long long _plus = 0;
		int _over = 0;

		for (int j = 0; j < N; j++) {
			cin >> _plus;
			// 기존 총합과 입력값의 합이 long long 의 최댓값을 넘어가면 오버플로우가 된다.
			if (_num > 0 && _plus > 0 && _plus > LLONG_MAX - _num) {
				_over++;
			}
			// 기존 총합과 입력값의 합이 long long 의 최솟값을 넘어가면 오버플로우가 된다.
			else if (_num < 0 && _plus < 0 && _plus < LLONG_MIN - _num) {
				_over--;
			}
			
			// 오버플로우가 되든 안되든 그냥 더해주기
			_num += _plus;

		}

		// 음수
		if (_over < 0) {
			cout << "-";
			cout << "\n";
		}
		// 양수
		else if (_over > 0) {
			cout << "+";
			cout << "\n";
		}
		// 오버플로우는 안 되지만
		else {
			// 양수
			if (_num > 0) {
				cout << "+";
				cout << "\n";
			}
			// 음수
			else if (_num < 0) {
				cout << "-";
				cout << "\n";
			}
			// 완전히 0
			else {
				cout << "0";
				cout << "\n";
			}
		}
	}

	return 0;
}
