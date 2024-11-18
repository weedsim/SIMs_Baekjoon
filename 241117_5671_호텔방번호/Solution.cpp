// CRT_SECURE 에 대한 에러를 무시하는 용도이다. 간단한 알고리즘에서는 CRT_SECURE는 필요없기에 무시해도 된다.
#define _CRT_SECURE_NO_WARNINGS
// C++ 의 기본이다.
#include <iostream> 
// 편의를 위해 존재하고 있다.
#include <algorithm>
#include <string>
#include <unordered_set>
// 임시 저장용도
#include <vector>
// 일반적으로 std 를 붙여가면서 할 것을 미리 명시하는 방식으로 편의를 위해 존재한다.
using namespace std;

bool hasRepeatedDigits(int number) {
    string str = to_string(number);
    unordered_set<char> digitSet;

    for (char digit : str) {
        if (digitSet.find(digit) != digitSet.end()) {
            return true; // 중복된 숫자 발견
        }
        digitSet.insert(digit);
    }
    return false; // 중복 없음
}

int main()
{
	// 아래 세 줄은 입력과 출력의 시간을 줄여주기위해 존재한다.
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int N, M;
    while (cin >> N >> M) {
        int count = 0;

        for (int i = N; i <= M; ++i) {
            if (!hasRepeatedDigits(i)) {
                count++; // 유효한 방 번호 카운트
            }
        }

        cout << count << "\n"; // 결과 출력
    }

	return 0;
}