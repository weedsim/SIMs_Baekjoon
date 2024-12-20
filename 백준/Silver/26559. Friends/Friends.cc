// CRT_SECURE 에 대한 에러를 무시하는 용도이다. 간단한 알고리즘에서는 CRT_SECURE는 필요없기에 무시해도 된다.
#define _CRT_SECURE_NO_WARNINGS
// C++ 의 기본이다.
#include <iostream> 
// 편의를 위해 존재하고 있다.
#include <algorithm>
#include <vector>
// 일반적으로 std 를 붙여가면서 할 것을 미리 명시하는 방식으로 편의를 위해 존재한다.
using namespace std;

struct node {
	string name;
	int num;
};

bool oper(node a, node b) {

	return a.num < b.num;
}

int main()
{
	// 아래 세 줄은 입력과 출력의 시간을 줄여주기위해 존재한다.
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> m;
		vector<node> no;
		for (int j = 0; j < m; j++) {
			string na;
			int nu;
			cin >> na >> nu;
			node temp;
			temp.name = na;
			temp.num = nu;
			no.push_back(temp);
		}
		sort(no.begin(), no.end(), oper);
		for (int j = 0; j < m; j++) {
			cout << no.back().name;
			no.pop_back();
			if (!no.empty()) {
				cout << ", ";
			}
			else {
				cout << endl;
			}
		}
	}

	return 0;
}