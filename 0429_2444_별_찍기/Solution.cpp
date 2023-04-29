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

	// 입력 받기
	int n;
	cin >> n;

	char space = ' ';
	char star = '*';
	// 첫 번째는 1개로 시작하고 가장 두꺼운 부분은 2*n-1 개로 이루어진
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < (n - i); j++) {
			cout << space;
		}
		for (int j = 0; j < ((i * 2) - 1); j++) {
			cout << star;
		}
		cout << space << "\n";
	}
	
	for (int i = n - 1; i >= 1; i--) {
		for (int j = 0; j < (n - i); j++) {
			cout << space;
		}
		for (int j = 0; j < ((i * 2) - 1); j++) {
			cout << star;
		}
		cout << space << "\n";
	}


	return 0;
}