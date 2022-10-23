# 📖 C04

📖 ***int 형과 char 형의 교차 변환을 연습한다***

-----

- `int`형 숫자를 `char`형 으로 변환하여 출력
- `char`형 으로 입력된 숫자를 `int`형 으로 변환

### [ft_strlen](#ex00)
### [ft_putstr](#ex01)
### [ft_putnbr](#ex02)
### [ft_atoi](#ex03)
### [ft_putnbr_base](#ex04)
### [ft_atoi_base](#ex05) 🚨

-----

## ex00 
### 📌 int     ft_strlen(char *str);
문자열 길이를 구하는 함수
-   return (NULL을 제외한 str의 길이);

## ex01 
### 📌 void     ft_putstr(char *str);
문자열을 표시하는 함수
-   putchar 함수를 사용

## ex02 
### 📌 void    *ft_putnbr(int nb);
int형 변수 내 가능한 모든 표시하는 함수
-   int 형 변수의 범위는 `-2147483638 ~ 2147483647`
>   int 형 함수를 문자 출력 함수 putchar로 출력 (int + '0' == print char)
-   부호를 예외처리 한 후 발생하는 int 형 최소값 2147483648의 예외처리 필요
>   write (1, "2147483648", 10);
>>  위 둘을 합쳐서 write (1, "-2147483648", 11);

## ex03 
### 📌 int    *ft_atoi(char *str);
문자열에 저장된 정수를 정수로 출력하는 함수 (Ascii TO Integer)
-   공백은 무시 (9 ~ 13, 32)
-   부호는 음수의 갯수가 짝수 시 '+', 홀수 시 '-'
-   출력 방법은 putchar의 반복이 아닌 숫자들을 변수에 저장하고 한번에 출력
>   rst = rst * 10 + (srt[idx] - '0');
-   return
>   ex1)    "         +--+ab42"     return (0);
>   ex2)    "         +--+42ab"     return (42);
>   ex3)    "         +--+42"       return (42);

```.c
atoi 함수의 사용 목적

scanf 로 정수를 입력 받을 때 문자를 입력하면 오류가 발생하는 문제를 피할 수 있다

int i;
char input[10];

scanf("%s", input);
i = atoi(input);

```

## ex04
### 📌 void    ft_putnbr_base(int nbr, char *base);
첫 매개변수 nbr을 base기수를 사용하여 표시하는 함수<br>
1.  nbr을 long long 자료형으로 옮기기
-   int 형으로 nbr이 주어짐
-   음수 표현이 가능해야 허기 때문
>   -2147483648을 `-` 와 `2147483648`로 분리하기<br>
>   `long long` 자료형은 2147483648을 담을 수 있음
2.  문자열의 예외조건을 체크하는 함수 필요
-   주의사항
>   이중 while문을 사용할 때 변수 설정을 제대로 하지 않아 시간이 오래 걸렸음
```.c
    int idx = 0;
    int idx2;
    while (str[idx])
    {
        idx2 = idx + 1;
        while (str[idx2])
        {   
            idx2++;
        }
        idx++;
    }
```
3.  base 문자열의 size는 `size진법`이 되며 기수변환이 필요
-   10진수 17을 16진수로 바꾸기 위해서는 16보다 작아질 때 까지 몫과 나머지로 나눈다
>   size보다 nbr이 작을 경우 출력 함수에 문자열 인덱스로 전달
```.c
putchar(base[nbr])
```
>   size보다 클 경우 재귀함수 사용
```.c
putstr(nbr / size, base);
putstr(nbr % size, base);
```

## ex05 
### 📌 void    ft_atoi_base(char *str, char *base);
atoi 함수와 putnbr_base를 합친 함수

-   check_base 하면서 len 구하기

    check list
    -   공백 확인
    -   부호 확인
    -   중복 문자 확인
    -   2진수 미만 확인

-   atoi 는 문자를 숫자로 변환

    즉, `인덱스`가 숫자가 된다
    ```.c
    int is_base(char c, char *base, int len)
    {
        int idx;

        idx = -1;
        while (++idx < len)
    {
        if (c == base[idx])
            return (idx);
    }
        return (-1);
    }
    
    ...

    res = res * len + is_base(*str, base, len);
    ```
(4.5 확인 후 수정)
2.  ft_putnbr_base(int nbr, char *base)의 방식으로 int 표현으로 `변환`
-   출력 void가 아닌 변환 int 이라는 점이 ex04와의 차이점
