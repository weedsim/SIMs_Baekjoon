# 별 찍기 - 12
 
|시간 제한|	메모리 제한|	제출|	정답|	맞힌 사람|	정답 비율|
|----|--------|------|-------|-------|---------|
|1 초|	128 MB|	20807|	17307|	15990|	84.167%|

### 문제

예제를 보고 규칙을 유추한 뒤에 별을 찍어 보세요.

### 입력

첫째 줄에 N(1 ≤ N ≤ 100)이 주어진다.

### 출력

첫째 줄부터 2×N-1번째 줄까지 차례대로 별을 출력한다.


### 예제 입력 1 

```
3
```

### 예제 출력 1 

```
  *
 **
***
 **
  *
```

### 문제 출처

- [백준 별 찍기 - 12 문제](https://www.acmicpc.net/problem/2522)

### 문제 풀이 방식

우선적으로 규칙을 찾아보면 첫 번째 줄은 띄어쓰기 N-1개, 별이 1개이고, 둘째 줄은 띄어쓰기가 N-2 개, 별이 2개 이런 식이며, N번 째 줄까지는 띄어쓰기가 하나씩 감소하고, 별이 하나씩 증가하는 상황이고, 그 다음 줄인 N+1 줄부터 (2*N)-1줄까지는 띄어쓰기가 하나씩 증가, 별이 하나씩 감소하는 상황으로 규칙을 찾을 수 있다.
이 규칙들을 이용하여 for 문을 작성하면 해결이다. 
