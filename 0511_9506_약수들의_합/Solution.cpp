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

bool cmp(int a, int b) {
	return a > b;
}

int main()
{
	// 아래 세 줄은 입력과 출력의 시간을 줄여주기위해 존재한다.
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	while (N != -1) {
		// 약수들의 합
		int ful = 0;
		vector<int> in;
		for (int i = 1; i < N; i++) {
			if (N % i == 0) {
				ful += i;
				in.push_back(i);
			}
		}

		sort(in.begin(), in.end(), cmp);

		cout << N;
		if (ful == N) {
			cout << " = ";
			while (!in.empty()) {
				cout << in.back();
				in.pop_back();
				if (!in.empty()) { cout << " + "; }
			}
		}
		else {
			cout << " is NOT perfect.";
		}

		cout << "\n";
		cin >> N;
	}

	return 0;
}