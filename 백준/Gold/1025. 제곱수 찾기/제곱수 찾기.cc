#include <iostream>
#include <cmath>
#include <vector>
#include <string>

using namespace std;

bool isPerfectSquare(long long n) {
    long long root = sqrt(n);
    return root * root == n;
}

long long findLargestSquare(const vector<string>& grid, int N, int M) {
    long long largestSquare = -1;

    for (int startX = 0; startX < N; ++startX) {
        for (int startY = 0; startY < M; ++startY) {
            for (int stepX = -N; stepX < N; ++stepX) {
                for (int stepY = -M; stepY < M; ++stepY) {
                    if (stepX == 0 && stepY == 0) continue;

                    string numStr = "";
                    int x = startX, y = startY;

                    while (x >= 0 && x < N && y >= 0 && y < M) {
                        numStr += grid[x][y];
                        long long num = stoll(numStr);

                        if (isPerfectSquare(num)) {
                            largestSquare = max(largestSquare, num);
                        }

                        x += stepX;
                        y += stepY;
                    }
                }
            }
        }
    }

    return largestSquare;
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<string> grid(N);
    for (int i = 0; i < N; ++i) {
        cin >> grid[i];
    }

    cout << findLargestSquare(grid, N, M) << endl;

    return 0;
}
