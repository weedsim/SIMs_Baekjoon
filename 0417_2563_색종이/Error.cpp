// CRT_SECURE 에 대한 에러를 무시하는 용도이다. 간단한 알고리즘에서는 CRT_SECURE는 필요없기에 무시해도 된다.
#define _CRT_SECURE_NO_WARNINGS
// C++ 의 기본이다.
#include <iostream> 
// 이번에는 없어도 되지만 편의를 위해 존재하고 있다.
#include <algorithm>
// 일반적으로 std 를 붙여가면서 할 것을 미리 명시하는 방식으로 편의를 위해 존재한다.
using namespace std;
	
// N은 색종이의 수이다.
int N;

// 종이의 위치를 저장하기 위해 
struct Paper {
	int x;
	int y;
};

// 종이 100장이하 이기에 인덱스를 99까지로하되 안전하게 100까지로 
Paper paper[101];

// 그냥 종이 수 곱하기 100한 값
// 최종에는 답이 되는 부분
int fullPaper;

// 두 종이의 위치를 확인해서 겹치는 부분이 있는지 확인, 있으면 그 부분만큼의 넓이를 삭제
void check(int now, int before) {
	// 두장을 기준으로 x와 y 모두 10 미만이여야 겹치게 되는 것이다.
	if ((paper[now].x - paper[before].x) < 10 && (paper[now].x - paper[before].x) > -10 && (paper[now].y - paper[before].y) < 10 && (paper[now].y - paper[before].y) > -10) {
		int X = 10 - abs(paper[now].x - paper[before].x);
		int Y = 10 - abs(paper[now].y - paper[before].y);
		fullPaper -= (X * Y);
	}
}

int main()
{
	// 아래 세 줄은 입력과 출력의 시간을 줄여주기위해 존재한다.
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// N은 색종이의 수이다.
	cin >> N;

	// 그냥 종이 수 곱하기 100한 값
	fullPaper = N * 100;

	// N 장의 종이 위치를 입력 받는다
	for (int i = 0; i < N; i++) {
		cin >> paper[i].x >> paper[i].y;
		for (int j = 0; j < i; j++) {
			check(i, j);
		}
	}

	cout << fullPaper;

	return 0;
}