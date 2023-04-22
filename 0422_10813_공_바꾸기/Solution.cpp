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

	// 바구니이다.
	int bucket[101];
	// N과 M을 입력 받는다. 바구니가 N개이다.
	int N, M;
	cin >> N >> M;

	// 바구니를 1번 부터 N번까지 초기화 조치
	for (int i = 1; i <= N; i++) {
		bucket[i] = i;
	}

	// M개의 줄을 입력 받는다
	for (int t = 0; t < M; t++) {
		// i와 j로 입력 받는다
		int i, j;
		int temp;
		cin >> i >> j;
		// i번 바구니는 temp에 임시로 빼두고
		temp = bucket[i];
		// i바구니에 j바구니에 있던 공을 넣고
		bucket[i] = bucket[j];
		// 아까 임시로 빼둔 temp를 j번 바구니에 넣기
		bucket[j] = temp;
	}

	// 모든 바구니 출력
	for (int i = 1; i <= N; i++) {
		cout << bucket[i] << " ";
	}

	return 0;
}