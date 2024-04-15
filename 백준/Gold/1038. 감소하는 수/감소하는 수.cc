// CRT_SECURE 에 대한 에러를 무시하는 용도이다. 간단한 알고리즘에서는 CRT_SECURE는 필요없기에 무시해도 된다.
#define _CRT_SECURE_NO_WARNINGS
// C++ 의 기본이다.
#include <iostream> 
// 편의를 위해 존재하고 있다.
#include <algorithm>
// 임시 저장 용도
#include <queue>
#include <string>
// 일반적으로 std 를 붙여가면서 할 것을 미리 명시하는 방식으로 편의를 위해 존재한다.
using namespace std;



int main()
{
	// 아래 세 줄은 입력과 출력의 시간을 줄여주기위해 존재한다.
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	if (N < 10) { cout << N; return 0; }

	int digit = 0;
	int cnt = -1;

	queue<long long> q;

	for (int i = 0; i < 10; i++) {
		q.push(i);
		cnt++;
	}

	while (!q.empty()) {

		long long temp = q.front();
		q.pop();
		
		int last = stoll(to_string(temp)) % 10;

		for (int i = 0; i < last; i++) {
			string t = to_string(temp) + to_string(i);
			q.push(stoll(t));
			cnt++;
			if (cnt == N) { cout << t; return 0; }
		}

	}

	cout << -1;

	return 0;
}
