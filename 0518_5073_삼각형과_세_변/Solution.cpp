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

	while (1) {
		int arr[3];
		cin >> arr[0] >> arr[1] >> arr[2];
		// 오름차순 정렬
		sort(arr, arr + 3);
		// 종료
		if (arr[0] == 0 && arr[1] == 0 && arr[2] == 0) { break; }
		// 세 길이가 같으면
		if (arr[0] == arr[1] && arr[0] == arr[2]) {
			cout << "Equilateral" << "\n";
		}
		// 하위 둘의 길이가 같으면
		else if (arr[0] == arr[1]) {
			if (arr[2] >= (arr[0] + arr[1])) { // 삼각형이 안됨
				cout << "Invalid" << "\n";
			}
			else { 
				cout << "Isosceles" << "\n";
			}
		}
		// 상위 둘의 길이가 같으면
		else if (arr[1] == arr[2]) {
			cout << "Isosceles" << "\n";
		}
		// 세 변의 길이가 다르면
		else {
			if (arr[2] >= (arr[0] + arr[1])) { // 삼각형이 안됨
				cout << "Invalid" << "\n";
			}
			else {
				cout << "Scalene" << "\n";
			}
		}
	}
	return 0;
}