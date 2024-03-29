# 물병

|시간 제한|	메모리 제한|	제출|	정답|	맞힌 사람|	정답 비율|
|----|---------|-----|------|-------|----------|
|1 초|	512 MB|	13945|	5380|	4157|	38.760%|

### 문제

지민이는 N개의 물병을 가지고 있다. 각 물병에는 물을 무한대로 부을 수 있다. 처음에 모든 물병에는 물이 1리터씩 들어있다. 지민이는 이 물병을 또 다른 장소로 옮기려고 한다. 지민이는 한 번에 K개의 물병을 옮길 수 있다. 하지만, 지민이는 물을 낭비하기는 싫고, 이동을 한 번보다 많이 하기는 싫다. 따라서, 지민이는 물병의 물을 적절히 재분배해서, K개를 넘지 않는 비어있지 않은 물병을 만들려고 한다.

물은 다음과 같이 재분배 한다.

먼저 같은 양의 물이 들어있는 물병 두 개를 고른다. 그 다음에 한 개의 물병에 다른 한 쪽에 있는 물을 모두 붓는다. 이 방법을 필요한 만큼 계속 한다.

이런 제약 때문에, N개로 K개를 넘지않는 비어있지 않은 물병을 만드는 것이 불가능할 수도 있다. 다행히도, 새로운 물병을 살 수 있다. 상점에서 사는 물병은 물이 1리터 들어있다.

예를 들어, N=3이고, K=1일 때를 보면, 물병 3개로 1개를 만드는 것이 불가능하다. 한 병을 또다른 병에 부으면, 2리터가 들어있는 물병 하나와, 1리터가 들어있는 물병 하나가 남는다. 만약 상점에서 한 개의 물병을 산다면, 2리터가 들어있는 물병 두 개를 만들 수 있고, 마지막으로 4리터가 들어있는 물병 한 개를 만들 수 있다.

### 입력

첫째 줄에 N과 K가 주어진다. N은 107보다 작거나 같은 자연수이고, K는 1,000보다 작거나 같은 자연수이다.

### 출력

첫째 줄에 상점에서 사야하는 물병의 최솟값을 출력한다. 만약 정답이 없을 경우에는 -1을 출력한다.

### 예제 입력 1 

```
3 1
```

### 예제 출력 1 

```
1
```

### 예제 입력 2 

```
13 2
```

### 예제 출력 2 

```
3
```

### 예제 입력 3 

```
1000000 5
```

### 예제 출력 3 

```
15808
```

### 문제 출처

- [백준 물병](https://www.acmicpc.net/problem/1052)

### 문제 풀이 방식

이진수를 통해 처음의 N 을 최소 물병의 갯수가 몇개가 되는 것인지 확인하고 목표인 K 보다 클 경우에만 갯수를 하나씩 줄이면서 사야하는 물병의 갯수를 찾는 식으로 문제를 접근하였다. 
물병의 갯수를 하나씩 줄이려면 가장 적게 들어있는 물병을 찾고, 그 안의 물 양만큼 물을 사오기에 ans 에 물 양을 더해주며, 다음 물의 양은 이전 물양의 2배로 이루어지는데 이미 2배에 해당하는 물이 들어있는 물병이 있으면 ans에 물의 양을 더할 필요 없이 바로 다음 물양에 해당하는 물병을 더하는 방식으로 반복해간다.
만약 물병의 갯수가 목표인 K 개가 되면 사온 물병의 갯수를 출력하면 해결이다.
