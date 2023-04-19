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

	// 입력 받는 N은 정수의 갯수를 의미한다.
	int N;
	cin >> N;

	// 배열로 입력을 받는다. 100개를 안 넘기에 100까지로 만들어준다.
	int map[101];

	for (int i = 0; i < N; i++) {
		cin >> map[i];
	}

	// 찾아야 숫자
	int find;
	cin >> find;

	// 카운트
	int cnt = 0;

	// for문으로 찾기
	for (int i = 0; i < N; i++) {
		if (map[i] == find) {
			cnt++;
		}
	}

	cout << cnt;

	return 0;
}