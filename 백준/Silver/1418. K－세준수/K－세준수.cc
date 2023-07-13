#include <iostream>
#include <vector>

using namespace std;

// 소인수분해 함수
vector<int> primeFactors(int n) {
    vector<int> factors;

    while (n % 2 == 0) {
        factors.push_back(2);
        n /= 2;
    }

    for (int i = 3; i * i <= n; i += 2) {
        while (n % i == 0) {
            factors.push_back(i);
            n /= i;
        }
    }

    if (n > 2)
        factors.push_back(n);

    return factors;
}

int countKFreeNumbers(int N, int K) {
    int count = 0;

    for (int i = 1; i <= N; i++) {
        vector<int> factors = primeFactors(i);
        bool isKFree = true;

        for (int factor : factors) {
            if (factor > K) {
                isKFree = false;
                break;
            }
        }

        if (isKFree)
            count++;
    }

    return count;
}

int main() {
    int N, K;
    cin >> N >> K;

    int result = countKFreeNumbers(N, K);
    cout << result << endl;

    return 0;
}
