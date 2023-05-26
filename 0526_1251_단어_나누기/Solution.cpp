// CRT_SECURE 에 대한 에러를 무시하는 용도이다. 간단한 알고리즘에서는 CRT_SECURE는 필요없기에 무시해도 된다.
#define _CRT_SECURE_NO_WARNINGS
// C++ 의 기본이다.
#include <iostream> 
// 이번에는 없어도 되지만 편의를 위해 존재하고 있다.
#include <algorithm>
// 입력을 위해 사용
#include <string>
// 일반적으로 std 를 붙여가면서 할 것을 미리 명시하는 방식으로 편의를 위해 존재한다.
using namespace std;

int _first, _second;
char _check = (char)127;
int _size;

string Check(string s, int First, int Second) {
	First++;
	Second++;
	reverse(s.begin(), s.begin() + First);
	reverse(s.begin() + First, s.begin() + Second);
	reverse(s.begin() + Second, s.end());
	return s;
}

int main()
{
	// 아래 세 줄은 입력과 출력의 시간을 줄여주기위해 존재한다.
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string _word;
	cin >> _word;

	_size = _word.size();
	string ans, temp;
	ans = "";

	for (int i = 0; i < _size - 2; i++) {
		for (int j = i + 1; j < _size - 1; j++) {
			temp = Check(_word, i, j);
			if (ans == "") { ans = temp; }
			else {
				if (ans > temp) { ans = temp; }
			}
		}
	}

	cout << ans;
	

	return 0;
}
