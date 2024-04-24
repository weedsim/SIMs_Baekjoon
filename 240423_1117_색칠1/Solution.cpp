// CRT_SECURE 에 대한 에러를 무시하는 용도이다. 간단한 알고리즘에서는 CRT_SECURE는 필요없기에 무시해도 된다.
#define _CRT_SECURE_NO_WARNINGS
// C++ 의 기본이다.
#include <iostream> 
// 편의를 위해 존재하고 있다.
#include <algorithm>
// 계산용
#include <cmath>
#include <vector>
// 일반적으로 std 를 붙여가면서 할 것을 미리 명시하는 방식으로 편의를 위해 존재한다.
using namespace std;



int main()
{
	// 아래 세 줄은 입력과 출력의 시간을 줄여주기위해 존재한다.
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	unsigned long long W, H, f, c, x1, y1, x2, y2;
	cin >> W >> H >> f >> c >> x1 >> y1 >> x2 >> y2;

	unsigned long long _all = W * H;
	unsigned long long ans = 0;

	ans += (x2 - x1) * (y2 - y1);

	if (f != 0 && f != W) { // 조금이라도 종이가 접히면

		if ((W - f) == f) { // 완벽하게 포개짐
			ans *= 2;
		}
		else if ((W - f) > f) { // 오른쪽 종이가 더 큼
			if (f <= x1) { // 왼쪽 종이가 페인트에 아예 안 묻으면
			
			}
			else if (f >= x2) { // 왼쪽 종이에 범위가 들어가면
				ans *= 2;
			}
			else { // 왼쪽 종이가 일부만 묻으면
				
				ans += ((f - x1) * (y2 - y1));
				
			}

		}
		else { // 왼쪽 종이가 더 큼
			// 왼쪽 종이는 그대로 묻지만, 오른쪽 종이는 일부만 묻는다.
			// x2+f가 W보다 작으면 전부 묻는다.
			if ((x1 + f) >= W) { // 오른쪽 종이에 아예 안 묻으면

			}
			else if ((x2 + f) <= W) {
				ans *= 2;
			}
			else {
				ans += ((W - f - x1) * (y2 - y1));
			}
		}
	}

	ans *= (c + 1);

	cout << (_all - ans);

	return 0;
}
