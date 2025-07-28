# Periods
 
|시간 제한|	메모리 제한|	제출|	정답|	맞힌 사람|	정답 비율|
|-|-|-|-|-|-|
|1 초|	1024 MB|	1554|	1146|	1085|	74.417%|

## 문제

Eric gets distracted so sometimes he forgets to put periods at the end of his sentences. To help him out, you are to put a period at the end of his sentences if the period is not already present.

## 입력

The first line of input will contain a single integer n that indicates the number of lines to follow. Each line will consist of a sentence which may or may not have a period at the end.

## 출력

Output the sentence, making sure there is one period at the end.

### 예제 입력 1 

```
3
You kicked my dog
No I did not.
It was the kid that did
```

### 예제 출력 1 

```
You kicked my dog.
No I did not.
It was the kid that did.
```

## 문제 출처

- [백준 Periods 문제](https://www.acmicpc.net/problem/26560)

## 문제 풀이 방식

 string 안에 있는 getline 을 사용해서 한 줄 전체 입력을 받은 뒤, 입력받은 줄의 마지막이 '.'으로 되어 있는지 확인 후 없는 경우 추가하여 출력하고, 있는 경우 그대로 출력하면 해결이다.
