# Shares
 
|시간 제한|	메모리 제한|	제출|	정답|	맞힌 사람|	정답 비율|
|-|-|-|-|-|-|
|1 초|	128 MB|	11160|	5958|	5620|	54.979%|

## 문제

A group of N persons and the ACM Chief Judge share equally a number of S shares (not necessary all of them). Let x be the number of shares aquired by each person (x must be an integer). The problem is to compute the maximum value of x.

Write a program that reads pairs of integer numbers from an input text file. Each pair contains the values of 1 ≤ N ≤ 10000 and 1 ≤ S ≤ 109 in that order. The input data are separated freely by white spaces, are correct, and terminate with an end of file. For each pair of numbers the program computes the maximum value of x and prints that value on the standard output from the beginning of a line, as shown in the example below.

### 예제 입력 1 

```
1 100
2 7
10 9
10 10
```

### 예제 출력 1 

```
50
2
0
0
```

## 문제 출처

- [백준 Shares 문제](https://www.acmicpc.net/problem/3733)

## 문제 풀이 방식

우선 문제를 한글로 번역해서 봤을 때는  입력받은 S를 N으로 나눈 몫을 구하는 것으로 보였으나 정작 예제를 보면 아니라는 것을 볼 수 있는데, 다른 사람들이 푼 것을 확인해본 결과 N명과 ACM 수석(Chief)까지해서 인원이 N+1명이 S주의 주식을 나누어 먹을 수 있는 최대 값을 구하라는 것이기에 S를 N+1로 나눈 몫을 구하는 방식으로 하면 해결이 되는 것이었다.
 