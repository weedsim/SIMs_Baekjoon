# FYI
 
|시간 제한|	메모리 제한|	제출|	정답|	맞힌 사람|	정답 비율|
|-|-|-|-|-|-|
|1 초|	512 MB|	4052|	3208|	3043|	80.016%|

## 문제

In the United States of America, telephone numbers within an area code consist of 7 digits: the prefix number is the first 3 digits and the line number is the last 4 digits. Traditionally, the 555 prefix number has been used to provide directory information and assistance as in the following examples:

- 555-1212
- 555-9876
- 555-5000
- 555-7777

Telephone company switching hardware would detect the 555 prefix and route the call to a directory information operator. Now-a-days, telephone switching is done digitally and somewhere along the line a computer decides where to route calls.

For this problem, write a program that determines if a supplied 7-digit telephone number should be routed to the directory information operator, that is, the prefix number is 555.

## 입력

The input consists of a single line containing a 7-digit positive integer N, (1000000 <= N <= 9999999).

## 출력

The single output line consists of the word YES if the number should be routed to the directory information operator or NO if the number should not be routed to the directory information operator.

### 예제 입력 1 

```
5551212
```

### 예제 출력 1 

```
YES
```

### 예제 입력 2 

```
5519876
```

### 예제 출력 2

```
NO
```

### 예제 입력 3

```
5055555
```

### 예제 출력 3

```
NO
```

### 예제 입력 4

```
5550000
```

### 예제 출력 4

```
YES
```

## 문제 출처

- [백준 FYI 문제](https://www.acmicpc.net/problem/17863)

## 문제 풀이 방식

해당 문제에서 입력에 따라 달라지겠지만, 만약 int로 입력받은 경우 앞의 세 자리 수만 필요하기에 10000로 나눈 몫을 구하고 해당 값이 555인지 아닌지 확인하는 방식으로 하고, 만약 string으로 입력받은 경우 인덱스 0, 1, 2가 5인지 그 외의 경우 인지 확인해서 YES 와 NO 를 출력하면 해결이다. 이때, 실수로라도 소문자로 하면 틀리니 주의하자…..
 