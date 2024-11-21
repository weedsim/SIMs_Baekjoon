// CRT_SECURE 에 대한 에러를 무시하는 용도이다. 간단한 알고리즘에서는 CRT_SECURE는 필요없기에 무시해도 된다.
#define _CRT_SECURE_NO_WARNINGS
// C++ 의 기본이다.
#include <iostream> 
// 편의를 위해 존재하고 있다.
#include <algorithm>
#include <vector>
// 일반적으로 std 를 붙여가면서 할 것을 미리 명시하는 방식으로 편의를 위해 존재한다.
using namespace std;

struct Arr {
	int Y;
	float X1;
	float X2;
} arr;

bool cmp(Arr a, Arr b) {
	if (a.Y > b.Y) { return true; }

	return false;
}

int main()
{
	// 아래 세 줄은 입력과 출력의 시간을 줄여주기위해 존재한다.
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int N;
    cin >> N;
	 int Y, X1, X2;
	vector<Arr> vec;

	for (int i = 0; i < N; i++) {
		cin >> arr.Y >> X1 >> X2;
		arr.X1 = X1;
		arr.X2 = X2;
		vec.push_back(arr);
	}

	sort(vec.begin(), vec.end(), cmp);

	int ans = 0;
	
	for (int i = 0; i < N; i++) {
		ans += (vec[i].Y * 2);
		X1 = vec[i].X1;
		X2 = vec[i].X2 - 1;
		for (int j = i + 1; j < N; j++) {
			if (vec[j].X1 <= X1 && X1 < vec[j].X2) {
				ans -= vec[j].Y;
				break;
			}
		}
		for (int j = i + 1; j < N; j++) {
			if (vec[j].X1 <= X2 && X2 < vec[j].X2) {
				ans -= vec[j].Y;
				break;
			}
		}
	}

	cout << ans;

	return 0;
}