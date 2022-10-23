# C08

### [ft_h](#ex00)
### [ft_boolean.h](#ex01)
### [ft_abs.h](#ex02)
### [ft_point.h](#ex03)
### [ft_strs_to_tab](#ex04) 🚨
### [ft_show_tab](#ex05) 🚨


## ex00 
### ft_h;
>   헤더파일 만들기

헤더파일은 `선언`<br>
소스파일은 `정리`<br>
형식
```.c
#ifndef FT_H              // 만약 FT_H(대문자, '.' 대신 '_')가 not def 라면
# define FT_H             // FT_H(ft.h)를 아래와 같이 정의하겠다

#endif                    // 정의 끝
```
세미콜론(;)은 define에는 붙이지 않고, typedef에는 붙인다 

## ex01
### ft_boolean.h;
>   main 함수에서 입력받은 av의 개수가 짝, 홀수에 따라 다른 문자열 출력

1.  write 함수가 사용되었지만, 헤더파일이 선언되지 않았다<br>
2.  int를 반환하는 ft_is_even의 자료형이 t_bool 형이다<br>
3.  삼항연산자가 사용되었고 EVEN(nbr)이 무엇인지 적혀있지 않다
4.  숫자를 TRUE, FALSE로 대체하였다<br>
5.  문자열의 내용을 각각 EVEN_MSG, ODD_MSG로 대체하였다<br>
6.  main 함수가 정상적으로 종료될 때 반환하는 숫자 0을 SUCCESS로 대체하였다<br>

## ex02
### ft_abs.h;
>   절댓값을 반환하는 함수를 헤더파일로 선언

ft_abs를 삼항연산자를 활용하여 헤더파일에 선언하기
```.c
  #define ABS(Value) (Value < 0) ? -Value : Value
```

## ex03
### ft_point.h;

1.  main 함수에서 t_point라는 자료형이 쓰이고 있다
2.  point->x, point->y를 통해 구조체임을 알 수 있다
3.  따라서 t_point는 구조체 변수가 typedef된 변수다

## ex04
### struct s_stock_str* ft_strs_to_tab;
>  argv로 받은 문자열을 원본, 복사본, 원본크기로 나누어 보관하는 함수

'.'와 '->'를 헷갈리지 말자<br>

구조체 관련 핵심
1.  구조체를 main함수 위에 적어주는 것은 변수를 선언한 것이 아니라 자료의 구성을 열거한 것
2.  멤버 접근연산 (.)
3.  구조체 멤버 접근 연산의 결과는 ㅣ-value
4.  구조체 변수의 주소를 저장하는 포인터 변수를 이용해 접근할 수 있다
5.  이때 멤버 접근연산 (->)   //  '->' == '*' + '.'
6.  다시말해 값으로 접근할 때는 '.', 포인터로 접근할 때는 '->'

```.c
  // 이차원 배열을 생각하자
  t_stock_str   *array    // 구조체 포인터 변수 선언
  
  // array는 이차원 배열이라고 봐야하므로 이를 이용해 멤버에 접근하려면
  array[idx].str = av[idx];
  
  // 포인터는 연결의 의미! 왜 포인터로 선언하는지, 왜 값으로 접근하는지 생각하자
```

실수하지 말 것들
-   malloc 이후에는 습관적으로 오류 확인하기
```.c
  dup = (자료형)malloc(sizeof() ... );
  if (!dub)
    return 0;
```

-   while문 돌릴때 인덱스 -1로 출발한다면 while 조건문 잘생각하기
```.c
  idx = -1;
  while (str[++idx])
  {
    ...
  }
  str[idx] = 0;       // 바로 NULL자리이다. while문에서 최종 더해져서 나온다
```

## ex05
### void  ft_show_tab(struct s_stock_str* par);
>  구조체의 부분을 꺼내 출력하는 함수

1.  size를 출력하기 위해 ft_putnbr 필요
2.  str를 출력하기 위해 ft_putstr 필요

main 함수는 어떻게 만들어야 할까
```.c
#include "../ex04/ft_strs_to_tab.c"     // 파일을 넘나들며 선언 가능!

int main(int ac, char **av)
{
   ft_show_tab(ft_strs_to_tab(ac, av));
}
```

주의하자! 🚨
- putnbr은 char을 출력하므로 매개변수를 int형으로 받지만 char 출력을 위해 `nb + '0'`
- int 형 최소값은 -2147483648
