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

	map<string, int> _month;
	_month["January"] = 1;
	_month["February"] = 2;
	_month["March"] = 3;
	_month["April"] = 4;
	_month["May"] = 5;
	_month["June"] = 6;
	_month["July"] = 7;
	_month["August"] = 8;
	_month["September"] = 9;
	_month["October"] = 10;
	_month["November"] = 11;
	_month["December"] = 12;
	map<int, int> _day;
	_day[1] = 31;
	_day[2] = 28;
	_day[3] = 31;
	_day[4] = 30;
	_day[5] = 31;
	_day[6] = 30;
	_day[7] = 31;
	_day[8] = 31;
	_day[9] = 30;
	_day[10] = 31;
	_day[11] = 30;

	string Month;
	string _DD;
	double DD;
	int YYYY;
	bool Pyung = false;
	string HH_MM;
	double HH, MM;
	cin >> Month;
	cin >> _DD >> YYYY;
	cin >> HH_MM;
	DD = stoi(_DD.substr(0, 2));
	HH = stoi(HH_MM.substr(0, 2));
	MM = stoi(HH_MM.substr(3));
	if (YYYY % 400 == 0) {
		Pyung = true;
	}
	else if (YYYY % 4 == 0 && YYYY % 100 != 0) {
		Pyung = true;
	}

	double _all = 0.0000000000;
	double _allMinute = 0;

	// 앞 달들의 날들 다 더하기
	for (int i = 1; i < _month[Month]; i++) {
		if (i == 2) {
			_allMinute += _day[i];
			if (Pyung) {
				_allMinute += 1;
			}
		}
		else {
			_allMinute += _day[i];
		}
	}

	// 현재의 일자 더하기
	_allMinute += (DD - 1);

	// 지금까지의 일자합을 시간 단위로 변형
	_allMinute *= 24;

	// 현재시간 더하기
	_allMinute += HH;

	// 지금까지의 시간 단위를 분 단위로 변형
	_allMinute *= 60;

	// 마지막 분을 더하기
	_allMinute += MM;
	
	//cout << _allMinute << "\n";

	// 퍼센트로 계산하기 위한 분자에 곱하기 100
	_allMinute *= 100;

	if (Pyung) {
		_all = _allMinute / 527040;
	}
	else {
		_all = _allMinute / 525600;
	}

	cout.precision(17);
	//cout << to_string(_all) << "\n";
	cout << _all;


	return 0;
}
