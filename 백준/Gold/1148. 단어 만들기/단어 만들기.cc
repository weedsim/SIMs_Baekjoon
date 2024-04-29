#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>
using namespace std;

unordered_set<string> dictionary;

// 단어가 퍼즐판으로 만들 수 있는지 확인하는 함수
bool canBeFormed(const string& word, const string& puzzle) {
    string availableChars = puzzle;
    for (char c : word) {
        auto pos = availableChars.find(c);
        if (pos == string::npos) {
            return false;
        } else {
            availableChars.erase(pos, 1);
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string word;
    while (true) {
        cin >> word;
        if (word == "-") break;
        dictionary.insert(word);
    }

    string puzzle;
    while (true) {
        cin >> puzzle;
        if (puzzle == "#") break;

        vector<int> counts(9, 0);
        for (int center = 0; center < 9; ++center) {
            for (const auto& word : dictionary) {
                // 중앙 글자가 포함되어 있는지 확인
                if (word.find(puzzle[center]) != string::npos) {
                    if (canBeFormed(word, puzzle)) {
                        counts[center]++;
                    }
                }
            }
        }

        int minCount = *min_element(counts.begin(), counts.end());
        int maxCount = *max_element(counts.begin(), counts.end());

        string minChars, maxChars;
        for (int i = 0; i < 9; ++i) {
            if (counts[i] == minCount) {
                minChars.push_back(puzzle[i]);
            }
            if (counts[i] == maxCount) {
                maxChars.push_back(puzzle[i]);
            }
        }
        
        // 중복 문자 제거 및 정렬
        sort(minChars.begin(), minChars.end());
        minChars.erase(unique(minChars.begin(), minChars.end()), minChars.end());
        
        sort(maxChars.begin(), maxChars.end());
        maxChars.erase(unique(maxChars.begin(), maxChars.end()), maxChars.end());

        cout << minChars << " " << minCount << " " << maxChars << " " << maxCount << "\n";
    }

    return 0;
}
