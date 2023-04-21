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

	// M은 몇 줄을 입력 받을지 알려준다. N은 바구니의 갯수이다.
	int N, M;
	cin >> N >> M;

	// 바구니에 공이 없기에 0으로 초기화
	int bucket[101] = { 0, };
	
	// 한 줄씩 3개의 숫자(i, j, k)를 입력 받아서 i부터 j까지의 bucket에 k를 입력
	for (int t = 0; t < M; t++) {
		int i, j, k;
		cin >> i >> j >> k;
		for (int num = i; num <= j; num++) {
			bucket[num] = k;
		}
	}

	// 모든 바구니 출력
	for (int i = 1; i <= N; i++) {
		cout << bucket[i] << " ";
	}

	return 0;
}
