// CRT_SECURE 에 대한 에러를 무시하는 용도이다. 간단한 알고리즘에서는 CRT_SECURE는 필요없기에 무시해도 된다.
#define _CRT_SECURE_NO_WARNINGS
// C++ 의 기본이다.
#include <iostream>
// 제곱 계산용
#include <cmath>
#include <vector>
#include <algorithm>
// 일반적으로 std 를 붙여가면서 할 것을 미리 명시하는 방식으로 편의를 위해 존재한다.
using namespace std;



int main()
{
	// 아래 세 줄은 입력과 출력의 시간을 줄여주기위해 존재한다.
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    long long D, P;
    cin >> D >> P;

    // 1. 한계값 설정 (10^D)
    // 숫자가 이 값 이상이면 안 됩니다. (미만이어야 함)
    long long limit = 1;
    for (int i = 0; i < D; ++i) {
        limit *= 10;
    }

    // 2. 초기 상태 설정
    // 현재 만들 수 있는 숫자들의 리스트
    vector<long long> current_nums;
    current_nums.push_back(1);

    // 3. P번 반복 (곱셈 수행)
    for (int i = 0; i < P; ++i) {
        vector<long long> next_nums;

        // 현재 가지고 있는 모든 숫자들에 대해
        for (long long num : current_nums) {
            // 2부터 9까지 곱해본다
            for (int mul = 2; mul <= 9; ++mul) {
                long long next_val = num * mul;

                // D자리수 한계를 넘지 않는 경우만 저장
                if (next_val < limit) {
                    next_nums.push_back(next_val);
                }
            }
        }

        // P번 곱하기 전에 더 이상 만들 수 있는 수가 없으면 실패
        if (next_nums.empty()) {
            cout << -1;
            return 0;
        }

        // [핵심] 중복 제거 및 정렬
        // 숫자가 많아지는 것을 방지하여 시간을 단축시킵니다.
        sort(next_nums.begin(), next_nums.end());
        next_nums.erase(unique(next_nums.begin(), next_nums.end()), next_nums.end());

        // 다음 단계를 위해 리스트 갱신
        current_nums = next_nums;
    }

    // 4. 결과 출력
    if (current_nums.empty()) {
        cout << -1;
    }
    else {
        // 오름차순 정렬되어 있으므로 가장 마지막 값이 최댓값
        cout << current_nums.back();
    }

	return 0;
}