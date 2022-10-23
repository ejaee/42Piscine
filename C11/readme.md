# C11

### [ft_foreach](#ex00)
### [ft_map](#ex01)
### [ft_any](#ex02)
### [ft_count_if](#ex03)
### [ft_is_sort](#ex04)
### [do-op](#ex05)
### [ft_sort_string_tab](#ex06)
### [ft_advanced_sort_string_tab](#ex07)

## ex00 
### void    ft_foreach(int* tab. int length, void(*f)());
>   배열의 모든 요소에 함수를 적용시키기
#### [문제풀이로 넘기기](#문제풀이)

### 함수 포인터
기존의 포인터
-   변수 이름 대신 변수 `주소를 사용`하여 접근
-   변수 외에도 이름을 사용하는 문법 : `함수`

명령문들도 메모리에 저장되어 있기 때문에 각 `명령문`마다 주소를 가진다
-   데이터 세그먼트 (문자열 상수목록, 전역변수, static 전역 변수)
-   스택 세그먼트 (동적 메모리 할당(Heap) 지역변수(Stack))
-   `코드 세그먼트` (기계어 `명령문`)
>   메모리의 주소 값을 알고 있다면 당연히 포인터를 사용할 수 있다

함수 포인터
>   코드 세그먼트에 있는 명령문의 주소를 저장해서 포인터로 사용하는 방법
-   특정 함수를 구성하는 시작 명령의 위치를 가리키는 포인터
-   함수 포인터 사용 -> 함수 호출하여 실행

일반적 함수 호출
```.c
    int sum(int a, int b)   // 3개의 명령문으로 구성
    {
        int result = 0;     // sum 함수의 시작 주소
        result = a + b;
        return result;
    }

    int result = sum(2,3)   // 함수 호출
```
sum 함수의 시작 주소는 중복 가능성이 크므로 적합하지 않음<br>
->  함수의 이름 앞에 &를 적으면 함수에 포함되는 첫번째 명령문의 주소 값을 얻음
```.c
    &sum;   // &를 적지 않아도 가능
```

### 함수 포인터 사용
함수의 주소 값을 저장할 수 있는 포인터가 필요
-   함수의 원형을 사용하여 포인터를 선언한다
>   함수 원형을 알아야 함수를 호출할 때 스택 프레임을 구성할 수 있다
```.c
    // int sum의 함수원형   ->  int sum(int, int)

    int (*p)(int, int);
    p = &sum;       //  p = sum;

    int result = (*p)(2, 3);
    // (*p)(2, 3) == sum(2, 3)
```

### 함수 포인터 사용 이유
같은 형식의 함수를 그룹으로 묶을 수 있다
```.c
    int sum(int a, int b){
        return a + b;
    }

    int sub(int a, int b){
        return a - b;
    }

    int mul(int a, int b){
        return a * b;
    }

    int (*p[3])(int, int) = {sum, sub, mul};

    int result[3], i;

    for(i = 0; i < 3; i++) result[i] = (*p[i])(8, 2)
```

### typedef 활용
```.c
    typedef int (*OP_TYPE)(int, int);
    OP_TYPE p[4] = {&sum, &sub, &mul};
```

#### 문제풀이

1.  주어지는 int형 배열의 모든 요소에 `함수를 적용하는` 함수를 작성
2.  void    함수를 적용하는 함수(배열, 배열의 길이, 함수원형)

예시)
```.c
    //ft_putnbr 함수를 적용하는 함수

    void    ft_foreach(int *tab, int length, void(*f)(int))

    int main(){

        ft_foreach(tab, 1337, &ft_putnbr);

    }
```
>   tab 배열의 1337개를 ft_putnbr 적용하기

함수 호출 시 (*f)tab[idx] == (f)tab[idx] 상관없다

## ex01
### int*    ft_map(int* tab, int length, int(*f)(int));
>   배열의 모든 요소에 함수를 적용하고 각 반환 값의 배열을 반환

1.  각 배열 요소마다 함수 적용
2.  배열 갯수만큼 동적할당 이후 함수 적용된 리턴값을 부여

## ex02
### int    ft_ft_any(char** tab, int(*f)(int));
>   이차원 배열을 받는데 신경쓰기

```.c
    int idx;

    idx = -1;
    while (tab[idx])
    {
        if (f(tab[idx]))
            return 1;
    }
```

## ex03
### int    ft_count_if(char** tab, int length, int(* f)(char*));
>   while 돌리면서 조건 적합 시 cnt++

## ex04
### int ft_is_sort(int* tab, int length, int(*f)(int, int));
>   정렬 확인하기

1.  오름차순 경우
2.  내림차순 경우

각각 조건마다 카운팅 한 후 최종 idx 값과 비교

## ex05
### do-op
>   연산자를 확인하고 그에 맞는 함수를 가져와 연산하기

1.  input 3개
2.  input 1,3 문자열을 atoi를 통해 int 만들기
3.  함수를 가리키는 포인터의 배열에서 연산자 받아쓰기
4.  결과를 char형으로 출력해야 하므로 putnbr

```.c
   void (*f[5])(int a, int b);

   f[0] = func_name;
   f[1] = func_name;
   
   ...

    f[idx](a, b);       // idx에 맞는 함수 실행
```

## ex06
### ft_sort_string_tab
>   cmp와 swap을 통해 문자열 정렬

2차원 특성 잘 고려하기

## ex07
### void    ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *,     char *))
>   cmp를 함수포인터로 받기

함수포인터 안쓸 때 (ex06)
```.c
void    ft_advanced_sort_string_tab(char **tab)
{
    if (ft_strcmp(tab[idx], tab[jdx]) > 0);

}```
함수포인터 쓸 때 (ex07)
```.c
void    ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *,     char *))
{
    if (*cmp)(tab[idx], tab[jdx]) > 0);
}

/*
int ft_strcmp(char *s1, char *s2)   // 함수 정의
{
    ...
}

int main()
{
    ft_advanced_sort_string_tab(arr, ft_strcmp) // 함수 전달
}
*/
```