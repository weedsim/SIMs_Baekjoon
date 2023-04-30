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

    // 입력
	int N, M;
	cin >> N >> M;

    // 실 바구니
	int map[101] = { 0, };

    // 기준점의 앞쪽에 있는 바구니 들을 임시로 담을 곳
	int temp[101] = { 0, };

    // 바구니 초기화
	for (int i = 1; i <= N; i++) {
		map[i] = i;
	}

	for (int t = 0; t < M; t++) {
		int i, j, k;
		cin >> i >> j >> k;

        // 기준 점의 앞 쪽에 있는 바구니 들 임시로 두기
		for (int p = i; p < k; p++) {
			temp[p - i] = map[p];
		}

        // 기준점 포함 뒤쪽에 있는 바구니들 앞으로 당겨오기
		for (int p = k; p <= j; p++) {
			map[i + p - k] = map[p];
		}

        // 임시로 빼둔 바구니들 뒤쪽으로 이동
		for (int p = (i + (j - k) + 1); p <= j; p++) {
			map[p] = temp[p - (i + (j - k) + 1)];
		}
	}

    // 출력
	for (int i = 1; i <= N; i++) {
		cout << map[i] << " ";
	}

	return 0;
}