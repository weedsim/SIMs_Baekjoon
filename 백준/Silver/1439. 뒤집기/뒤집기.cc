// CRT_SECURE 에 대한 에러를 무시하는 용도이다. 간단한 알고리즘에서는 CRT_SECURE는 필요없기에 무시해도 된다.
#define _CRT_SECURE_NO_WARNINGS
// C++ 의 기본이다.
#include <iostream> 
// 이번에는 없어도 되지만 편의를 위해 존재하고 있다.
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

	string S;
	cin >> S;

	int cnt1 = 0;
	int cnt0 = 0;
	int Size = S.size();
	char temp = S[0];

	if (temp == '0') {
		cnt0++;
	}
	else {
		cnt1++;
	}

	for (int i = 1; i < Size; i++) {
		
		if (S[i] != temp) {
			if (S[i] == '0') {
				cnt0++;
			}
			else {
				cnt1++;
			}
			temp = S[i];
		}
	}

	cout << min(cnt1, cnt0);

	return 0;
}
