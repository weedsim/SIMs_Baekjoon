// CRT_SECURE 에 대한 에러를 무시하는 용도이다. 간단한 알고리즘에서는 CRT_SECURE는 필요없기에 무시해도 된다.
#define _CRT_SECURE_NO_WARNINGS
// C++ 의 기본이다.
#include <iostream> 
// 편의를 위해 존재하고 있다.
#include <algorithm>
// 계산용
#include <cmath>
// 일반적으로 std 를 붙여가면서 할 것을 미리 명시하는 방식으로 편의를 위해 존재한다.
using namespace std;

bool check(int num) {
	int slice = sqrt(num);
	return num == (slice * slice);
}

int main()
{
	// 아래 세 줄은 입력과 출력의 시간을 줄여주기위해 존재한다.
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	int map[10][10] = { 0, };
	int ans = -1;

	for (int j = 0; j < N; j++) {
		int temp;
		cin >> temp;
		for (int i = M - 1; i >= 0 ; i--) {
			int tmp = temp % 10;
			temp /= 10;
			map[j][i] = tmp;
			if (check(tmp) && ans < tmp) { // 한 자리 완전제곱수가 있으면
				ans = tmp;
			}
		}
	}

	for (int startY = 0; startY < N; startY++) {
		for (int startX = 0; startX < M; startX++) {
			for (int Y = -N; Y <= N; Y++) {
				for (int X = -M; X <= M; X++) {
					if (X == 0 && Y == 0) { continue; }

					int num = 0;
					int x = startX;
					int y = startY;

					while (x >= 0 && x < M && y >= 0 && y < N) {
						num *= 10;
						num += map[y][x];
						if (check(num) && ans < num) {
							ans = num;
						}

						y += Y;
						x += X;
					
					}

				}
			}
		}
	}

	cout << ans;


	return 0;
}
