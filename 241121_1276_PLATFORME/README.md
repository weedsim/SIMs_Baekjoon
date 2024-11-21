# PLATFORME
 
|시간 제한  |	메모리 제한 |	제출    |	정답    |	맞힌 사람   |	정답 비율|
|-------|-----------|-------|------|------|---------|
|2 초	|128 MB		|769	|325	|276	|44.733%|

## 문제

A level is being designed for a new platform game. The locations of the platforms have been chosen. Contrary to popular opinion, platforms can't float in the air, but need pillars for support. More precisely, each of the two ends of the platform needs to be supported by a pillar standing on the floor or on a different platform. 

You will be given the locations of the platforms in a coordinate system as in the left image below. Each platform's location is determined by its altitude (vertical distance from the ground) and the start and end coordinates in the horizontal direction. Each support pillar is placed half a unit from the end of a platform, as in the right image. 

Determine the total length of pillars needed to support all the platforms. 

| <img src="./IMG.png"> | <img src="./IMG2.png"> |
|----------|------------|
| Example level with three platforms. The lowest platform is at altitude 1, the second lowest at altitude 3 and the third at altitude 5.	| The total length of pillars needed to support all platforms is 14. |

## 입력

The first line contains the integer N, 1 ≤ N ≤ 100, the number of platforms. 
Each of the following N lines contains the position of one platform, three coordinates Y, X1 and X2. The first number is the altitude, the other two the horizontal coordinates. All coordinates will be positive integers less than 10000 satisfying X2 > X1+1 (i.e. the length of each platform will be at least 2). 
The input will be such that no two platforms overlap. 

## 출력

Output the total length of pillars needed to support all the platforms. 

### 예제 입력 1 

```
3
1 5 10
3 1 5
5 3 7
```

### 예제 출력 1 

```
14
```

### 예제 입력 2 

```
5
50 50 90
40 40 80
30 30 70
20 20 60
10 10 50
```

### 예제 출력 2 

```
200
```

### 문제 출처

- [백준 PLATFORME 문제](https://www.acmicpc.net/problem/1276)

### 문제 풀이 방식

처음 입력 되는 X 좌표들은 판의 양 끝 좌표인데 이거를 그대로 비교하게 되면 1번 예제에서 높이가 1인 판과 3인 판의 다리가 같은 것처럼 보이게 된다.
하지만 위의 그림을 보면 다리의 위치가 조금 점 좌표에 위치하는 것이 아닌 점과 점 사이에 위치해 있는 것을 볼 수 있는데 이 점을 차용하여 왼 쪽 다리는 X1의 좌표 값에 +1 번째 면에 다리를 놓는다고 두고, 오른쪽 다리는 X2의 좌표 값의 면에 다리를 놓는다는 식으로 인식하여 계산을 진행하였다.
sort를 판이 가장 높이 있는 곳부터 확인하면서 바로 아래의 판에 놓는 다리와 곂치는 부분이 있는지 확인하고, 있는 경우 곂쳐지는 만큼의 값(아래 판의 높이)을 빼는 식으로 진행하면 해결이 된다.
