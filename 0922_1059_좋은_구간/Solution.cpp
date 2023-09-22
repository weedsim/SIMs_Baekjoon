// CRT_SECURE 에 대한 에러를 무시하는 용도이다. 간단한 알고리즘에서는 CRT_SECURE는 필요없기에 무시해도 된다.
#define _CRT_SECURE_NO_WARNINGS
// C++ 의 기본이다.
#include <iostream> 
// 이번에는 없어도 되지만 편의를 위해 존재하고 있다.
#include <algorithm>
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

	int L;
	cin >> L;
	vector<int> S;
	for (int i = 0; i < L; i++) {
		int t;
		cin >> t;
		S.push_back(t);
	}

	sort(S.begin(), S.end());
	int n;
	cin >> n;

	int A, B;
	A = 0;
	B = 0;

	bool err = false;

	for (int i = 0; i < L; i++) {
		if (S[i] == n) { err = true; break; }
		if (S[i] > n) {
			if (i < 1) { A = 1; B = S[i] - 1; break; }
			A = S[i - 1] + 1;
			B = S[i] - 1;
			break;
		}
	}

	if (A > n) {
		err = true;
	}

	if (!err) {
		int left;
		int right;
		left = A;
		right = B;
		int cnt = 0;

		for (int a = A; a < B; a++) {
			for (int b = a + 1; b <= B; b++) {
				if (a <= n && n <= b) {
					if (a < b) {
						cnt++;
					}
				}
			}
		}

		cout << cnt;

	}
	else {
		cout << 0;
	}


	return 0;
}
