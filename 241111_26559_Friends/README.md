# Friends
 
|시간 제한  |	메모리 제한 |	제출    |	정답    |	맞힌 사람   |	정답 비율|
|-------|-----------|-------|------|------|---------|
|1 초	|1024 MB		|131	|101	|95	|79.167%|

## 문제

Jane has many friends, but she likes some less than others. She has a number associated with each friend which represents how much she likes each friend. The higher the number, the more she likes that friend. Given her list of friends, sort them so that the best friends are at the top and the least best friends are at the bottom.

### 문제 번역

제인은 많은 친구를 가지고 있지만, 그녀는 어떤 친구는 다른 친구보다 덜 좋아합니다. 그녀는 각 친구와 관련된 숫자를 가지고 있는데, 이는 그녀가 각 친구를 얼마나 좋아하는지 나타냅니다. 숫자가 높을수록 그녀는 그 친구를 더 좋아합니다. 그녀의 친구 목록을 고려하여 가장 친한 친구가 맨 위에 있고 가장 친한 친구가 맨 아래에 있도록 정렬합니다.

## 입력

The first line of input will contain a single integer n that indicates the number datasets to follow. Each dataset will consist an integer m, (0 < m < 500), which is the number of friends that will be in the dataset. The next m lines will have the format “name num”, where name is the name of the friend and num (0 < num < 500) is the number that represents how much she likes her friend. The name will only be one word. No two friends will not have the same num value.

### 입력 번역

첫 번째 입력 줄에는 따라야 할 데이터 세트의 수를 나타내는 단일 정수 n이 포함됩니다. 각 데이터 세트는 정수 m(0 < m < 500)으로 구성되며, 이는 데이터 세트에 포함될 친구의 수입니다. 다음 m 줄은 "name num" 형식을 가지며, 여기서 name은 친구의 이름이고 num(0 < num < 500)은 그녀가 친구를 얼마나 좋아하는지 나타내는 숫자입니다. 이름은 한 단어만 됩니다. 두 친구가 같은 num 값을 가질 수는 없습니다.

## 출력

Output a list of names, separated by a comma and one space, of the friends in order of how much Jane likes them.

### 출력 번역

제인이 친구를 좋아하는 정도에 따라 친구들의 이름 목록을 쉼표와 공백 하나로 구분하여 출력하세요.

### 예제 입력 1 

```
2
2
bill 2
greg 5
4
jim 5
phil 8
paul 7
rob 2
```

### 예제 출력 1 

```
greg, bill
phil, paul, jim, rob
```

### 문제 출처

- [백준 Friends 문제](https://www.acmicpc.net/problem/26559)

### 문제 풀이 방식

name과 num으로 구조체를 구성, 해당 구조체인 vector로 입력받은 후 algorithm의 sort를 활용하여 구조체 중 num으로 내림차순으로 정렬하면 해결이다.
