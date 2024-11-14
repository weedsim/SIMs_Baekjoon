# Reverse Words (Large)
 
|시간 제한  |	메모리 제한 |	제출    |	정답    |	맞힌 사람   |	정답 비율|
|-------|-----------|-------|------|------|---------|
|5 초	|512 MB		|505	|398	|362	|79.039%|

## 문제

Given a list of space separated words, reverse the order of the words. Each line of text contains L letters and W words. A line will only consist of letters and space characters. There will be exactly one space character between each pair of consecutive words.

## 입력

The first line of input gives the number of cases, N.
N test cases follow. For each test case there will a line of letters and space characters indicating a list of space separated words. Spaces will not appear at the start or end of a line.


Limits

- N = 100
- 1 ≤ L ≤ 1000

## 출력

For each test case, output one line containing "Case #x: " followed by the list of words in reverse order.

### 예제 입력 1 

```
3
this is a test
foobar
all your base
```

### 예제 출력 1 

```
Case #1: test a is this
Case #2: foobar
Case #3: base your all
```

### 문제 출처

- [백준 Reverse Words (Large) 문제](https://www.acmicpc.net/problem/12606)

### 문제 풀이 방식

개행문자를 기준으로 입력을 받아오는데, 입력 받아오기 전에 있는 개행문자로 인해 첫 개행문자를 넘어가게 하기 위해서는 "cin.ignore();"을 for문 이전에 입력하고 시작해야 한다.
다름으로 뒤부터 vector와 string을 활용하여 뒤쪽 문자열을 출력해주면 해결이다.
