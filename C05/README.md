# C05

### [ft_iterative_factorial](#ex00)
### [ft_recursive_factorial](#ex01)
### [ft_iterative_power](#ex02)
### [ft_recursive_power](#ex03)
### [ft_fibonacci](#ex04)
### [ft_sqrt](#ex05)
### [ft_is_prime](#ex06)
### [ft_find_next_prime](#ex07)
### [ft_ten_queens_puzzle](#ex08) 🚨


## ex00 
### int     ft_iterative_factorial(int nb);
팩토리얼 연산 함수
-   인자가 유효하지 않을 경우, 즉 음수일 경우
>   return (0);
-   인자가 0일 경우, 즉 0!일 경우
>   return (1);

## ex01 
### int     ft_recursive_factorial(int nb);
재귀함수를 활용한 팩토리얼 연산
-   return 값에 재귀함수를 부여
>   재귀함수는 nb-1의 값이 1이 되는 순간 return (1)이 되어 더이상 재귀를 반복하지 않는다

## ex02 
### int    ft_iterative_power(int nb, int power);
power은 지수를 의미, nb를 power번 곱하는 함수

## ex03 
### int    ft_recursive_power(int nb, int power);
재귀함수를 활용한 nb의 power승 연산 함수

## ex04
### int    ft_fibonacci(int index);
피보나치 함수
-   0, 1, 1, 2, 3, 5, 8, 13 ...
>   피보나치의 특성을 재귀함수를 활용하여 연산

## ex05 
### int    ft_sqrt(int nb);
sqrt, 즉 제곱근을 구하는 함수
-   조건 1) 매개변수로 주어진 nb를 idx = 2부터 하나씩 올라가며 % 연산의 결과가 0
-   조건 2) idx * idx = nb라면 nb'sqrt는 idx
>   10의 경우 2와 5로 나누어지지만 10의 제곱근은 루트 10이므로 무리수에 해당
-   예외 조건
>   int 자료형을 고려하여 idx의 범위를 46340으로 제한<br>
>   46341 * 46341 = 2147488281<br>
>   매개변수가 nb 2147483647를 넘는 숫자가 오지는 않겠지만<br>
>   idx가 46341이 될 수 있기 때문에 예외 필요

## ex06
### int    ft_is_prime(int nb);
소수 구하기 함수
-   소수의 특징은 nb를 나늘 수 있는 자연수가 1과 nb만 존재
-   1은 소수가 아니다
-   nb % idx++ = 0 일떄
>   nb == idx 이면 소수

## ex07 
### int    ft_find_next_prime(int nb);
nb보다 크거나 같은 소수 구하기 함수
-   ft_is_prime 함수를 활용
-   ex06과 다르게 소수 여부 판별하고 소수가 아닐 경우 nb++ 후 소수 판별을 반복
>   런타임 오류 발생 -> `에라토스테네스의 체` 활용
![find_next_prime](https://user-images.githubusercontent.com/87407504/150549513-2aca9ac6-0a59-4e71-ac20-f3f6910167e3.gif)<br>

>   nb가 123일때 2부터 123까지의 배수를 뺄 필요 없다
>   nb의 제곱근만큼만 빼주면 된다
>   즉, 2, 3, 5, 7, 11배수까지만 빼주면 된다
```.c
while (idx <= nb / idx) // 자기 자신까지 idx가 오지 않기 때문에
{
    if (nb % idx == 0)  // 나눠진다는 것은 배수로 나눠진다는 것을 의미하므로
        return (0);     // 바로 소수가 아님을 판정
    idx++;
}
```

## ex08 
### int    ft_ten_queens_puzzle(vdid);  🚨
>   전형적인 백트래킹 문제

백트래킹(backtracking)<br>
-   해를 찾는 도중 해가 아니어서 막히면, 되돌아가서 다시 해를 찾아가는 기법
>   cf) 깊이 우선 탐색(DFS)<br>
>   가능한 모든 경로를 탐색<br>
>   경우의 수를 줄이지 좃함

-   불필요한 부분을 쳐내고 최대한 올바른쪽으로 가는데 이를 가지치기라고 함
-   가지치기를 얼마나 잘하느냐에 따라 효율성이 결정
-   모든 가능한 경우의 수 중에서 특정한 조건을 만족하는 경우만 살펴보는 것

1.  모든 경우의 수를 탐색하는 과정에서 
2.  조건문 등을 걸어 답이 안되는 상황을 정의하고 (유망성 판단)
3.  그러한 상황일 경우 탐색을 중지시킨 뒤 
4.  그 이전으로 돌아가 다시 다른경우를 탐색 (부모노드로 돌아가는 것을 backtracking)


[재귀의 특성 참고](https://github.com/Ejaeda/42_study/tree/master/DataStructure/Ch02.Recursion)<br>

코드 풀이 방식
1.  일차원 배열 chess[10]에 Queen의 위치를 표시
2.  배열의 idx는 row, 값 chess[row]는 col에 해당
3.  row를 고정하고 col 값을 promising으로 판단하여 입력후 row + 1;
4.  promising이 안될 경우 부모 노드로 되돌아가기

promising 확인
-   가로 중복 체크
```.c
    //  row를 고정하고 col을 promising에 맞게 입력 후 row + 1 하므로 곂치지 않음
    //  체크 필요 없음
```
-   세로 중복 체크
```.c
    // 0부터 지금까지 저장된 row까지의 idx의 값 chess[idx]와 현재 넣고싶은 col을 비교
    chess[idx] == col;      // 아직 col을 chess[row]라고 하면 안됨! 🚨
```
-   대각선 중복 체크
<img width="833" alt="KakaoTalk_Photo_2022-02-09-13-46-03" src="https://user-images.githubusercontent.com/87407504/153123626-ae135844-c627-460f-9434-b4176295c829.png"><br>
```.c
    // X - x == Y - y
    // X - x == ft_abs(Y, y);
    
    row - idx == ft_abs(col, chess[idx]);
```

중요 핵심
-   배열의 초기화는 chess[10] = {0}이 아니다! 문자열과 헷갈리지 마라🚨
-   row는 재귀함수가 돌때마다 ++되어야 하므로 매개변수로 선언하고 받아야한다 🚨
-   ft_ten_queens_puzzle에서 result로 선언하였으므로 reculsive 인자로 &result를 준다
-   reculsive에서 * result로 선언하였으므로 reculsive 인자로 result를 준다 🚨
-   int chess[]를 putchar 하는 것이니 반드시 + '0' 🚨

백트래킹의 오해 🚨
-   하나를 쭉 가다가 안되면 row - 1해서 다시 시작하는 것이 아니다!
![KakaoTalk_Photo_2022-02-15-01-37-17](https://user-images.githubusercontent.com/87407504/153906447-02348a03-df89-49fa-a001-81d758d259f2.jpeg)<br>

1.  가지를 뻗어 나갈 수 있는 경우의 수를 모두 수행 (DFS)
2.  유망한 노드인지 검토 (promising)
    -   유망하지 않을 경우 return 0으로 끝
    -   if문을 들어가지 않으므로 col++ 된 후 다시 유망 노드 확인

3.  방문한 노드의 하위 노드로 이동하여 (row ++) 다시 DFS (reculsive)
4.  갯수가 모두 차면 더이상 재귀가 돌아가지 않는다 ( while (col < 10) )
