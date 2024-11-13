// CRT_SECURE 에 대한 에러를 무시하는 용도이다. 간단한 알고리즘에서는 CRT_SECURE는 필요없기에 무시해도 된다.
#define _CRT_SECURE_NO_WARNINGS
// C++ 의 기본이다.
#include <iostream> 
#include <algorithm>
// 일반적으로 std 를 붙여가면서 할 것을 미리 명시하는 방식으로 편의를 위해 존재한다.
using namespace std;



int main()

{
	// 아래 세 줄은 입력과 출력의 시간을 줄여주기위해 존재한다.
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	bool ans = true;

	int n;
	cin >> n;

	for (int i = 0; i < 3; i++) {
		bool tem = false;
		for (int j = 0; j < n; j++) {
			int a;
			cin >> a;
			if (a == 7) {
				tem = true;
			}
		}
		if (!tem && ans) { ans = false; }
	}

	if (ans) {
		cout << "777";
	}
	else {
		cout << "0";
	}

	return 0;
}