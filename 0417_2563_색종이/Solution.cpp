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

	// N은 색종이의 수이다.
	int N;
	cin >> N;

  // map이 도화지이고 0은 흰 배경을 의미한다.
	int map[101][101] = { 0, };

  // cnt는 칠을 할 때 바로 값을 계산해준다.
	int cnt = 0;

	// N 장의 종이 위치를 입력 받는다
	for (int i = 0; i < N; i++) {
		int x, y;
		cin >> x >> y;
    // 
		for (int Y = y; Y < y + 10; Y++) {
			for (int X = x; X < x + 10; X++) {
        // 아직 도화지에 칠이 안되어있으면
				if (map[Y][X] == 0) {
					map[Y][X] = 1;
					cnt++;
				}
			}
		}
	}

	cout << cnt;

	return 0;
}