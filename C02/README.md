# 📖 C02

📖 ***포인터를 활용해 `문자열`을 다루는 연습을 한다***

-----

### [ft_strcpy](#ex00)
### [ft_strncpy](#ex01)
### [ft_str_is_alpha](#ex02)
### [ft_str_is_nummeric](#ex03)
### [ft_str_is_lowercase](#ex04)
### [ft_str_is_uppercase](#ex05)
### [ft_str_is_printable](#ex06)
### [ft_strupcase](#ex07)
### [ft_strlowcase](#ex08)
### [ft_strcapitalize](#ex09)
### [ft_strlcpy](#ex10)
### [ft_putstr_non_printable](#ex11)
### [ft_print_momory](#ex12)🚨

-----

## ex00 
### 📌 char    *ft_strcpy(char *dest, char *src);

`src의 배열`을 `dest에 복사`하는 함수

-   복사를 마치고 반복문을 벗어나면 NULL값 반드시 입력
-   return (dest);
    >   리턴값을 주소(배열의 이름)로 전달

    >   `그러나,` src가 dest 문자열 공간보다 많다면 overflow 발생

    >   `이를 보완` -> ft_strncpy (ex01)

## ex01 
### 📌 ft_strncpy(char *dest, char *src, unsigned int n);

src의 배열을 dest에 `n만큼` 복사하는 함수

-   n이 src의 길이보다 `작을 경우`, 
    dest에 `NULL 문자(\0)는 추가되지 않음`
-   n이 src의 길이와 `같거나 클` 경우, 
    dest에는 n까지 남은 자리를 `NULL 문자(\0)로 채워짐`
-   return (dest);
    > n의 값이 음수가 되면 버퍼 오버플로우(size_t는 unsigned형으로 선언) 발생한다
    
    > 때문에 자료형이 `size_t`(typedef unsigned int)형 

    > `그러나,`  복사할 길이(n) < src의 길이 경우, 문자열 끝에 ‘\0’문자가 붙지 않기 때문에 위험함

    > `이를 보완` : ft_strlcpy (ex10)

    > 주의점 : `unsigned int형` n과, 비교하는 idx의 자료형을 맞출 것


## ex02 
### 📌 int     ft_str_is_alpha(char *str);

- `ASCII` 대문자 알파벳 = 65 ~ 90
- `ASCII` 소문자 알파벳 = 97 ~ 122

## ex03 
### 📌 int     ft_str_is_nummeric(char *str);

- `ASCII` 숫자 = 48 ~ 57

## ex04 
### 📌 int     ft_str_is_lowercase(char *str);

- `ASCII` 소문자 알파벳 = 97 ~ 122

## ex05 
### 📌 int     ft_str_is_uppercase(char *str);

- `ASCII` 대문자 알파벳 = 65 ~ 90

## ex06 
### 📌 int     ft_str_is_printable(char *str);

- `ASCII` 출력 가능한 문자 = 32 ~ 126
    >   공백 문자 1개 ( 32 )

    >   숫자 10개 ( 48 ~ 57 )

    >   영문 알파벳 대+소 문자 52개 ( 65 ~ 90, 97 ~ 122 )

    >   특수 문자 32개 ( 33 ~ 47, 58 ~ 64, 91 ~ 96, 123 ~ 126 )

## ex07 
### 📌 char    *ft_strupcase(char  *str);

대문자 = 소문자 + 32

## ex08 
### 📌 char    *ft_strlowercase(char  *str);

소문자 = 대문자 - 32

> 포인터로 내용을 바꿀 수 있는가?

## ex09 
### 📌 char    * ft_strcapitalize(char  *str);

문자열에서 단어를 식별하고 단어의 첫 알파벳을 대문자로, 이외 알파벳을 소문자로 변경
- 단어 = (대, 소)문자, 숫자
- 특수문자는 단어에 포함되지 않는다

logic
```.c
while(str)                                // 문자열 전체 반복문
{
    if(문자가 대문자 or 소문자 or 숫자)         // 단어 첫 진입
    {
        if(소문자일 경우)                    // 첫 단어는 대문자
            대문자로 변경;
        str++;
        while(문자가 대문자 or 소문자 or 숫자)  // 단어 끝까지 확인 반복문
        {
            if(대문자일 경우)                // 두번째부터는 소문자
                소문자로 변경;
            str++;
        }                                // 단어 종료
    }
    str++;                               // 단어를 찾을때 까지 더하기
}
```

## ex10 
### 📌 unsigned int ft_strlcpy(char *dest, char *src, unsigned int  size);

src의 배열을 dest 배열에 복사하는데, `dest의 마지막에 NULL을 보장`하는 함수

