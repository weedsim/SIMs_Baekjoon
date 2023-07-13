#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());
    int _size = completion.size();

    for (int i = 0; i < _size; i++) {
        if (participant[i] != completion[i]) {
            answer = participant[i];
            break;
        }
    }

    if (answer == "") {
        answer = participant[_size];
    }

    return answer;
}
