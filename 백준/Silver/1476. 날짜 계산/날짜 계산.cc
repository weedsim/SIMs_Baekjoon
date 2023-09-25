// CRT_SECURE 에 대한 에러를 무시하는 용도이다. 간단한 알고리즘에서는 CRT_SECURE는 필요없기에 무시해도 된다.
#define _CRT_SECURE_NO_WARNINGS
// C++ 의 기본이다.
#include <iostream> 
// 이번에는 없어도 되지만 편의를 위해 존재하고 있다.
#include <algorithm>
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

	int E, S, M;
	cin >> E >> S >> M; // E => 15   S => 28    M => 19

	while (true) {

		if (E == S && E == M) {
			break;
		}
		
		if (E <= S && E <= M) {
			if (E == S) {
				E += 420;
				S += 420;
			}
			else if (E == M) {
				E += 285;
				M += 285;
			}
			else {
				E += 15;
			}
		}
		else if (S <= E && S <= M) {
			if (S == E) {
				E += 420;
				S += 420;
			}
			else if (S == M) {
				S += 532;
				M += 532;
			}
			else {
				S += 28;
			}
		}
		else if (M <= E && M <= S) {
			if (M == E) {
				E += 285;
				M += 285;
			}
			else if (M == S) {
				S += 532;
				M += 532;
			}
			else {
				M += 19;
			}
		}

	}

	cout << E;

	return 0;
}
