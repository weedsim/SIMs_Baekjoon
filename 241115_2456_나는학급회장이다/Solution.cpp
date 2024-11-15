// CRT_SECURE 에 대한 에러를 무시하는 용도이다. 간단한 알고리즘에서는 CRT_SECURE는 필요없기에 무시해도 된다.
#define _CRT_SECURE_NO_WARNINGS
// C++ 의 기본이다.
#include <iostream> 
// 편의를 위해 존재하고 있다.
#include <algorithm>
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

	int threeCount[3] = { 0, };
	int twoCount[3] = { 0, };
	int fullCount[3] = { 0, };
	int maxSco = 0;
	int candi[2] = { 0, };

	for (int i = 0; i < N; i++) {
		int a, b, c;
		cin >> a >> b >> c;

		fullCount[0] += a;
		fullCount[1] += b;
		fullCount[2] += c;

		if (a == 3) { threeCount[0]++; }
		else if (a == 2) { twoCount[0]++; }
		if (b == 3) { threeCount[1]++; }
		else if (b == 2) { twoCount[1]++; }
		if (c == 3) { threeCount[2]++; }
		else if (c == 2) { twoCount[2]++; }
	}

	for (int i = 0; i < 3; i++) {
		if (maxSco < fullCount[i]) {
			maxSco = fullCount[i];
			candi[0] = i;
			candi[1] = -1;
		}
		else if (maxSco == fullCount[i]) {
			candi[1] = i;
		}
	}

	// 1명
	if (candi[1] == -1) {
		cout << candi[0] + 1 << " " << maxSco;
	}
	else { // 2명이상
		int one = candi[0];
		int two = candi[1];

		if (threeCount[one] > threeCount[two]) {
			cout << one + 1 << " " << maxSco;
		}
		else if (threeCount[one] < threeCount[two]) {
			cout << two + 1 << " " << maxSco;
		}
		else {
			if (twoCount[one] > twoCount[two]) {
				cout << one + 1 << " " << maxSco;
			}
			else if (twoCount[one] < twoCount[two]) {
				cout << two + 1 << " " << maxSco;
			}
			else {
				cout << "0 " << maxSco;
			}
		}
	}

	return 0;
}