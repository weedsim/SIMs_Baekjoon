# 서울사이버대학을 다니고
 
|시간 제한|	메모리 제한|	제출|	정답|	맞힌 사람|	정답 비율|
|-|-|-|-|-|-|
|1 초|	512 MB|	1248|	962|	886|	78.756%|

## 문제

서울사이버대학을 다니고 나의 성공 시대 시작됐다

서울사이버대학을 다니고 나를 찾는 회사 많아졌다

서울사이버대학을 다니고 내 인생이 달라졌다

미래를 바꾸는 전략

서울사이버대학교

서울사이버대학교 로고송은 중독성 강한 멜로디로 매우 매우 유명하다. 빅데이터·AI센터에서 데이터 분석을 하던 노교수와 천교수는 어디선가 들려오는 로고송을 듣고 가장 많이 사용된 글자가 몇 번이나 등장하는지 궁금해졌다.

멜로디에 중독된 두 교수를 대신해서 가장 많이 사용된 글자가 몇 번 등장하는지를 출력하자.

## 입력

첫 번째 줄에 로고송의 길이 $N$이 주어진다. $(1 \le N \le 10^5)$ 

두 번째 줄에 로고송이 한 줄의 문자열로 주어진다. 문자열은 서울사이버대학교 로고송의 영문 번역이 반복되는 형태로 주어지며, 알파벳 소문자와 띄어쓰기, 쉼표, 마침표로만 구성되어 있다. 줄이 띄어쓰기로 끝나는 경우는 주어지지 않는다.

## 출력

첫 번째 줄에 가장 많이 등장한 알파벳의 등장 횟수를 출력한다. (띄어쓰기, 쉼표, 마침표는 세지 않는다.)

### 예제 입력 1 

```
255
my era of success began with seoul cyber university, since attending seoul cyber university, more companies have been seeking me out, my life has changed since i went to seoul cyber university, the strategy that changes the future, seoul cyber university.
```

### 예제 출력 1 

```
34
```

### 예제 입력 2 

```
1
m
```

### 예제 출력 2 

```
1
```

### 예제 입력 3 

```
51
my era of success began with seoul cyber university
```

### 예제 출력 3 

```
6
```

## 노트

로고송의 영문 번역은 `"my era of success began with seoul cyber university, since attending seoul cyber university, more companies have been seeking me out, my life has changed since i went to seoul cyber university, the strategy that changes the future, seoul cyber university."` 이다.

## 문제 출처

- [백준 서울사이버대학을 다니고 문제](https://www.acmicpc.net/problem/30958)

## 문제 풀이 방식

하단 노트에 있는 원문을 보게 되면 알파벳이 전부 소문자 임을 확인할 수 있기에 26자를 기준으로 진행하기에 배열로 확인 과정을 진행할 것이다.
다만 문제는 char로 입력을 받게 되면 띄어쓰기는 입력을 받을 수 없게 되기에 그냥 전체 한 줄을 통째로 가져온 후에 0부터 먼저 입력받은 N까지 확인하면서 해당 소문자가 나온 횟수를 탐색한 뒤, 그 중 가장 큰 값을 출력해주면 해결이다.
사실 배열 내의 최댓값을 찾아주는 max_element() 함수가 있으나 algorithm 헤더를 사용해야 한다는 점과 메모리의 제한이 크다는 점에 직접 더해가면서 가장 큰 값을 직접 찾는 방식으로 진행하였다.
 