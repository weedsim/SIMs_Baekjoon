// CRT_SECURE 에 대한 에러를 무시하는 용도이다. 간단한 알고리즘에서는 CRT_SECURE는 필요없기에 무시해도 된다.
#define _CRT_SECURE_NO_WARNINGS
// C++ 의 기본이다.
#include <iostream> 
// 이번에는 없어도 되지만 편의를 위해 존재하고 있다.
#include <algorithm>
// 저장용
#include <vector>
// 일반적으로 std 를 붙여가면서 할 것을 미리 명시하는 방식으로 편의를 위해 존재한다.
using namespace std;

// 소인수 분해해서 저장
vector<int> So(int n) {
	vector<int> so;

	while (n % 2 == 0) {
		so.push_back(2);
		n /= 2;
	}

	for (int i = 3; i * i <= n; i += 2) {
		while (n % i == 0) {
			so.push_back(i);
			n /= i;
		}
	}

	if (n > 2) {
		so.push_back(n);
	}

	return so;

}



int main()
{
	// 아래 세 줄은 입력과 출력의 시간을 줄여주기위해 존재한다.
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, K;
	cin >> N >> K;
	int cnt = 0;

	for (int i = 1; i <= N; i++) {
		vector<int> so = So(i);
		bool Is = true;
		int _size = so.size();

		for (int j = 0; j < _size; j++) {
			if (so[j] > K) {
				Is = false;
				break;
			}
		}

		if (Is) {
			cnt++;
		}
		
	}

	cout << cnt << "\n";

	return 0;
}
