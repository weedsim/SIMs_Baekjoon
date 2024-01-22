// CRT_SECURE 에 대한 에러를 무시하는 용도이다. 간단한 알고리즘에서는 CRT_SECURE는 필요없기에 무시해도 된다.
#define _CRT_SECURE_NO_WARNINGS
// C++ 의 기본이다.
#include <iostream> 
// 편의를 위해 존재하고 있다.
#include <algorithm>
// 입력용
#include <string>
// 일반적으로 std 를 붙여가면서 할 것을 미리 명시하는 방식으로 편의를 위해 존재한다.
using namespace std;



int main()
{
	// 아래 세 줄은 입력과 출력의 시간을 줄여주기위해 존재한다.
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int A, B;
	cin >> A >> B;

	bool check[100002] = { false, };
	check[0] = true;
	check[1] = true;
	int yak[100002] = { 0, };
	int ans = 0;
	
	for (int i = 2; i <= B; i++) { // 소수는 false 로, 소수가 아니면 true로
		if (!check[i]) {
			for (int j = i * 2; j <= B; j += i) {
				check[j] = true;
				int temp = j;
				while (temp % i == 0) {
					temp /= i;
					yak[j]++;
				}
			}
		}
	}

	for (int i = A; i <= B; i++) {
		if (!check[yak[i]]) {
			ans++;
		}
	}

	cout << ans;

	return 0;
}
