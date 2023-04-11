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

	//숫자 3개를 A, B, C 순으로 받아서 설정한다. int로 하기에는 int의 제한은 –2,147,483,648 ~ 2,147,483,647 로 매우 부족하기에 long long으로 범위를 매우 크게 늘려서 사용하였다.
	long long A, B, C;
	cin >> A >> B >> C;

  // 받아든 3개의 수를 그대로 더해서 출력하였다. 다른 방식으로는 long long ans = A + B + C; cout << and; 도 가능하다.
	cout << A + B + C;

	return 0;
}