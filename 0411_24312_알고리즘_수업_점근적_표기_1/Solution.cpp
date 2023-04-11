// CRT_SECURE 에 대한 에러를 무시하는 용도이다. 간단한 알고리즘에서는 CRT_SECURE는 필요없기에 무시해도 된다.
#define _CRT_SECURE_NO_WARNINGS
// C++ 의 기본이다.
#include <iostream> 
// 이번에는 없어도 되지만 편의를 위해 존재하고 있다.
#include <algorithm>
// 일반적으로 std 를 붙여가면서 할 것을 미리 명시하는 방식으로 편의를 위해 존재한다.
using namespace std;



int main()
{
	// 아래 세 줄은 입력과 출력의 시간을 줄여주기위해 존재한다.
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// 최상단 각각 A, B 순으로 입력 받는다.
	int A, B;
	cin >> A >> B;

	// 다음 값은 c로 받는다.
	int c;
	cin >> c;

	// n의 시작 값을 받아서 진행한다.
	int n;
	cin >> n;

	// (A * x) + B <= (c * x) 이것에서 Ax 를 우변으로 이항시켜서 B <= (c - A) * x 로 만들고 B / (c - A) <= x 로 계산하여  B / (c - A) 가 n 보다 크면 만족하지 않는 것이고,
	// n 보다 작거나 같으면 만족하는 것이다. 
	// 하지만 알고리즘 상으로 나누기는 부적합하기에 반대인 곱하기 방식을 이용하는 것으로 대체하여 작업한다.
	// 고로 B 와 n * (c - A) 를 비교하는 방식을 채택한다.
	// 하지만 여기에서 (c - A) 가 음수 인 경우 실직적인 범위가 n0 <= n <= (B / (c - A)) 로 '모든' n0 <= n 이 불가능해진 것으로 무조건 적으로 (c - A) < 0 일 경우는 답이 0으로 되는 것이다.
	int ans;
	ans = n * (c - A);
	if ((c - A) < 0) {
		cout << 0;
	}
	else {
		if (B > ans) {
			cout << 0;
		}
		else {
			cout << 1;
		}
	}

	return 0;
}