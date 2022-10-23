# 📖 C00

📖 ***오직 write 함수만을 사용해 `문자` 출력을 연습한다***

-----

write() by #include <unistd.h>

- 원형

    ssize_t write (int fd, const void *buf, size_t nbytes);
    -   `int fd` : 1
    >   0 == 표준 입력 (STDIN_FILENO)

    >   1 == 표준 출력 (STDOUT_FILENO)

    >   2 == 표준 에러 ( STDERR_FILENO)

    -   `void *buf` : 파일에 쓰기를 할 내용을 담은 버퍼
    -   `size_t n` : 쓰기할 바이트 개수

- 반환

    ssize_t 쓰기에 성공했다면 쓰기한 바이트 개수를, 실패했다면 -1을 반환

### [ft_putchar](#ex00)
### [ft_print_alphabet](#ex01)
### [ft_print_reverse_alphabet](#ex02)
### [ft_print_number](#ex03)
### [ft_is_negative](#ex04)
### [ft_print_comb](#ex05)
### [ft_print_comb2](#ex06)
### [ft_putnbr](#ex07)
### [ft_print_combn](#ex08)

-----

## ex00 
### 📌 void    ft_putchar(char c);

`문자`를 출력하는 함수

## ex01 
### 📌 void    ft_print_alphabet(void);

`문자` a ~ z를 출력하는 함수

## ex02 
### 📌 void    ft_print_reverse_alphabet(void);

`문자` z ~ a를 출력하는 함수

## ex03 
### 📌 void    ft_print_number(void);

`문자` 0 ~ 9를 출력하는 함수

## ex04
###  📌 void    ft_is_negative(int n);

음수일 경우 `문자` N을, 0 또는 양수이면 `문자` P를 출력하는 함수

## ex05 
### 📌 void    ft_print_comb(void)

서로 다른 숫자를 오름차순의 순서로 조합한 `세` 자릿수 숫자를 오름차순으로 출력하는 함수

```
012, 012, ..., 023, ..., , 789$
```
> dfs 활용 해보기

## ex06
### 📌 void    ft_print_comb2(void)

00과 99 사이의 `두` 자릿수 숫자를 오름차순으로 출력하는 함수

```
00 01, 00 02, ..., 00 99, 01 02, ..., , 97 99, 98 99$
```

-   `ft_putchar()` 함수를 만들지 않으면, 별도의 char형 변수를 만들면서 코드가 길어진다
    
    (nbr / 10)의 int 값에 + '0'을 더하여 `char 인자`로 전달하기

## ex07
### 📌 void    ft_putnbr(int nb)

`int형 숫자`를 char형 출력 함수인 `write`로 출력하는 함수

## ex08
### 📌 void    ft_print_combn(int n)

서로 다른 숫자를 오름차순의 순서로 조합한 `n` 자릿수 숫자를 오름차순으로 출력하는 함수

> dfs 활용 해보기


