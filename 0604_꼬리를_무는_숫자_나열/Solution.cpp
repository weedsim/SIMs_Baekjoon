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

	int A, B;
	cin >> A >> B;
	int A_X = A / 4;
	int A_Y = A % 4;
	int B_X = B / 4;
	int B_Y = B % 4;

	if (B_Y == 0) {
		B_Y = 4;
		B_X -= 1;
	}

	if (A_Y == 0) {
		A_Y = 4;
		A_X -= 1;
	}

	int X = abs(A_X - B_X);
	int Y = abs(A_Y - B_Y);

	cout << X + Y;


	return 0;
}
