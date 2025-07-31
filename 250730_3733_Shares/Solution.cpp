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
	
	// 몇 번의 입력이 있을지는 알 수 없기에 그냥 줄 때까지 기다리는 것으로 진행
	// 문제의 내용과 답이 조금 이상하지만, 답을 기준으로 하면 S를 N+1로 나눈 몫을 구하는게 목표

	int N, S;
	
	while (cin >> N >> S) {
		cout << S / (N + 1) << '\n';
	}

	return 0;
}