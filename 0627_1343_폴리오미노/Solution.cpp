// CRT_SECURE 에 대한 에러를 무시하는 용도이다. 간단한 알고리즘에서는 CRT_SECURE는 필요없기에 무시해도 된다.
#define _CRT_SECURE_NO_WARNINGS
// C++ 의 기본이다.
#include <iostream> 
// 이번에는 없어도 되지만 편의를 위해 존재하고 있다.
#include <algorithm>
// 입력을 위해
#include <string>
// 일반적으로 std 를 붙여가면서 할 것을 미리 명시하는 방식으로 편의를 위해 존재한다.
using namespace std;



int main()
{
	// 아래 세 줄은 입력과 출력의 시간을 줄여주기위해 존재한다.
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int cnt = 0;
	string board;
	cin >> board;
	string ans;
	bool wrong = false;
	int _size = board.size();
	for (int i = 0; i < _size; i++) {
		if (wrong) { break; }
		if (board[i] == 'X') { cnt++; }
		else {

			while (!wrong) {
				// AAAA 가 하나 이상 있다.
				if (cnt / 4 > 0) {
					ans += "AAAA";
					cnt -= 4;
				}
				// BB 가 하나 이상 있다.
				else if (cnt / 2 > 0) {
					ans += "BB";
					cnt -= 2;
				}
				// AAAA 도 BB 도 하나 없다.
				else {
					if (cnt == 0) {
						ans += ".";
						break;
					}
					else {
						ans = '-';
						ans += '1';
						wrong = true;
					}
				}
			}
		}
	}

	while (!wrong) {
		// AAAA 가 하나 이상 있다.
		if (cnt / 4 > 0) {
			ans += "AAAA";
			cnt -= 4;
		}
		// BB 가 하나 이상 있다.
		else if (cnt / 2 > 0) {
			ans += "BB";
			cnt -= 2;
		}
		// AAAA 도 BB 도 하나 없다.
		else {
			if (cnt == 0) {
				break;
			}
			else {
				ans = '-';
				ans += '1';
				wrong = true;
			}
		}
	}

	cout << ans;

	return 0;
}
