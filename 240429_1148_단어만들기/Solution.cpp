// CRT_SECURE 에 대한 에러를 무시하는 용도이다. 간단한 알고리즘에서는 CRT_SECURE는 필요없기에 무시해도 된다.
#define _CRT_SECURE_NO_WARNINGS
// C++ 의 기본이다.
#include <iostream> 
// 편의를 위해 존재하고 있다.
#include <algorithm>
// 계산용
#include <string>
#include <vector>
// 일반적으로 std 를 붙여가면서 할 것을 미리 명시하는 방식으로 편의를 위해 존재한다.
using namespace std;


int main()
{
	// 아래 세 줄은 입력과 출력의 시간을 줄여주기위해 존재한다.
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string word;
	vector<string> str;
	while (1) {

		cin >> word;

		if (word == "-") {
			break;
		}

		if (str.empty()) { str.push_back(word); continue; }
		if (str.back() == word) { continue; }
		str.push_back(word);

	}

	string puzzle;
	while (1) {
		cin >> puzzle;
		if (puzzle == "#") {
			break;
		}

		vector<int> count;
		for (int i = 0; i < 9; i++) {
			count.push_back(0);
		}

		int str_len = str.size();
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < str_len; j++) {
				string temp = puzzle;
				if (str[j].find(temp[i] != string::npos)) {
					string word1 = str[j];
					int word_len = word1.length();
					bool check = true;
					for (int k = 0; k < word_len; k++) {
						if (temp.find(word1[k]) == string::npos) {
							check = false;
							break;
						}
						else {
							temp.erase(temp.find(word1[k]), 1);
						}
					}
					if (check) {
						count[i]++;
					}
				}
			}
		}

		int minCNT = *min_element(count.begin(), count.end());
		int maxCNT = *max_element(count.begin(), count.end());

		string minSTR, maxSTR;

		for (int i = 0; i < 9; i++) {
			if (count[i] == minCNT) {
				minSTR += puzzle[i];
			}
			if (count[i] == maxCNT) {
				maxSTR += puzzle[i];
			}
		}

		sort(minSTR.begin(), minSTR.end());
		minSTR.erase(unique(minSTR.begin(), minSTR.end()), minSTR.end());

		sort(maxSTR.begin(), maxSTR.end());
		maxSTR.erase(unique(maxSTR.begin(), maxSTR.end()), maxSTR.end());

		cout << minSTR << " " << minCNT << " " << maxSTR << " " << maxCNT << "\n";

	}


	return 0;
}
