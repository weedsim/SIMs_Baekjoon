// CRT_SECURE 에 대한 에러를 무시하는 용도이다. 간단한 알고리즘에서는 CRT_SECURE는 필요없기에 무시해도 된다.
#define _CRT_SECURE_NO_WARNINGS
// C++ 의 기본이다.
#include <iostream> 
// 편의를 위해 존재하고 있다.
#include <algorithm>
// 일반적으로 std 를 붙여가면서 할 것을 미리 명시하는 방식으로 편의를 위해 존재한다.
using namespace std;



int main()

{
	// 아래 세 줄은 입력과 출력의 시간을 줄여주기위해 존재한다.
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		string order;
		cin >> order;

		int _size = order.size();
		int fro = 500;

		int minY = 0;
		int maxY = 0;
		int minX = 0;
		int maxX = 0;
		int now[2] = { 0,0 }; // y, x 좌표기준

		for (int i = 0; i < _size; i++) {
			char temp = order[i];

			if (temp == 'L') {
				fro -= 1;
			}
			else if (temp == 'R') {
				fro += 1;
			}
			else if (temp == 'F') {
				if (fro % 4 == 0) {
					now[0] += 1;
				}
				else if (fro % 4 == 1) {
					now[1] += 1;
				}
				else if (fro % 4 == 2) {
					now[0] -= 1;
				}
				else if (fro % 4 == 3) {
					now[1] -= 1;
				}
			}
			else if (temp == 'B') {
				if (fro % 4 == 0) {
					now[0] -= 1;
				}
				else if (fro % 4 == 1) {
					now[1] -= 1;
				}
				else if (fro % 4 == 2) {
					now[0] += 1;
				}
				else if (fro % 4 == 3) {
					now[1] += 1;
				}
			}

			if (minX > now[1]) {
				minX = now[1];
			}

			if (minY > now[0]) {
				minY = now[0];
			}

			if (maxX < now[1]) {
				maxX = now[1];
			}

			if (maxY < now[0]) {
				maxY = now[0];
			}
		}

		cout << ((maxX - minX) * (maxY - minY)) << endl;
		

	}

	return 0;
}