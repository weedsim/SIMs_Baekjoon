// CRT_SECURE 에 대한 에러를 무시하는 용도이다. 간단한 알고리즘에서는 CRT_SECURE는 필요없기에 무시해도 된다.
#define _CRT_SECURE_NO_WARNINGS
// C++ 의 기본이다.
#include <iostream> 
// 이번에는 없어도 되지만 편의를 위해 존재하고 있다.
#include <algorithm>
// 입력을 위해 사용
#include <vector>
// 일반적으로 std 를 붙여가면서 할 것을 미리 명시하는 방식으로 편의를 위해 존재한다.
using namespace std;



int main()
{
	// 아래 세 줄은 입력과 출력의 시간을 줄여주기위해 존재한다.
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	vector<int> vec;
	while (1) {
		cin >> N;
		if (N == 0) { break; }
		vec.push_back(N);
	}

	reverse(vec.begin(), vec.end());

	while (!vec.empty()) {
		int _size = 1;
		int n;
		n = vec.back();
		vec.pop_back();
		while (n / 10 != 0 || n % 10 != 0) {
			if (n % 10 == 0) {
				_size += 5;
			}
			else if (n % 10 == 1) {
				_size += 3;
			}
			else {
				_size += 4;
			}
			n /= 10;
		}
		cout << _size;
		cout << "\n";
	}
	

	return 0;
}
