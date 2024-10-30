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

	int N;
	cin >> N;

	cout << "어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다.\n";

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < i; j++) {
			cout << "____";
		}
		cout << "\"재귀함수가 뭔가요?\"\n";
		for (int j = 0; j < i; j++) {
			cout << "____";
		}
		cout << "\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어.\n";
		for (int j = 0; j < i; j++) {
			cout << "____";
		}
		cout << "마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지.\n";
		for (int j = 0; j < i; j++) {
			cout << "____";
		}
		cout << "그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\"\n";
	}

	for (int i = 0; i < N; i++) {
		cout << "____";
	}
	cout << "\"재귀함수가 뭔가요?\"\n";
	for (int i = 0; i < N; i++) {
		cout << "____";
	}
	cout << "\"재귀함수는 자기 자신을 호출하는 함수라네\"\n";

	for (int i = N; i >= 0; i--) {
		for (int j = 0; j < i; j++) {
			cout << "____";
		}
		cout << "라고 답변하였지.";
		if (i == 0) { break; }
		cout << "\n";
	}


	return 0;
}