// CRT_SECURE 에 대한 에러를 무시하는 용도이다. 간단한 알고리즘에서는 CRT_SECURE는 필요없기에 무시해도 된다.
#define _CRT_SECURE_NO_WARNINGS
// C++ 의 기본이다.
#include <iostream> 
// 이번에는 없어도 되지만 편의를 위해 존재하고 있다.
#include <algorithm>
// 입력은 string으로
#include <string>
// 일반적으로 std 를 붙여가면서 할 것을 미리 명시하는 방식으로 편의를 위해 존재한다.
using namespace std;



int main()
{
	// 아래 세 줄은 입력과 출력의 시간을 줄여주기위해 존재한다.
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// 과목 이름
	string name;
	// 학점
	float point;
	// 등급
	string gr;

	// 총 학점
	double full = 0;
	// 학점과 등급에 10을 곱
	double Max = 0;

	for (int i = 0; i < 20; i++) {
		cin >> name >> point >> gr;
		if (gr == "P") {
			continue;
		}
		else if (gr == "A+") {
			Max += (45 * point);
		}
		else if (gr == "A0") {
			Max += (40 * point);
		}
		else if (gr == "B+") {
			Max += (35 * point);
		}
		else if (gr == "B0") {
			Max += (30 * point);
		}
		else if (gr == "C+") {
			Max += (25 * point);
		}
		else if (gr == "C0") {
			Max += (20 * point);
		}
		else if (gr == "D+") {
			Max += (15 * point);
		}
		else if (gr == "D0") {
			Max += (10 * point);
		}
		else if (gr == "F") {
			
		}

		full += point;
	}

	Max /= (double)10;

	double ans;
	ans = Max / full;

	cout << Max / full;

	return 0;
}