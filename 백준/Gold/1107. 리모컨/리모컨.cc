// CRT_SECURE 에 대한 에러를 무시하는 용도이다. 간단한 알고리즘에서는 CRT_SECURE는 필요없기에 무시해도 된다.
#define _CRT_SECURE_NO_WARNINGS
// C++ 의 기본이다.
#include <iostream> 
// 편의를 위해 존재하고 있다.
#include <algorithm>
// 계산용
#include <cmath>
#include <vector>
// 일반적으로 std 를 붙여가면서 할 것을 미리 명시하는 방식으로 편의를 위해 존재한다.
using namespace std;

bool broken[10] = { false, };

bool isUsable(int num) {
	if (num == 0) return !broken[0];
	while (num > 0) {
		if (broken[num % 10]) return false;
		num /= 10;
	}
	return true;
}

int countPress(int num) {
	if (num == 0) return 1;
	int len = 0;
	while (num > 0) {
		len++;
		num /= 10;
	}
	return len;
}

int main()
{
	// 아래 세 줄은 입력과 출력의 시간을 줄여주기위해 존재한다.
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	int M;
	cin >> N;
	cin >> M;
	for (int i = 0; i < M; i++) {
		int temp;
		cin >> temp;
		broken[temp] = true;
	}

	if (N == 100) { cout << 0; return 0; }

	int ans = abs(N - 100);

	for (int i = 0; i < 1000000; i++) {
		
		if (isUsable(i)) {
			int pressCnt = countPress(i) + abs(N - i);
			ans = min(ans, pressCnt);
		}

	}

	cout << ans;

	return 0;
}
