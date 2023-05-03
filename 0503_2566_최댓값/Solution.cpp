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

	// 격자판
	int map[9][9];
	// 최댓값
	int max = -1;
	// 위치 y, x
	int y, x;

	for (int j = 0; j < 9; j++) {
		for (int i = 0; i < 9; i++) {
			cin >> map[j][i];
			if (max < map[j][i]) {
				max = map[j][i];
				y = j;
				x = i;
			}
		}
	}

	cout << max << "\n";
	cout << y + 1 << " " << x + 1;

	return 0;
}