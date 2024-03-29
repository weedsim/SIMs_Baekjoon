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
	
	int home[1001][3] = { 0, };
	int temp[3];

	for (int i = 1; i <= N; i++) {
		cin >> temp[0];
		cin >> temp[1];
		cin >> temp[2];
		home[i][0] = min(home[i - 1][1], home[i - 1][2]) + temp[0];
		home[i][1] = min(home[i - 1][0], home[i - 1][2]) + temp[1];
		home[i][2] = min(home[i - 1][0], home[i - 1][1]) + temp[2];
	}

	cout << min(home[N][0], min(home[N][1], home[N][2]));

	return 0;
}
