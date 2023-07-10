// CRT_SECURE 에 대한 에러를 무시하는 용도이다. 간단한 알고리즘에서는 CRT_SECURE는 필요없기에 무시해도 된다.
#define _CRT_SECURE_NO_WARNINGS
// C++ 의 기본이다.
#include <iostream> 
// 이번에는 없어도 되지만 편의를 위해 존재하고 있다.
#include <algorithm>
// 입력용
#include <string>
// 저장용
#include <map>
// 저장용
#include <vector>
// 일반적으로 std 를 붙여가면서 할 것을 미리 명시하는 방식으로 편의를 위해 존재한다.
using namespace std;



int main()
{
	// 아래 세 줄은 입력과 출력의 시간을 줄여주기위해 존재한다.
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	int GroupNum = 1;

	while (1) {

		cin >> n;
		if (n == 0) { break; }

		// 나쁜말 한명이라도 했는지
		bool _bad = false;

		// 몇번 종이가 누구 꺼인지
		map<int, string> names;

		// 누구 종이에 나쁜말 써져 있는지     일단 모든 인원의 종이가 들어가지만, 나쁜 말이 없으면 vector 가 비게된다.
		map<int, vector<int>> bads;

		for (int i = 0; i < n; i++) {
			// 누가 나쁜 말 썼는지
			vector<int> bad;
			for (int j = 0; j < n; j++) {
				string aa;
				cin >> aa;
				if (j == 0) {
					names[i] = aa;
				}

				// 나쁜 말 쓴 경우
				if (aa == "N") {
					bad.push_back(j);
					_bad = true;
				}

			}

			bads[i] = bad;
			
		}

		cout << "Group ";
		cout << GroupNum;
		cout << "\n";

		// 나쁜 말 아무도 안 썼으면
		if (!_bad) {
			cout << "Nobody was nasty";
			cout << "\n";
		}
		else {
			int _size = bads.size();

			for (int i = 0; i < _size; i++) {

				// 종이에 나쁜 말이 하나라도 써 있으면
				if (bads[i].size() != 0) {
					vector<int> bad;
					int Size;
					// 누가 나쁜 말 썼는지
					bad = bads[i];
					Size = bad.size();
					
					// 여러개가 있으면 왼쪽부터
					for (int j = 0; j < Size; j++) {

						int _who = i - bad[j];
						if (_who < 0) {
							_who += n;
						}

						// 누구인지 확인 완료 -> _who
						cout << names[_who];
						cout << " was nasty about ";
						cout << names[i];
						cout << "\n";

					}

				}

			}
		}

		GroupNum++;
		cout << " \n";
	}



	return 0;
}
