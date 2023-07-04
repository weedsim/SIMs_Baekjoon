// CRT_SECURE 에 대한 에러를 무시하는 용도이다. 간단한 알고리즘에서는 CRT_SECURE는 필요없기에 무시해도 된다.
#define _CRT_SECURE_NO_WARNINGS
// C++ 의 기본이다.
#include <iostream> 
// 이번에는 없어도 되지만 편의를 위해 존재하고 있다.
#include <algorithm>
// 입력용
#include <string>
// 저장용
#include <vector>
// 
#include <map>
// 일반적으로 std 를 붙여가면서 할 것을 미리 명시하는 방식으로 편의를 위해 존재한다.
using namespace std;



int main()
{
	// 아래 세 줄은 입력과 출력의 시간을 줄여주기위해 존재한다.
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T = 0;

	while (1) {
		T++;
		int N;
		cin >> N;
		if (N == 0) { break; }

		// 이름 저장
		map<int, string> names;
		map<int, bool> check;

		for (int i = 0; i <= N; i++) {

			string name;

			getline(cin, name);

			names[i] = name;
		}

		// 2N-1 줄 입력받기
		for (int i = 0; i < ((2 * N) - 1); i++) {
			int t;
			char n;
			cin >> t;
			cin >> n;
			// 처음 입력 받은 경우
			if (check.find(t) == check.end()) {
				// 압수되었다.
				check[t] = true;
			}
			else {
				check[t] = false;
			}
		}

		cout << T;
		cout << " ";

		for (int i = 1; i <= N; i++) {
			if (check[i]) { cout << names[i]; }
		}

		cout << "\n";

	}

	return 0;
}
