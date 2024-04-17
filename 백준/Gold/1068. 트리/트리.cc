// CRT_SECURE 에 대한 에러를 무시하는 용도이다. 간단한 알고리즘에서는 CRT_SECURE는 필요없기에 무시해도 된다.
#define _CRT_SECURE_NO_WARNINGS
// C++ 의 기본이다.
#include <iostream> 
// 편의를 위해 존재하고 있다.
#include <algorithm>
// 입력용
#include <vector>
// 선입선출용
#include <queue>
// 일반적으로 std 를 붙여가면서 할 것을 미리 명시하는 방식으로 편의를 위해 존재한다.
using namespace std;



int main()
{
	// 아래 세 줄은 입력과 출력의 시간을 줄여주기위해 존재한다.
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	vector<int> map;
	int del;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		map.push_back(temp);
	}
	cin >> del;
	
	// 삭제된 노드와 그 노드에 연결된 하위 노드들은 전부 55로 전환
	map[del] = 55;
	queue<int> dels;
	dels.push(del);

	while (!dels.empty()) {
		int nowDel = dels.front();
		dels.pop();
		for (int i = 0; i < N; i++) {
			if (map[i] == nowDel) {
				map[i] = 55;
				dels.push(i);
			}
		}
	}

	int cnt = 0; // 마지막 노드부터 찾아가면서 해당 번호 노드의 하위가 있는지 확인, 없으면 리프 노드임을 확인한 것이다.
	for (int i = N - 1; i >= 0; i--) {
		if (map[i] == 55) { continue; }
		if (find(map.begin(), map.end(), i) == map.end()) {
			cnt++;
		}
	}

	cout << cnt;

	return 0;
}
