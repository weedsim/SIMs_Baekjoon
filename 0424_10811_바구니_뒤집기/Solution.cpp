// CRT_SECURE 에 대한 에러를 무시하는 용도이다. 간단한 알고리즘에서는 CRT_SECURE는 필요없기에 무시해도 된다.
#define _CRT_SECURE_NO_WARNINGS
// C++ 의 기본이다.
#include <iostream> 
// 이번에는 없어도 되지만 편의를 위해 존재하고 있다.
#include <algorithm>
// 일반적으로 std 를 붙여가면서 할 것을 미리 명시하는 방식으로 편의를 위해 존재한다.
using namespace std;



int main()
{
	// 아래 세 줄은 입력과 출력의 시간을 줄여주기위해 존재한다.
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// N개의 바구니와 M개 줄을 입력 받는다.
	int N, M;
	cin >> N >> M;

    // 바구니이다.
	int bucket[101] = { 0, };

    // 1번 바구니는 1번 , n번 바구니는 n번으로 지정
	for (int i = 1; i <= N; i++) {
		bucket[i] = i;
	}

    // 입력 받은 두 수를 확인해서 두 수의 합이나 차가 짝수인 경우와 홀수인 경우 두 가지로 나눈다.
	for (int t = 0; t < M; t++) {
		int i, j;
		cin >> i >> j;
		if ((i + j) % 2 == 1) { // 홀수 일 경우
			for (int k = 0; k <= (j - i) / 2; k++) {
				int temp;
				temp = bucket[i + k];
				bucket[i + k] = bucket[j - k];
				bucket[j - k] = temp;
			}
		}
		else { // 짝수 일 경우
			for (int k = 0; k < (j - i) / 2; k++) {
				int temp;
				temp = bucket[i + k];
				bucket[i + k] = bucket[j - k];
				bucket[j - k] = temp;
			}
		}
	}

	// 끝났으니 출력
	for (int i = 1; i <= N; i++) {
		cout << bucket[i] << " ";
	}


	return 0;
}