- size보다 src의 길이가 클 경우 -> `src의 NULL이 저장`

- size보다 src의 길이가 작을 경우 -> size - 1만큼 복사 후 NULL 저장

- 저장하려고 했던 src의 길이를 리턴

    왜 ?
    - 
    

- 예외 처리

   size가 0일 경우 -1만큼 복사가 되므로 예외처리 필요
    ```.c
    if(size == 0)  
        return (src_len);
    ```

- 신경 써야하는 부분

    - src를 모두 복사 하였음에도 size - 1값이 남아있다면 무의미한 복사의 반복이 발생 
    
        >  추가 조건 : size - 1 값이 남았더라도 복사를 완료했다면 종료
        ```.c
        while ( src[idx] && idx < size - 1 )
        ```


    - `unsigned int형` n과 비교하는 idx는 같은 자료형이어야 한다


## ex11
### 📌 ft_putstr_non_printable(char  *str)

문자열을 출력하는데, 출력할 수 없는 문자는 `\hex` 로 표시하는 함수

<details>
    <summary> logic </summary>

 

16진수 (0123456789abcdef)를 담은 배열을 만든다
   
출력 불가한 숫자를 매개변수로 받아 16으로 나눈 몫과 나머지를 활용하여 출력한다
>   putchar(hexa[c/16]);

>   putchar(hexa[c%16]);

ASCII 코드는 256개(0 ~ 255)이므로 c/16과 c%16 한번씩 만으로 16진수로 변환이 가능하다
> 최대 ASCII 코드 `255를 16진수`로 하면 `FF`
</details>

- 🚨 주의할 점 🚨

    (범위0 ~ 255 를 가지는) `unsigned char 자료형`을 사용할 것
    >  16진수로 변환하는 함수의 매개변수는 ASCII 코드의 숫자를 받으므로
    
    >  char를 사용할 시 범위에 문제가 발생함(ascii 범위 0 ~ 127)

# 📖 memory

<details>
    <summary> 개념 확인 </summary>

## 📖 메모리의 이해

### 📌 메모리

1. 사용자가 운영체제(OS)에 실행을 요청

2. 운영체제가 보조기억장치(HDD)에서 프로그램의 정보를 읽어 메모리에 로드

3. CPU는 프로그램 코드를 가져다 메모리를 관리하고 명령문을 실행

    > 메모리 == Random Access Memory(RAM)

### 📌 메모리 구조

[메모리 사진]
- 코드 영역

    실행할 프로그램의 코드가 저장되는 영역
    > == 텍스트 영역
    
    > CPU는 코드 영역에서 저장된 명령을 하나씩 가져가서 처리

- 데이터 영역

    프로그램의 `전역 변수`와 `정적(static) 변수`가 저장되는 영역
    > 프로그램 시작과 함꼐 할당, 
    
    > 프로그램이 종료되면 소멸

- 힙 영역

    프로그래머가 직접 공간을 할당, 해제하는 메모리 공간

    > malloc, free

    > 메모리의 낮은 주소(위)에서 높은 주소(아래)의 방향으로 할당

- 스택 영역

    프로그램이 자동으로 사용하는 임시 메모리 영역
    > 함수 호출 시 `지역 변수`와 `매개 변수`가 저장

    > 함수 호출 완료되면 소멸

    > 메모리의 높은 주소(아래)에서 낮은 주소(위)의 방향으로 할당

    - 힙 영역과 스택 영역은 같은 free store을 함께 사용한다
    - 떄문에 한정된 공간을 초과할 경우 오버플로우가 발생한다
    > 힙 오버 프로우, 스택 오버 플로우

### 📌 32bit OS와 64bit OS 메모리
- 8 bit == 1 byte

    영어 한글자를 1byte에 저장
    >   컴퓨터는 숫자만을 메모리에 저장한다
    ```.vim
    'A' == 65 (by ascii) == 0x41 == 0100 0001

    (영어)    (아스키 숫자)    (16진수) (메모리 저장형태)
    ```

    2진수를 16진수로 바꾸기 위해서는 4bit씩 끊어서 보면된다
    ```.vim
    0100 0001 는

    0100 == 4, 0001 = 1

    즉, 0100 0001 == 0x41
    ```

