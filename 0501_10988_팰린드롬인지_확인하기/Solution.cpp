// CRT_SECURE 에 대한 에러를 무시하는 용도이다. 간단한 알고리즘에서는 CRT_SECURE는 필요없기에 무시해도 된다.
#define _CRT_SECURE_NO_WARNINGS
// C++ 의 기본이다.
#include <iostream> 
// 이번에는 없어도 되지만 편의를 위해 존재하고 있다.
#include <algorithm>
// 입력 받는 것이 string 이라
#include <string>
// 일반적으로 std 를 붙여가면서 할 것을 미리 명시하는 방식으로 편의를 위해 존재한다.
using namespace std;



int main()
{
	// 아래 세 줄은 입력과 출력의 시간을 줄여주기위해 존재한다.
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string a, b;
	cin >> a;

	// a 를 뒤집을 것이기에 원래의 string 은 b 에 저장
	b = a;

	// a 를 reverse 실행
	reverse(a.begin(), a.end());

	// 뒤집은 것과 원래가 같으면 1로 출력
	if (a == b) {
		cout << "1";
	}
	// 뒤집은 것과 원래가 다르면 0으로 출력
	else {
		cout << "0";
	}

	return 0;
}