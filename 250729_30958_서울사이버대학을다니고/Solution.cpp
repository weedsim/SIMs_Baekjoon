// CRT_SECURE 에 대한 에러를 무시하는 용도이다. 간단한 알고리즘에서는 CRT_SECURE는 필요없기에 무시해도 된다.
#define _CRT_SECURE_NO_WARNINGS
// C++ 의 기본이다.
#include <iostream> 
// 입력용
#include <string>
// 일반적으로 std 를 붙여가면서 할 것을 미리 명시하는 방식으로 편의를 위해 존재한다.
using namespace std;



int main()
{
	// 아래 세 줄은 입력과 출력의 시간을 줄여주기위해 존재한다.
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	// 답을 확인해보니 가장 많이 사용된 알파벳이 무엇인지 찾는 문제로 해당 문제는 배열을 사용하는 방식으로 진행하겠다.

	int N;
	cin >> N;
	string temp;
	getline(cin, temp);
	getline(cin, temp);

	int arr[26] = { 0, };
	int maxCnt = 0;

	for (int i = 0; i < N; i++) {
		if (temp[i] - 'a' >= 0 && temp[i] - 'a' < 26) {
			arr[temp[i] - 'a']++;
			if (maxCnt < arr[temp[i] - 'a']) { maxCnt = arr[temp[i] - 'a']; }
		}
	}

	cout << maxCnt;

	return 0;
}