-   32bit OS에서 주소의 범위

    주소는 16진수로 표기된다
    > 32bit OS에서 32개의 bit를 사용한다
    
    32bit, 즉 4byte 길이의 주소를 가진다(0 ~ 2^32)
    > bit, `32자리`의 `2진수`를 `16진수`로 바꾸면 `4개 묶음 8자리`이다 
    
    > 32bit OS의 `주소의 범위`는 `0x00000000 부터 0xFFFFFFFF`

    64bit OS의 경우 4개 묶음 16자리(0 ~ 2^64)
    > 0x0000000000000000 ~ 0xFFFFFFFFFFFFFFFF

    포인터가 OS에 따라 각각 4byte, 8byte 크기를 가지는 이유가 이 때문이다

</details>

-----

## ex12
### 📌 ft_print_momory(void *addr, unsigned int size)

배열에 저장된 문자열이 실제 메모리 주소에 어떻게 저장되었는지 보이는 함수

1.  16진법 메모리 주소를 64비트 운영체제 사이즈로 출력 + `:`
2.  16개의 방에 16진법 숫자로 저장된 문자를 2개마다 띄어쓰기로 구분하여 출력
3.  저장된 문자들의 내용을 출력

[메모리 형태]<br>
<img width="574" alt="스크린샷 2022-02-08 오전 10 16 54" src="https://user-images.githubusercontent.com/87407504/152899540-729f1def-c236-4fd3-b10c-2d6c20a4c2b8.png"><br>

-----

### 📖 문제를 통해 알 수 있는 것들

![IMG_6E842EDA7396-1](https://user-images.githubusercontent.com/87407504/150752091-45af5a86-a778-45e2-b31a-2490ca0b25a9.jpeg)<br>
1.  64비트 운영체제이다
>   16진법 주소가 16자리

2.  빅 엔디안 방식을 사용하고 있다

<img width="729" alt="스크린샷 2022-01-25 오전 6 02 03" src="https://user-images.githubusercontent.com/87407504/150864966-8698cfc2-29b2-4d4f-b3b1-f3571a4c4357.png"><br>

    빅 엔디안은 0x12345678을 저장할 경우
    
    |12|34|56|78| 으로 저장
    

- 리틀 에디안(intel x86계열 CPU가 사용하는 방식)의 경우
>   <img width="360" alt="스크린샷 2022-01-25 오전 6 03 31" src="https://user-images.githubusercontent.com/87407504/150864441-27d6429d-bccf-4cc2-b9ed-31f09bbcdd0e.png">

-----

<details>
    <summary> logic 확인 </summary>

📌 매개변수 void* addr 
-   주소를 가져온다
-   void *형

    void *형은 순수하게 메모리의 주소만 가지고 있는 포인터
    >   타입이 정해져 있지 않으므로 캐스팅을 통해 어떤 포인터로도 변화가 가능하다
    
    >   void 포인터 자체에는 주소만 저장되어 있으므로 그곳에 배열이 있을지 구조체가 있을 지 알 수 없다

    ```.c
    int a = 10;
    void* p = &a;
    *p = 20 //불가
    ```
    <img width="390" alt="스크린샷 2022-01-27 오후 10 55 10" src="https://user-images.githubusercontent.com/87407504/151372623-fca67ef2-2c9f-4aad-9d8d-f75598508d26.png"><br>
    
    캐스팅 (형 변환)
    ```.c
    int a = 10;
    void* p = &a;
    *(int*)p = 20;
    ```
    
    <img width="377" alt="스크린샷 2022-01-27 오후 10 55 39" src="https://user-images.githubusercontent.com/87407504/151372700-f65b3e66-a699-4e1c-9dfb-93fc216252f5.png"><br>


📌 매개변수 unsigned int size
-   `배열에 저장된 총 사이즈`를 가져온다

    음수가 올 수 없기 때문에 `unsigned int` 자료형 사용


### 📌 문제 핵심

- 주소를 출력하는 함수 `ft_putaddr`

    첫 주소는 0000000000000000 으로 시작

    호출마다 16번의 write를 사용
    >   idx = 0 와  jdx = 16 - idx를 활용

    >   주소를 (char*)addr에서 받아와 10진수를 16진수로 처리해아 한다
    
    >   호출마다 16번씩 number가 올라가므로 print_addr[16]에
    ```.c
    while (number)
    {
        print_addr[idx++] = number % 16;
        number /= 16;
    }
    ```
    >   이후에 idx-- 해주며 STACK 방법으로 출력
   
- 문자를 16진수로 출력하는 함수 `ft_puthexa`

    addr[number_idx]의 ascii 코드 10진수를 16진수로 변경
    ```.c
        write (1, &hexa[addr[number + idx] / 16], 1);
        write (1, &hexa[addr[number + idx] % 16], 1);
    ```

    두 문자 출력 후 공백 규칙 + 홀수로 끝날 수 있음을 고려
    ```.c
        if (idx % 2)
            write (1, " ", 1);
    ```
</details>
