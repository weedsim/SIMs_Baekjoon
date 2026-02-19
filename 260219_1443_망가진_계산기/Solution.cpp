// CRT_SECURE 에 대한 에러를 무시하는 용도이다. 간단한 알고리즘에서는 CRT_SECURE는 필요없기에 무시해도 된다.
#define _CRT_SECURE_NO_WARNINGS
// C++ 의 기본이다.
#include <iostream>
// 제곱 계산용
#include <cmath>
// 일반적으로 std 를 붙여가면서 할 것을 미리 명시하는 방식으로 편의를 위해 존재한다.
using namespace std;

int cnt = 0;
long long ans = 1;
bool success = false;
int P;

void DFS(long long base) {
	if (base == 1) {
		success = true;
		return;
	}

	if (success) {
		return;
	}

	if (cnt >= P) {
		return;
	}

	cnt++;

	for (int i = 9; i > 1; i--) {
		if (base % i == 0) {
			DFS(base / i);
		}

		if (success) {
			return;
		}
	}

	cnt--;

}

int main()
{
	// 아래 세 줄은 입력과 출력의 시간을 줄여주기위해 존재한다.
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int D;
	cin >> D >> P;

	if (P == 0) {
		cout << 1;
		return 0;
	}

	ans = pow(10, D);

	if (P < 19) {
		long long tmp = pow(9, P);

		if (tmp < ans) {
			cout << tmp;
			return 0;
		}
	}

	long long minTmp = pow(2, P);

	if (minTmp > ans) {
		cout << -1;
		return 0;
	}

	for (long long i = 0; i < ans; i++) {
		ans--;
		DFS(ans);

		if (success) {
			cout << ans;
			return 0;
		}
	}

	cout << -1;

	return 0;
}