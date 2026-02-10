// CRT_SECURE 에 대한 에러를 무시하는 용도이다. 간단한 알고리즘에서는 CRT_SECURE는 필요없기에 무시해도 된다.
#define _CRT_SECURE_NO_WARNINGS
// C++ 의 기본이다.
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
// 일반적으로 std 를 붙여가면서 할 것을 미리 명시하는 방식으로 편의를 위해 존재한다.
using namespace std;

int main() 
{
    // 아래 세 줄은 입력과 출력의 시간을 줄여주기위해 존재한다.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;
    cin >> N >> K;

    vector<long long> lions(K);
    long long minL = 2147483648LL; // 사자 중 최소 키
    long long maxL = -1;           // 사자 중 최대 키

    for (int i = 0; i < K; ++i) {
        cin >> lions[i];
        if (lions[i] < minL) minL = lions[i];
        if (lions[i] > maxL) maxL = lions[i];
    }

    long long minA = minL; // 전체 중 최소 키
    long long maxA = maxL; // 전체 중 최대 키

    for (int i = 0; i < N - K; ++i) {
        int h;
        cin >> h;
        if (h < minA) minA = h;
        if (h > maxA) maxA = h;
    }

    // 1. 사자가족 사이의 고정된 키 차이 합산
    int total_diff = 0;
    for (int i = 0; i < K - 1; ++i) {
        total_diff += abs(lions[i] - lions[i + 1]);
    }

    // 사자 외에 다른 사람이 없는 경우 바로 출력
    if (N == K) {
        cout << total_diff << endl;
        return 0;
    }

    // 2. 전체 최댓값(maxA)이 사자 범위를 벗어날 경우의 최소 비용 추가
    if (maxA > maxL) {
        long long cost = abs(lions[0] - maxA); // 맨 앞
        cost = min(cost, abs(lions[K - 1] - maxA)); // 맨 뒤
        cost = min(cost, 2 * (maxA - maxL)); // 중간 사자 옆 왕복
        total_diff += cost;
    }

    // 3. 전체 최솟값(minA)이 사자 범위를 벗어날 경우의 최소 비용 추가
    if (minA < minL) {
        long long cost = abs(lions[0] - minA); // 맨 앞
        cost = min(cost, abs(lions[K - 1] - minA)); // 맨 뒤
        cost = min(cost, 2 * (minL - minA)); // 중간 사자 옆 왕복
        total_diff += cost;
    }

    cout << total_diff << endl;

    return 0;
}