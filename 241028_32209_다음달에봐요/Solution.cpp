// CRT_SECURE 에 대한 에러를 무시하는 용도이다. 간단한 알고리즘에서는 CRT_SECURE는 필요없기에 무시해도 된다.
#define _CRT_SECURE_NO_WARNINGS
// C++ 의 기본이다.
#include <iostream> 
// 편의를 위해 존재하고 있다.
#include <algorithm>
#include <cstdlib>
#include <cmath>
// 임시 저장용도
#include <vector>
// 일반적으로 std 를 붙여가면서 할 것을 미리 명시하는 방식으로 편의를 위해 존재한다.
using namespace std;



int main()
{
	// 아래 세 줄은 입력과 출력의 시간을 줄여주기위해 존재한다.
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int Q;
	int x = 0;
	int y = 0;

    // 몇번 입력 받을지
	cin >> Q;

	for (int i = 0; i < Q; i++) {
		int t;
		cin >> t;
		int y;
		cin >> y;
		if (t == 1) {
            // 출제할 문제 추가
			x += y;
		}
		else {
			if (y > x) { // 남아있는 문제가 향유회에 필요한 문제보다 적으면
				cout << "Adios";
				return 0;
			}
			else { // 문제가 충분하면
				x -= y;
			}
		}
	}

	cout << "See you next month";

	return 0;
}