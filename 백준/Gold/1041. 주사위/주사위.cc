// CRT_SECURE 에 대한 에러를 무시하는 용도이다. 간단한 알고리즘에서는 CRT_SECURE는 필요없기에 무시해도 된다.
#define _CRT_SECURE_NO_WARNINGS
// C++ 의 기본이다.
#include <iostream> 
// 편의를 위해 존재하고 있다.
#include <algorithm>
// 계산용
#include <cmath>
// 일반적으로 std 를 붙여가면서 할 것을 미리 명시하는 방식으로 편의를 위해 존재한다.
using namespace std;



int main()
{
	// 아래 세 줄은 입력과 출력의 시간을 줄여주기위해 존재한다.
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	int dice[6];
	cin >> N;
	
	long long ans = 0;

	// 한 면만 보이는 경우 6면 중 가장 작은 값을 찾으면 된다.
	int minInDice = 51;
	int maxInDice = 0;
	int maxIndex;

	for (int i = 0; i < 6; i++) { // a는 인덱스가 0 , b는 인덱스가 1 , c는 인덱스가 2 , d는 인덱스가 3 , e는 인덱스가 4 , f는 인덱스가 5
		cin >> dice[i];
		if (dice[i] < minInDice) {
			minInDice = dice[i];
		}

		if (maxInDice < dice[i]) {
			maxIndex = i;
			maxInDice = dice[i];
		}
	}

	if (N > 1) {

		// 두 면이 보이는 경우 두 개씩 조합인 (a, b), (a, c), (a, d), (a, e), (b, c), (b, d), (b, f), (c, e), (c, f), (d, e), (d, f), (e, f)
		// 조합이 총 12개로 구성이 된다.
		int dualInDice[12];
		int minInDual = 101;

		dualInDice[0] = dice[0] + dice[1];
		dualInDice[1] = dice[0] + dice[2];
		dualInDice[2] = dice[0] + dice[3];
		dualInDice[3] = dice[0] + dice[4];
		dualInDice[4] = dice[1] + dice[2];
		dualInDice[5] = dice[1] + dice[3];
		dualInDice[6] = dice[1] + dice[5];
		dualInDice[7] = dice[2] + dice[4];
		dualInDice[8] = dice[2] + dice[5];
		dualInDice[9] = dice[3] + dice[4];
		dualInDice[10] = dice[3] + dice[5];
		dualInDice[11] = dice[4] + dice[5];

		for (int i = 0; i < 12; i++) {
			if (minInDual > dualInDice[i]) {
				minInDual = dualInDice[i];
			}
		}

		// 세면이 보이는 경우 세개씩 조합인 (a, b, c), (a, b, d), (a, c, e), (a, d, e), (b, c, f), (b, d, f), (c, e, f), (d, e, f)
		// 조합이 총 8개로 구성이 된다.
		int triInDice[8];
		int minInTri = 151;

		triInDice[0] = dice[0] + dice[1] + dice[2];
		triInDice[1] = dice[0] + dice[1] + dice[3];
		triInDice[2] = dice[0] + dice[2] + dice[4];
		triInDice[3] = dice[0] + dice[3] + dice[4];
		triInDice[4] = dice[1] + dice[2] + dice[5];
		triInDice[5] = dice[1] + dice[3] + dice[5];
		triInDice[6] = dice[2] + dice[4] + dice[5];
		triInDice[7] = dice[3] + dice[4] + dice[5];

		for (int i = 0; i < 8; i++) {
			if (minInTri > triInDice[i]) {
				minInTri = triInDice[i];
			}
		}

		ans += (5 * minInDice * pow((N - 2), 2));
		ans += (minInTri * 4);
		ans += (minInDual * 4 * (N - 2));
		ans += (minInDual * 4 * (N - 1));
		ans += (minInDice * 4 * (N - 2));

	}
	else {
		for (int i = 0; i < 6; i++) {
			if (maxIndex != i) {
				ans += dice[i];
			}
		}
	}
	
	cout << ans;

	return 0;
}
