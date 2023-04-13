// CRT_SECURE 에 대한 에러를 무시하는 용도이다. 간단한 알고리즘에서는 CRT_SECURE는 필요없기에 무시해도 된다.
#define _CRT_SECURE_NO_WARNINGS
// C++ 의 기본이다.
#include <iostream> 
// 이번에는 없어도 되지만 편의를 위해 존재하고 있다.
#include <algorithm>
// 키와 value를 직접 컨트롤 하려고 사용
#include <map>
// 일반적으로 std 를 붙여가면서 할 것을 미리 명시하는 방식으로 편의를 위해 존재한다.
using namespace std;



int main()
{
	// 아래 세 줄은 입력과 출력의 시간을 줄여주기위해 존재한다.
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// N은 출입 로그의 수를 표시한 것이다.
	int N;
	cin >> N;

	// 각 직원이 들어왔는지 나갔는지 체크하기 위해
	string name;
	string inout;
	
  
	map<string, bool> Map;
	for (int i = 0; i < N; i++) {
		cin >> name >> inout;
		if (inout == "enter") {
			Map[name] = true;
			//cout << "insert\n";
		}
		else if (inout == "leave") {
			Map.erase(name);
			//cout << "erase\n";
		}
		else {
			//cout << "error\n";
		}
	}

	for (auto iter = Map.rbegin(); iter != Map.rend(); iter++) {
		cout << iter->first << "\n";
	}


	return 0;
}