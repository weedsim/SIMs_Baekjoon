#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    // 입출력 성능 최적화
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K;
    if (!(cin >> N >> K)) return 0;

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
        long long h;
        cin >> h;
        if (h < minA) minA = h;
        if (h > maxA) maxA = h;
    }

    // 1. 사자가족 사이의 고정된 키 차이 합산
    long long total_diff = 0;
    for (int i = 0; i < K - 1; ++i) {
        total_diff += abs(lions[i] - lions[i+1]);
    }

    // 사자 외에 다른 사람이 없는 경우 바로 출력
    if (N == K) {
        cout << total_diff << endl;
        return 0;
    }

    // 2. 전체 최댓값(maxA)이 사자 범위를 벗어날 경우의 최소 비용 추가
    if (maxA > maxL) {
        long long cost = abs(lions[0] - maxA); // 맨 앞
        cost = min(cost, abs(lions[K-1] - maxA)); // 맨 뒤
        cost = min(cost, 2 * (maxA - maxL)); // 중간 사자 옆 왕복
        total_diff += cost;
    }

    // 3. 전체 최솟값(minA)이 사자 범위를 벗어날 경우의 최소 비용 추가
    if (minA < minL) {
        long long cost = abs(lions[0] - minA); // 맨 앞
        cost = min(cost, abs(lions[K-1] - minA)); // 맨 뒤
        cost = min(cost, 2 * (minL - minA)); // 중간 사자 옆 왕복
        total_diff += cost;
    }

    cout << total_diff << endl;

    return 0;
}