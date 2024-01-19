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

	int N, M;
	cin >> N >> M;

	int map1[51][51] = { 0, };
	int map2[51][51] = { 0, };
	int cnt = -1;

	for (int y = 0; y < N; y++) {
		string temp;
		cin >> temp;
		for (int x = 0; x < M; x++) {
			map1[y][x] = (temp[x] - '0');
		}
	}

	for (int y = 0; y < N; y++) {
		string temp;
		cin >> temp;
		for (int x = 0; x < M; x++) {
			map2[y][x] = (temp[x] - '0');
		}
	}

	if (N < 3 || M < 3) {

		cnt = 0;

	}
	else {
		cnt = 0;
		for (int i = 0; i < (N - 2); i++) {
			for (int j = 0; j < (M - 2); j++) {

				if (map1[i][j] != map2[i][j]) {
					cnt++;
					for (int a = i; a < i + 3; a++) {
						for (int b = j; b < j + 3; b++) {

							map1[a][b] = 1 - map1[a][b];

						}
					}
				}

			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map1[i][j] != map2[i][j] && cnt != -1) {
				cout << "-1";
				return 0;
			}
		}
	}

	cout << cnt;

	return 0;
}
