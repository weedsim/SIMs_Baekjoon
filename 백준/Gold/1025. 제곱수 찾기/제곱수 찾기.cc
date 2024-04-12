#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

bool isPerfectSquare(long long n) {
    long long root = sqrt(n);
    return root * root == n;
}

int main() {
    int N, M;
    cin >> N >> M;

    int grid[10][10]; // 10x10 크기의 int 형 2차원 배열 선언

    // 입력 처리
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            char c;
            cin >> c;
            grid[i][j] = c - '0'; // char를 int로 변환하여 저장
        }
    }

    long long largestSquare = -1;

    for (int startX = 0; startX < N; startX++) {
        for (int startY = 0; startY < M; startY++) {
            for (int stepX = -N; stepX <= N; stepX++) {
                for (int stepY = -M; stepY <= M; stepY++) {
                    if (stepX == 0 && stepY == 0) continue;

                    long long num = 0;
                    int x = startX, y = startY;

                    while (x >= 0 && x < N && y >= 0 && y < M) {
                        num = num * 10 + grid[x][y]; // 숫자 생성
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

    cout << largestSquare << endl;

    return 0;
}
