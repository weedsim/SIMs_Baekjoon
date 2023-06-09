# 약수 구하기
 
|시간 제한|	메모리 제한|	제출|	정답|	맞힌 사람|	정답 비율|
|--------|------------|--------|------|-----------|----------|
|1 초|	128 MB|	36491|	17460|	15338|	48.613%|

### 문제

어떤 자연수 p와 q가 있을 때, 만일 p를 q로 나누었을 때 나머지가 0이면 q는 p의 약수이다. 

6을 예로 들면

- 6 ÷ 1 = 6 … 0
- 6 ÷ 2 = 3 … 0
- 6 ÷ 3 = 2 … 0
- 6 ÷ 4 = 1 … 2
- 6 ÷ 5 = 1 … 1
- 6 ÷ 6 = 1 … 0

그래서 6의 약수는 1, 2, 3, 6, 총 네 개이다.

두 개의 자연수 N과 K가 주어졌을 때, N의 약수들 중 K번째로 작은 수를 출력하는 프로그램을 작성하시오.

### 입력

첫째 줄에 N과 K가 빈칸을 사이에 두고 주어진다. N은 1 이상 10,000 이하이다. K는 1 이상 N 이하이다.

### 출력

첫째 줄에 N의 약수들 중 K번째로 작은 수를 출력한다. 만일 N의 약수의 개수가 K개보다 적어서 K번째 약수가 존재하지 않을 경우에는 0을 출력하시오.

### 예제 입력 1 

```
6 3
```

### 예제 출력 1 

```
3
```

### 예제 입력 2 

```
25 4
```

### 예제 출력 2 

```
0
```

### 예제 입력 3 

```
2735 1
```

### 예제 출력 3 

```
1
```

### 문제 출처

- [백준 약수 구하기 문제](https://www.acmicpc.net/problem/2501)

### 문제 풀이 방식

먼저 약수란 입력받은 N을 1부터 N까지 모든 자연수로 나누었을 때 나머지가 0이면 그게 약수 인 것이다.
그 모든 약수를 저장을 하여 오름 차순으로 정렬을 해준 뒤, 약수의 갯수가 K 보다 작으면 0으로 출력을, K보다 크거나 같으면 K 번째에 해당하는 값을 출력하면 되는 것인데, 오름차순 정렬과 약수의 갯수를 빠르게, 메모리가 적게 들여가며 찾기 위해 vector을 이용하였다.
