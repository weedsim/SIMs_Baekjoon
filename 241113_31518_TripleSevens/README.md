# Triple Sevens
 
|시간 제한  |	메모리 제한 |	제출    |	정답    |	맞힌 사람   |	정답 비율|
|-------|-----------|-------|------|------|---------|
|1 초 (추가 시간 없음)	|2048 MB		|648	|506	|454	|80.354%|

## 문제

Eddy is overseeing construction of some new slot machines. His slot machines consist of three wheels, each of which can show one of several different digits. When activated, each wheel shows a random digit. The goal is for all wheels to be able to show the digit $7$.

A slot machine is good if each wheel is capable of showing the digit $7$, and bad otherwise. For a given slot machine, determine if it is good or bad.

### 문제 번역

에디는 새로운 슬롯 머신의 건설을 감독하고 있습니다. 그의 슬롯 머신은 세 개의 휠로 구성되어 있으며, 각 휠은 ​​여러 개의 다른 숫자 중 하나를 표시할 수 있습니다. 활성화되면 각 휠은 ​​임의의 숫자를 표시합니다. 목표는 모든 휠이 숫자를 표시할 수 있도록 하는 것입니다.$7$.

각 휠이 숫자를 표시할 수 있는 경우 슬롯 머신이 좋습니다.$7$, 그렇지 않으면 나쁘다. 주어진 슬롯 머신에 대해 그것이 좋은지 나쁜지 판단한다.

## 입력

The first line contains a single integer $n$ $(1 \leq n \leq 10)$, which is the number of different digits on each wheel. Each wheel has the same number of digits.

Each of the next three lines contains $n$ distinct digits (in the range from $0$ to $9$). These are the digits on each of the three wheels.

### 입력 번역

첫 번째 줄에는 단일 정수가 포함됩니다.$n$ $(1 \leq n \leq 10)$, 각 휠의 다른 숫자의 개수입니다. 각 휠은 ​​같은 숫자의 숫자를 가지고 있습니다.

다음 세 줄에는 각각 다음이 포함됩니다.$n$고유한 숫자(범위 내)$0$에게$9$). 이는 세 바퀴 각각의 숫자입니다.

## 출력

Output a single integer, which is $777$ if the slot machine is good, $0$ otherwise.

### 출력 번역

단일 정수를 출력합니다.$777$슬롯머신이 좋다면,$0$그렇지 않으면.

### 예제 입력 1 

```
2
0 7
7 3
7 0
```

### 예제 출력 1 

```
777
```

### 예제 입력 2 

```
2
0 7
7 3
3 9
```

### 예제 출력 2 

```
0
```

### 문제 출처

- [백준 Triple Sevens 문제](https://www.acmicpc.net/problem/31518)

### 문제 풀이 방식

슬롯 한줄에 하나라도 7이 없으면 777이 나올 수 없고, 세 줄 전체에서 7이 있으면 777을 출력되게 하면 해결이다.
