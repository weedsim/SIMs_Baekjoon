// CRT_SECURE 에 대한 에러를 무시하는 용도이다. 간단한 알고리즘에서는 CRT_SECURE는 필요없기에 무시해도 된다.
#define _CRT_SECURE_NO_WARNINGS
// C++ 의 기본이다.
#include <iostream> 
// 편의를 위해 존재하고 있다.
#include <algorithm>
// 일반적으로 std 를 붙여가면서 할 것을 미리 명시하는 방식으로 편의를 위해 존재한다.
using namespace std;



int main()
{
	// 아래 세 줄은 입력과 출력의 시간을 줄여주기위해 존재한다.
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	int arr[51];
	int S;
	cin >> N; 
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	cin >> S;

	for (int i = 0; i < N && S > 0; i++) {

		int maxPos = i;

		for (int j = i; j < N && j <= i + S; j++) {

			if (arr[j] > arr[maxPos]) {
				maxPos = j;
			}

		}

		for (int k = maxPos; k > i; k--) {

			swap(arr[k], arr[k - 1]);

			S--;

		}

	}

	for (int i = 0; i < N; i++) {
		cout << arr[i] << " ";
	}

	return 0;
}
