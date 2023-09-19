// CRT_SECURE 에 대한 에러를 무시하는 용도이다. 간단한 알고리즘에서는 CRT_SECURE는 필요없기에 무시해도 된다.
#define _CRT_SECURE_NO_WARNINGS
// C++ 의 기본이다.
#include <iostream> 
// 이번에는 없어도 되지만 편의를 위해 존재하고 있다.
#include <algorithm>
// 입력용
#include <vector>
#include <map>
// 일반적으로 std 를 붙여가면서 할 것을 미리 명시하는 방식으로 편의를 위해 존재한다.
using namespace std;

//bool tmp(map<int, int> a, map<int, int> b) {
bool tmp(const map<int, int>& a, const map<int, int>& b) {
	// 두 맵의 value 값을 비교하여 정렬
	return a.begin()->second < b.begin()->second;
}

bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
	if (a.second == b.second) return a.first < b.first;
	return a.second < b.second;
}

int main()
{
	// 아래 세 줄은 입력과 출력의 시간을 줄여주기위해 존재한다.
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	
	vector<pair<int, int>> P;
	
	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;
		P.push_back(make_pair(n, i));
	}

	sort(P.begin(), P.end());

	vector<int> p(N);

	for (int i = 0; i < N; i++) {
		p[P[i].second] = i;
	}

	for (auto a : p) {
		cout << a << " ";
	}

	return 0;
}
