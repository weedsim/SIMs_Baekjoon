// CRT_SECURE 에 대한 에러를 무시하는 용도이다. 간단한 알고리즘에서는 CRT_SECURE는 필요없기에 무시해도 된다.
#define _CRT_SECURE_NO_WARNINGS
// C++ 의 기본이다.
#include <iostream> 
// 이번에는 없어도 되지만 편의를 위해 존재하고 있다.
#include <algorithm>
// 입력에 필요
#include <string>
// 월을 숫자로 변환하게위해
#include <map>
// 일반적으로 std 를 붙여가면서 할 것을 미리 명시하는 방식으로 편의를 위해 존재한다.
using namespace std;



int main()
{
	// 아래 세 줄은 입력과 출력의 시간을 줄여주기위해 존재한다.
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	map<char, int> _x;
	_x['A'] = 1;
	_x['B'] = 2;
	_x['C'] = 3;
	_x['D'] = 4;
	_x['E'] = 5;
	_x['F'] = 6;
	bool ans = true;

	int _used[7][7] = { 0, };

	int before_x;
	int before_y;

	string tmp;
	cin >> tmp;
	int X = _x[tmp[0]];
	int Y = (tmp[1] - '0');
	_used[Y][X] = 1;
	before_x = X;
	before_y = Y;
	string first = tmp;

	bool temp = false;

	for (int i = 0; i < 35; i++) {
		string tmp;
		cin >> tmp;
		X = _x[tmp[0]];
		Y = (tmp[1] - '0');
		if (_used[Y][X] == 1) { temp = true; }
		_used[Y][X] = 1;
		if (ans) {
			if ((abs(before_x - X) == 1 && abs(before_y - Y) == 2) || (abs(before_x - X) == 2 && abs(before_y - Y) == 1)) {
				ans = true;
			}
			else {
				ans = false;
			}
		}

		before_x = X;
		before_y = Y;
	}

	X = _x[first[0]];
	Y = (first[1] - '0');

	if (ans && !temp) {
		if ((abs(before_x - X) == 1 && abs(before_y - Y) == 2) || (abs(before_x - X) == 2 && abs(before_y - Y) == 1)) {
			cout << "Valid";
		}
		else {
			cout << "Invalid";
		}
	}
	else {
		cout << "Invalid";
	}

	return 0;
}
