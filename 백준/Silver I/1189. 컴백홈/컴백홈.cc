// CRT_SECURE 에 대한 에러를 무시하는 용도이다. 간단한 알고리즘에서는 CRT_SECURE는 필요없기에 무시해도 된다.
#define _CRT_SECURE_NO_WARNINGS
// C++ 의 기본이다.
#include <iostream> 
// 편의를 위해 존재하고 있다.
#include <algorithm>
// 입력용
#include <string>
#include <queue>
#include <vector>
// 일반적으로 std 를 붙여가면서 할 것을 미리 명시하는 방식으로 편의를 위해 존재한다.
using namespace std;

struct node {
	int row, col, dis;
	vector<vector<bool>> used;
};

int main()
{
	// 아래 세 줄은 입력과 출력의 시간을 줄여주기위해 존재한다.
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int R, C, K;
	cin >> R >> C >> K;

	bool map[6][6] = { 0, };
	bool used[6][6] = { 0, };

	for (int y = 0; y < R; y++) {
		string temp;
		cin >> temp;
		for (int x = 0; x < C; x++) {
			if (temp[x] == '.') {
				map[y][x] = false;
			}
			else if (temp[x] == 'T') {
				map[y][x] = true;
			}
			else {
				cout << "ERROR";
				return 0;
			}
		}
	}

	queue<node> q;

	vector<vector<bool>> usedTemp(6, vector<bool>(6, 0));
	usedTemp[R - 1][0] = 1;

	q.push({ R - 1, 0, 1, usedTemp});

	int ans = 0;

	while (!q.empty()) {

		node now = q.front();
		q.pop();
		vector<vector<bool>> usedTemp1(6, vector<bool>(6, 0));
		usedTemp1 = now.used;

		if (now.row == 0 && now.col == C - 1 && now.dis == K) {
			ans++;
		}

		if (now.dis >= K) { continue; }

		// 왼쪽 
		if (now.col > 0 && now.used[now.row][now.col - 1] == false && map[now.row][now.col - 1] == false) {
			usedTemp1 = now.used;
			usedTemp1[now.row][now.col - 1] = true;
			q.push({ now.row, now.col - 1, now.dis + 1, usedTemp1 });
		}
		// 오른쪽
		if (now.col < C - 1 && now.used[now.row][now.col + 1] == false && map[now.row][now.col + 1] == false) {
			usedTemp1 = now.used;
			usedTemp1[now.row][now.col + 1] = true;
			q.push({ now.row, now.col + 1, now.dis + 1, usedTemp1 });
		}
		// 위 
		if (now.row > 0 && now.used[now.row - 1][now.col] == false && map[now.row - 1][now.col] == false) {
			usedTemp1 = now.used;
			usedTemp1[now.row - 1][now.col] = true;
			q.push({ now.row - 1, now.col, now.dis + 1, usedTemp1 });
		}
		// 아래
		if (now.row < R - 1 && now.used[now.row + 1][now.col] == false && map[now.row + 1][now.col] == false) {
			usedTemp1 = now.used;
			usedTemp1[now.row + 1][now.col] = true;
			q.push({ now.row + 1, now.col, now.dis + 1, usedTemp1 });
		}

	}

	cout << ans;

	return 0;
}
