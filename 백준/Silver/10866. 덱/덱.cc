// CRT_SECURE 에 대한 에러를 무시하는 용도이다. 간단한 알고리즘에서는 CRT_SECURE는 필요없기에 무시해도 된다.
#define _CRT_SECURE_NO_WARNINGS
// C++ 의 기본이다.
#include <iostream> 
#include <algorithm>
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
	cin >> N;
	vector<int> ans;

	for (int i = 0; i < N; i++) {
		string n;
		cin >> n;

		if (n == "push_front") {
			int X;
			cin >> X;
			ans.insert(ans.begin(), X);
		}
		else if (n == "push_back") {
			int X;
			cin >> X;
			ans.push_back(X);
		}
		else if (n == "pop_front") {
			if (ans.empty()) {
				cout << "-1";
				cout << endl;
			}
			else {
				cout << ans[0];
				ans.erase(ans.begin());
				cout << endl;
			}
		}
		else if (n == "pop_back") {
			if (ans.empty()) {
				cout << "-1";
				cout << endl;
			}
			else {
				cout << ans.back();
				ans.pop_back();
				cout << endl;
			}
		}
		else if (n == "size") {
			cout << ans.size();
			cout << endl;
		}
		else if (n == "empty") {
			if (ans.empty()) {
				cout << "1";
				cout << endl;
			}
			else {
				cout << "0";
				cout << endl;
			}
		}
		else if (n == "front") {
			if (ans.empty()) {
				cout << "-1";
				cout << endl;
			}
			else {
				cout << ans[0];
				cout << endl;
			}
		}
		else if (n == "back") {
			if (ans.empty()) {
				cout << "-1";
				cout << endl;
			}
			else {
				cout << ans.back();
				cout << endl;
			}
		}
	}

	return 0;
}