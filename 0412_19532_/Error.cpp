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

	// 최상단 각각 A, B, C, D, E, F순으로 입력 받는다.
	int A, B, C, D, E, F;
	cin >> A >> B >> C >> D >> E >> F;

	// (A 와 D) , (B 와 E) 중 하나의 묶음이 같은 값이 되게 만들어서 A-D, B-E, C-F 를 해서 x나 y의 값을 찾은 뒤, 대입하여 반대값을 계산한다.
	// 나는 A와 D를 같은 값으로 만들기 위해 A행에는 D를 곱하고, D행에는 A를 곱하는 방식을 이용할 것이다.
	// 제한 조건으로 해가 무한이거나 없는 경우를 배제하여 만들었다고 되어있으니 if문은 필요없게 된 상황이다.
	// 그냥 계산하면 이후에 다시 A 값을 찾아봐도 이미 계산된 값으로 나오기에 따로 추가 저장을 해두는 방식을 쓴 것이다.
	int a = A;
	// 그냥 계산하면 이후에 다시 A 값을 찾아봐도 이미 계산된 값으로 나오기에 따로 추가 저장을 해두는 방식을 쓴 것이다.
	int d = D;

	int b = B;
	int c = C;
	int e = E;
	int f = F;

	A *= d;
	B *= d;
	C *= d;
	D *= a;
	E *= a;
	F *= a;

	int y;
	y = (C - F) / (B - E);
	
	int x;

	x =	(c - (b * y)) / a;
	
	cout << x << " " << y;

	return 0;
}