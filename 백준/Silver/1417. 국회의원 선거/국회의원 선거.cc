// CRT_SECURE 에 대한 에러를 무시하는 용도이다. 간단한 알고리즘에서는 CRT_SECURE는 필요없기에 무시해도 된다.
#define _CRT_SECURE_NO_WARNINGS
// C++ 의 기본이다.
#include <iostream> 
// 이번에는 없어도 되지만 편의를 위해 존재하고 있다.
#include <algorithm>
// 저장용
#include <vector>
// 일반적으로 std 를 붙여가면서 할 것을 미리 명시하는 방식으로 편의를 위해 존재한다.
using namespace std;

int N;
int _max = 0;
int maxWho;
int cnt = 0;
vector<int> tab;

void check() {
	for (int i = 1; i < N; i++) {
		if (_max <= tab[i]) {
			_max = tab[i];
			maxWho = i;
		}
	}
}

int main()
{
	// 아래 세 줄은 입력과 출력의 시간을 줄여주기위해 존재한다.
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;
		tab.push_back(n);
		if (_max <= n) { 
			_max = n; 
			maxWho = i;
		}
	}

	while (maxWho != 0) {
		tab[0]++;
		tab[maxWho]--;
		_max = tab[0];
		maxWho = 0;
		check();
		cnt++;
	}

	cout << cnt;

	return 0;
}
