# 📖 C01

📖 ***`포인터`를 활용해 함수 간에 값을 변화시키고 공유하는 연습을 한다***

-----

### [ft_ft](#ex00)
### [ft_ultimate_ft](#ex01)
### [ft_swap](#ex02)
### [ft_div_mod](#ex03)
### [ft_ultimate_div_mod](#ex04)
### [ft_putstr](#ex05)
### [ft_strlen](#ex06)
### [ft_rev_int_tab](#ex07)
### [ft_sort_int_tab](#ex08)

-----

## ex00 
### 📌 void *ft_ft(int  *nbr);

`포인터`를 매개변수로 보내어 `값을 변화시키는` 함수

```.c
int*   nbr = &i;
```

-   변수가 int형 이라면 그 변수의 주소는 int *형이다
-   포인터는 변수의 주소를 저장하는 변수이다
-   변수의 주소를 저장하는 int* 형 nbr를 매개변수로 선언하고 변수의 주소를 저장한다
-   포인터 nbr은 `*`를 통해 해당 변수의 값에 접근할 수 있다

## ex01 
### 📌 void	ft_ultimate_ft(int	*********nbr);

`포인터`의 주소를 `포인터`에 저장할 수 있음을 보이는 함수

-   int *형 포인터, p의 주소 &p는 int **형에 저장할 수 있다

```.c
int nbr;

int* p1 = &nbr;          // 변수 nbr의 주소를 저장하는 int* 형
int** p2 = p1;           // int*형 변수의 주소를 저장하기 위해서는 int** 형

...

int******** p8 = p7      // int* x 7 형 변수의 주소를 저장하기 위해서는 int* x 8형
```

## ex02 
### 📌 void ft_swap(int	*a, int	*b);

매개변수로 연결된 `포인터`로 `변수 값에 직접적인 영향을 미칠 수 있음`을 보이는 함수

- 두개의 값을 서로 바꾸는 swap 함수

## ex03 
### 📌 void	ft_div_mod(int a, int b, int *div, int *mod);

매개변수로 연결된 `포인터`로 `값을 변화시키고 공유하는` 함수

- 나누기 `몫` 연산자    -> `/`
- 나누기 `나머지` 연산자 -> `%`

## ex04 
### 📌 void	ft_ultimate_div_mod(int *a, int *b);

ex02와 ex03를 결합한 함수

## ex05 
### 📌 void	ft_putstr(char *str);

매개변수 포인터로 배열의 주소를 연결한 뒤 write 함수로 값을 출력하는 함수

## ex06 
### 📌 int	ft_strlen(char *str);

매개변수 포인터로 배열의 주소를 연결한 뒤 배열의 길이를 구하는 함수
> 🚨 문자열 마지막에 들어가는 NULL('\0')은 `포함되지 않은 길이`

ex05에서 ft_putchar 함수를 문자열이 끝날 때까지 while문을 돌린 것 처럼<br>
반복문을 진행하면서 카운트를 함께 해줌으로써 문자열의 길이를 측정할 수 있다


## ex07 
### 📌 void	ft_rev_int_tab(int *tab, int size);

매개변수 포인터로 배열의 주소를 연결한 뒤 값을 거꾸로 바꾸는 함수

- 값들이 홀수일 경우 가운데 값은 그대로 유지되므로 홀, 짝 무관하게 사고하면 된다

## ex08 
### 📌 void	ft_sort_int_tab(int *tab, int size);

매개변수 포인터로 배열의 주소를 연결한 뒤 값을 정렬하는 함수

- [정렬 참고 자료](https://github.com/Ejaeda/C_lang/tree/master/C-DataStructure/Ch10.Sorting)
