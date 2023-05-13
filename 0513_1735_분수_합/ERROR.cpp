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

	// 소문자 a 는 분자, 소문자 b 는 분모
	int Aa, Ab, Ba, Bb;
	cin >> Aa >> Ab;
	cin >> Ba >> Bb;

	// 분수를 상대의 분모로 곱하여 만들기
	Aa *= Bb;
	Ba *= Ab;
	Ab *= Bb;
	Bb = Ab;

	// 분모는 같아졌으니 분자는 그대로 더하기
	Aa += Ba;

	// 두 분수의 합은 분자가 Aa, 분모가 Ab 이고 약분 시고
	int moreSmall;
	if (Aa < Ab) { moreSmall = Aa; }
	if (Aa >= Ab) { moreSmall = Ab; }
	int moreSame = 1;
	for (int i = 2; i <= moreSmall; i++) {
		if (Aa % i == 0 && Ab % i == 0) {
			moreSame = i;
		}
	}

	cout << Aa / moreSame << " " << Ab / moreSame;

	return 0;
}