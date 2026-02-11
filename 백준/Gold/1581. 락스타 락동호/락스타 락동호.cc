// CRT_SECURE 에 대한 에러를 무시하는 용도이다. 간단한 알고리즘에서는 CRT_SECURE는 필요없기에 무시해도 된다.
#define _CRT_SECURE_NO_WARNINGS
// C++ 의 기본이다.
#include <iostream>
// 일반적으로 std 를 붙여가면서 할 것을 미리 명시하는 방식으로 편의를 위해 존재한다.
using namespace std;


int main()
{
	// 아래 세 줄은 입력과 출력의 시간을 줄여주기위해 존재한다.
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int FF, FS, SF, SS;
	cin >> FF >> FS >> SF >> SS;
	int ans = 0;

	if (FF == 0 && FS == 0) {
		ans += SS;
		if (SF > 0) {
			ans++;
		}
	}
	else {
		ans += FF;
		if (FS > SF) {
			ans += ((2 * SF) + 1);
			ans += SS;
		}
		else if (FS != 0) {
			ans += ((2 * FS) - 1);
			ans += (1 + SS);
		}
	}

	cout << ans;

	return 0;
}