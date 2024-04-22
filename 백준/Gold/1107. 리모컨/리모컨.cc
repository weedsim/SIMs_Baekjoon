#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

bool broken[10];

// 해당 채널을 누를 수 있는지 없는지 확인하는 함수
bool canPress(int channel) {
    if (channel == 0) {
        return !broken[0];
    }
    while (channel > 0) {
        if (broken[channel % 10]) {
            return false;
        }
        channel /= 10;
    }
    return true;
}

// 채널 번호를 누르는데 필요한 버튼 누름 횟수를 반환하는 함수
int pressCount(int channel) {
    if (channel == 0) {
        return 1;
    }
    int length = 0;
    while (channel > 0) {
        length++;
        channel /= 10;
    }
    return length;
}

int main() {
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int button;
        cin >> button;
        broken[button] = true;
    }

    // +, - 버튼만 사용하여 이동하는 경우의 초기값 설정
    int result = abs(N - 100);

    // 0부터 1000000까지 모든 채널을 확인
    for (int i = 0; i <= 1000000; i++) {
        // i 채널을 누를 수 있다면
        if (canPress(i)) {
            // i 채널을 누르는데 필요한 횟수 + i에서 N까지 + 혹은 -로 이동하는 횟수
            int press = pressCount(i) + abs(N - i);
            if (result > press) {
                result = press;
            }
        }
    }

    cout << result;
    return 0;
}
