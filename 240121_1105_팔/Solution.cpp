// CRT_SECURE 에 대한 에러를 무시하는 용도이다. 간단한 알고리즘에서는 CRT_SECURE는 필요없기에 무시해도 된다.
#define _CRT_SECURE_NO_WARNINGS
// C++ 의 기본이다.
#include <iostream> 
// 편의를 위해 존재하고 있다.
#include <algorithm>
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

	string  L, R;

	cin >> L >> R;

	int ans = 0;

	if (L.size() != R.size()) {
		ans = 0;
	}
	else {
		int Size = L.size();

		for (int i = 0; i < Size; i++) {
			if (L[i] == '8' && R[i] == '8') {
				ans++;
			}
			else {
				if (L[i] == R[i]) {
					for (int j = i; j < Size; j++) {
						if (L[j] == R[j]) {
							if (L[j] == '8') {
								ans++;
							}
						}
						else {
							break;
						}
					}
				}
				break;
			}
		}
	}

	cout << ans;

	return 0;
}
