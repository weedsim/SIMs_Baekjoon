#include <algorithm>
#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    // 사라진 인형 총합
    int answer = 0;
    // 정사각형이기에 세로만 측정
    int N = board.size();
    // 몇번 움직이는지
    int _size = moves.size();
    // 바구니
    vector<int> bucket;

    // 움직임 0번 부터 하나씩
    for (int i = 0; i < _size; i++) {
        
        for (int j = 0; j < N; j++) {
            // 보드에서 가장 위에 있는 수 찾기 
            if (board[j][moves[i] - 1] != 0) {

                // 처음에는 비었으니
                if (bucket.empty()) {
                    bucket.push_back(board[j][moves[i] - 1]);
                    board[j][moves[i] - 1] = 0;
                }
                // 바구니 제일 위의 숫자와 동일하면
                else if (bucket.back() == board[j][moves[i] - 1]) {
                    bucket.pop_back();
                    board[j][moves[i] - 1] = 0;
                    answer += 2;
                }
                // 다르면 그냥 삽입
                else {
                    bucket.push_back(board[j][moves[i] - 1]);
                    board[j][moves[i] - 1] = 0;
                }

                break;
            }
        }
    }
    
    return answer;
}