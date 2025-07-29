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
	
	// 1. 왼발과 오른발 인원이 같은 경우 양발 선수가 홀수 일 때는 전체 인원에서 1명만 방출, 짝수인 경우 전체 인원이 그대로 유지
	// 2. 왼발과 오른발 인원이 다른 경우 양발 선수가 왼발과 오른발 중 더 적은 쪽에 들어가되 더 많은 쪽 인원을 넘지 않게 한다.
	// 3. 만약 양발 인원이 전부 이동이 되었음에도 기존 많은 인원 쪽이 여전히 많다면 그만큼 인원 삭감
	// 4. 만약 양발 인원이 남는다면 1번과 같은 방식으로 방출 및 유지

	int L, R, A;
	cin >> L >> R >> A;

	if (L == R) {
		if (A % 2 == 0) {
			cout << L + R + A;
		}
		else {
			cout << L + R + A - 1;
		}
	}
	else {
		// 왼발 인원이 오른발 인원보다 많은 경우
		if (L > R) {
			int dis = L - R;
			// 양발 인원이 오른발 인원으로 취급했음에도 왼발 인원이 많은 경우
			if (dis > A) {
				cout << L + R + A + A - dis;
			}
			else { // 양발 인원 중 일부만 오른발 인원이 된 후 남은 양발 인원은 설명의 3번과 같이 확인 후 삭감
				if ((A - dis) % 2 == 0) {
					cout << L + R + A;
				}
				else {
					cout << L + R + A - 1;
				}
			}

		}
		else { // 오른발 인원이 원발 인원보다 많은 경우
			int dis = R - L;
			// 양발 인원이 오른발 인원으로 취급했음에도 왼발 인원이 많은 경우
			if (dis > A) {
				cout << L + R + A + A - dis;
			}
			else { // 양발 인원 중 일부만 오른발 인원이 된 후 남은 양발 인원은 설명의 3번과 같이 확인 후 삭감
				if ((A - dis) % 2 == 0) {
					cout << L + R + A;
				}
				else {
					cout << L + R + A - 1;
				}
			}
		}
	}

	return 0;
}