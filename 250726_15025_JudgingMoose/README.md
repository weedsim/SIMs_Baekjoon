# Judging Moose
 
|시간 제한|	메모리 제한|	제출|	정답|	맞힌 사람|	정답 비율|
|-|-|-|-|-|-|
|1 초|	512 MB|	3214|	2046|	1936|	64.148%|

## 문제

When determining the age of a bull moose, the number of tines (sharp points), extending from the main antlers, can be used. An older bull moose tends to have more tines than a younger moose. However, just counting the number of tines can be misleading, as a moose can break off the tines, for example when fighting with other moose. Therefore, a point system is used when describing the antlers of a bull moose.

The point system works like this: If the number of tines on the left side and the right side match, the moose is said to have the even sum of the number of points. So, “an even 6-point moose”, would have three tines on each side. If the moose has a different number of tines on the left and right side, the moose is said to have twice the highest number of tines, but it is odd. So “an odd 10-point moose” would have 5 tines on one side, and 4 or less tines on the other side.

Can you figure out how many points a moose has, given the number of tines on the left and right side?

## 입력

The input contains a single line with two integers ℓ and r, where 0 ≤ ℓ ≤ 20 is the number of tines on the left, and 0 ≤ r ≤ 20 is the number of tines on the right.

## 출력

Output a single line describing the moose. For even pointed moose, output “Even x” where x is the points of the moose. For odd pointed moose, output “Odd x” where x is the points of the moose. If the moose has no tines, output “Not a moose”

### 예제 입력 1 

```
2 3
```

### 예제 출력 1 

```
Odd 6
```

### 예제 입력 2 

```
3 3
```

### 예제 출력 2 

```
Even 6
```

### 예제 입력 3 

```
0 0
```

### 예제 출력 3 

```
Not a moose
```

## 문제 출처

- [백준 AI 선도대학 문제](https://www.acmicpc.net/problem/15025)

## 문제 풀이 방식

 케이스 하나씩 보면 입력 받은 두 수(l, r)에서 `두 수 전부 0인 경우`, `두 수가 같은 경우`, `두 수가 다른 경우` 이렇게 세 가지 경우의 수가 있으며, 먼저 `두 수 전부 0인 경우`는 그대로 "Not a moose"를 출력하고 종료하면 되고, `두 수가 같은 경우`는 "Even "에 l이나 r의 두 배인 수를 같이 붙여 출력, `두 수가 다른 경우`는 "Odd "에 l이나 r 중 큰 값 중 두 배인 수를 붙여 출력해주는 식으로 하나씩 볼 수 있다.
여기에서 `두 수가 같은 경우` 와 `두 수가 다른 경우`에는 두 수중 큰 값을 찾은 뒤 두 배를 추가 한다는 점으로 동일한 기능으로 볼 수 있기에 해당 부분만 if문 아래에 별개로 작성하는 식으로 최종 정리하였다.
