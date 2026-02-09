// CRT_SECURE 에 대한 에러를 무시하는 용도이다. 간단한 알고리즘에서는 CRT_SECURE는 필요없기에 무시해도 된다.
#define _CRT_SECURE_NO_WARNINGS
// C++ 의 기본이다.
#include <iostream>
// 일반적으로 std 를 붙여가면서 할 것을 미리 명시하는 방식으로 편의를 위해 존재한다.
using namespace std;


int main()
{
	// 아래 세 줄은 입력과 출력의 시간을 줄여주기위해 존재한다.
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int _testCase;
	cin >> _testCase;

	int base[41] = { 0, 1, };

	for (int i = 2; i < 41; i++)
	{
		base[i] = base[i - 1] + base[i - 2];
	}

	for (int tc = 0; tc < _testCase; tc++)
	{
		int t;
		cin >> t;

		if (t == 0)
		{
			cout << "1 0\n";
		}
		else
		{
			cout << base[t - 1] << " " << base[t] << "\n";
		}
	}

	return 0;
}