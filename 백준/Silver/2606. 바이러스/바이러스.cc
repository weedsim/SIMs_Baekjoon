// CRT_SECURE 에 대한 에러를 무시하는 용도이다. 간단한 알고리즘에서는 CRT_SECURE는 필요없기에 무시해도 된다.
#define _CRT_SECURE_NO_WARNINGS
// C++ 의 기본이다.
#include <iostream> 
#include <queue>
// 일반적으로 std 를 붙여가면서 할 것을 미리 명시하는 방식으로 편의를 위해 존재한다.
using namespace std;

int cnt, net;
int cont = 0;
int com[101][101];
bool used[101] = { 0, };
queue<int> q;

void bfs(int c) {
	q.push(c);
	used[c] = true;

	while (!q.empty()) {
		c = q.front();
		q.pop();

		for (int i = 1; i <= cnt; i++) {
			if (used[i] == 0 && com[c][i]) {
				q.push(i);
				used[i] = true;
				cont++;
			}
		}
	}
}

int main()
{
	// 아래 세 줄은 입력과 출력의 시간을 줄여주기위해 존재한다.
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> cnt >> net;

	for (int i = 0; i < net; i++) {
		int a, b;
		cin >> a >> b;
		com[a][b] = 1;
		com[b][a] = 1;
	}

	bfs(1);

	cout << cont;

	return 0;
}