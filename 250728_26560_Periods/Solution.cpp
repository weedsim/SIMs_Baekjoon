// CRT_SECURE 에 대한 에러를 무시하는 용도이다. 간단한 알고리즘에서는 CRT_SECURE는 필요없기에 무시해도 된다.
#define _CRT_SECURE_NO_WARNINGS
// C++ 의 기본이다.
#include <iostream> 
// 입력용
#include <string>
// 일반적으로 std 를 붙여가면서 할 것을 미리 명시하는 방식으로 편의를 위해 존재한다.
using namespace std;



int main()
{
	// 아래 세 줄은 입력과 출력의 시간을 줄여주기위해 존재한다.
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	while (1)
	{
		string a, b;
		cin >> a >> b;
		if (a == "0" && b == "0") { break; }

		string c, d;
		int cnt_a, cnt_b;
		cnt_a = a.size();
		cnt_b = b.size();

		int ans = 0;

		if (cnt_a == cnt_b) {
			int temp = 0;
			for (int i = cnt_a; i > 0; i--) {
				if ((a[i - 1] - '0') + (b[i - 1] - '0') + temp > 9) {
					ans++;
					temp = 1;
				}
				else {
					temp = 0;
				}
			}

		}
		else {
			if (cnt_a > cnt_b) {
				d = "";
				for (int i = 0; i < (cnt_a - cnt_b); i++) {
					d += "0";
				}
				d += b;
				c = a;

				int temp = 0;
				for (int i = cnt_a; i > 0; i--) {
					if ((c[i - 1] - '0') + (d[i - 1] - '0') + temp > 9) {
						ans++;
						temp = 1;
					}
					else {
						temp = 0;
					}
				}
			}
			else {
				c = "";
				for (int i = 0; i < (cnt_b - cnt_a); i++) {
					c += "0";
				}
				c += a;
				d = b;

				int temp = 0;
				for (int i = cnt_b; i > 0; i--) {
					if ((c[i - 1] - '0') + (d[i - 1] - '0') + temp > 9) {
						ans++;
						temp = 1;
					}
					else {
						temp = 0;
					}
				}
			}
		}

		cout << ans << "\n";
	}

	return 0;
}