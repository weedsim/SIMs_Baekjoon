// CRT_SECURE 에 대한 에러를 무시하는 용도이다. 간단한 알고리즘에서는 CRT_SECURE는 필요없기에 무시해도 된다.
#define _CRT_SECURE_NO_WARNINGS
// C++ 의 기본이다.
#include <iostream> 
// 편의를 위해 존재하고 있다.
#include <algorithm>
// 입력용
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
	vector<int> Crain;
	int M;
	vector<int> Box;

	cin >> N;
	for (int i = 0; i < N; i++) {
		int t;
		cin >> t;
		Crain.push_back(t);
	}
	cin >> M;
	for (int i = 0; i < M; i++) {
		int t;
		cin >> t;
		Box.push_back(t);
	}

	sort(Crain.begin(), Crain.end());

	sort(Box.begin(), Box.end());

	if (Crain.back() < Box.back()) {
		cout << -1;
		return 0;
	}

	int ans = 0;
	while (M > 0) {

		for (int i = 0; i < N; i++) {
			
			for (int j = M - 1; j >= 0; j--) {
				if (Crain[i] >= Box[j]) {
					Box.erase(Box.begin() + j);
					M--;
					break;
				}
			}

		}

		ans++;

	}

	cout << ans;

	return 0;
}
