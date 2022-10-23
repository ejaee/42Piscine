# C07

### [ft_strdup](#ex00)
### [ft_range](#ex01)
### [ft_ultimate_range](#ex02)
### [ft_strjoin](#ex03)
### [ft_convert_base](#ex04) 🚨
### [ft_split](#ex05) 🚨


## ex00 
### ft_strdup;

- 정의

    malloc을 통한 메모리 동적할당
-----
- 역할

    1. 복사 하고자 하는 문자열 크기 +1 만큼 동적할당 후
    > NULL 자리 확보

    2. src를 dup에 복사

    3. 복제된 dup의 주소를 리턴
    > 동적할당이 제대로 안됐을 때 if (!dup) check

    ```.c
    #include <stdlib.h>

    int* buffer;

    buffer = (int*)malloc(sizeof(int) * (size + 1);
    ```


## ex01 
### ft_range;

- 정의

    int형 최소, 최대값을 인자로 받아 개수를 고려하여 int 배열 생성 및 값 저장
-----
- 🚨 실수

    malloc
    ```.c
    //  dup = malloc(sizeof(int * size) + 1);
        dup = malloc(sizeof(int) * (size + 1));
    ```
    > NULL 도 자료형의 크기만큼 자리가 필요하다

    해당 문제에서는 len의 크기내에 NULL 자리까지 충당 가능<br>
    ```.c
        dup = malloc(sizeof(int) * len);
    ```

    문자열 입, 출력 시 주의사항
    ```.c
    
        idx = -1;
    //  while (buf[++idx])
        while (idx < len)
            buf[idx] = min + idx;
        buf[idx] = 0
    ```
    > 문자열 값이 0이라면 해당 반복문은 바로 종료

    malloc은 초기화가 되지 않는 것으로 알고 있지만 문제가 발생할 수 있다
    > 초기화 동적할당 `calloc`

    int형 배열에서 되도록이면 while 조건문으로 배열의 값을 넣지말자





## ex02 
### ft_ultimate_range;

> ex01에서 main 내에 출력을 위해 별도의 size를 측정했었다

이를 개선하는 함수

-----
- 정의

    malloc을 통한 메모리 동적할당
-----
- 역할

    1. 복제와 동시에 size를 함께 가져옴

    2. ** range를 통해 main함수와 연결

    3. 복제된 dup의 size를 리턴
    > 동적할당이 제대로 안됐을 때 if (!dup) check

    ```.c
    (int** range, int min, int max)

    int main()
    {
        int *buf;   

     ft_ultimate_range(&buf, 2, 100);
     // int **range = &buf;
    } 
    ```
    int** 형은 1차원 포인터의 주소를 담는다 
    > int *buf 의 포인터 주소는 &buf

-----
-   🚨 로직 

    1. 매개변수 2차 포인터와 main 1차 포인터 연결

        `int **range = &buf;`
        > 주소로 연결되었으므로 값에 영향을 끼침

    2. func내에 1차 포인터 생성 -> 복제
    
        `int *dup;`

    3. *range = dup;로 할당 값 전달
    
        `*range = buf`
        > 즉 dup = buf;
   
## ex03 
### ft_strjoin;

2차원 포인터로 확대

-----
- 정의

    char **strs이 가리키는 모든 문자열을 sep으로 구분하여 연결하는 함수

-----
- 역할

    ```.c
    char **strs;
    char *str[0] = "one"
    char *str[1] = "two"
    char *str[2] = "three"
    char *sep = " @ "

    ft_strjoin() ->  "one @ two @ three"
    ```

-----
-   🚨 로직 

    1. 총 담아야하는 길이 구해서 malloc

        strs의 길이 구하기
        > size 만큼 반복문을 통해 strs[idx++] 로 접근하며 측정

        sep의 문자열 길이 구하기
        >  sep의 길이는 동일하므로 (size - 1)개 더해주기

    2. strcat을 활용해 이어붙이기

-----

-   🚨 실수

    res[idx] = 0; 중복
    > ft_strcat에서 마지막에 NULL을 입력하는데 strjoin에서 중복

    곂치지 않도록 신경쓰자

-----

-   주의

    🚨 1) 
    
    : 49

    size가 0이면 free할 수 있는 빈 문자열이 있어야 한다 즉,<br>
    > size가 0이 더라도 동적할당이 되어야 한다

    ```.c
    if (size == 0)  >>  (size <= 0)
    buf = malloc(sizeof(char) * 1);   // NULL자리만 '1' 만들어준다
    *buf = 0;                         // 안넣어도 된다
    return (buf);
    ```

    🚨 2)
    
    size가 char형 이므로 음수일때도 고려해주어야 한다


    🚨 3)

    : 56

    >   동적 할당이 제대로 이루어지지 않은 경우
    ```.c
    buf = malloc(sizeof(char)*total_strlen(size, strs, sep));
        if (!buf)
            return (0);
    ```

    🚨 4)

    char* ft_strcat : 40

    >   dest가 모두 입력되면 반드시 NULL을 채울 것

    >   total_strlen에서 sum_len에 NULL자리 1을 더하기 때문

## ex04 
### ft_convert_base;


1.  문자열 nbr을 atoi의 규칙대로 base_from 을 반영하여 숫자화 후 base_from에 맞게 int 저장
    > `ft_atoi_base`

    🚨 int 형은 무조건 10진법!! -> 문자열 nbr 각각의 문자들이 위치하는 base_from의 인덱스 값을 그대로 int에 넣어주면 된다
    ```.c
    res = res * from_len + (is_exist(nbr[idx], base_from));
    ```
    > is_exist()는 base_from 내에서 nbr[idx] 문자의 위치 idx를 리턴


2.  int 값을 base_to에 맞게 변환
    >`ft_itoa_base`

    🚨 base에 있는지 없는지 체크할 필요 없다
    >int 형을 base의 idx라고 생각하고 하나씩 뽑아온다고 생각

    stack에 넣은 후 res에 담기
    ```.c
    idx = 0;
    while (nbr >= 0)
    {
        stack[idx++] = base[nbr % len];
        nbr /= len;
        if (nbr == 0)
            break ;
    }
    while (j < size)
        res[j++] = stack[--idx];
    res[j] = '\0';
    ```

    itoa에서 헷갈리기 쉬운 while문
    ```.c
    while (num >= 0)
    {
        num /= len;
        cnt++;
        if (num == 0)
            break;
    }
    ```
    > num == 0일때 cnt 한번은 되어야 하므로 포함시켜야 한다



-   베이스 체크
    
    1.  공백 없음
    2.  '+', '-' 없음
    3.  중복 문자 없음
    4.  1진법 없음 🚨

int ft_atoi_base(char *nbr, char (base_from))<br>
>   char 문자열을 base_from에 맞게 int화

```.c
    ex)
    nbr = "abc";
    base_from = "012ab"
    ab만 숫자 c는 문자에 해당
    ab는 숫자이므로 자릿수가 적용됨!

    a를 인덱스 값으로 변환!!
    rst = a'idx * base_type + b'idx

    🚨 rst 는 10진법이다!!!! 🚨
```
> 두 base의 길이를 따로 구하지말고 점검하는 과정에서 바로 가져오면 편하다

## ex05 
### ft_split
>   첫번째 인자를 두번째 인자로 나누어 2차원 배열에 각각 저장하는 함수

1.  몇개의 row가 있는지 알아야 하므로 word의 갯수가 필요하다 (count_word)
```.c   🚨
    //  word 갯수 구하는 방식
    while (*str)                            // 문자열 전체 도는동안
    {
        while (*str && is_charset(str))     // 구분자 라면 str위치 이동
            str ++;
        if (*str && !is_charset(str))       // 구분자가 끝났을테니 그 다음이 무언가 있으면 단어의 시작
        {
            cnt ++;
            while (*str && !is_charset(str))// 단어의 시작점을 카운팅 했으니 단어 넘기기
                str++;
        }
    }
```
2.  word의 갯수만큼 malloc 할당해준다
```.c
    char    **dest;     // word를 각 row에 저장하는 이차원 배열
    dest = (char **)malloc(sizeof(char*)*count_word + 1);
    //  char ** 이차원배열에서 각 열(char *)의 크기를 word만큼 요구!
```
3.  각 row에 word 저장하는 방법 🚨
    -   우선 word 마다 각각 길이가 다르므로 각각의 동적할당이 필요
    -   word의 사이즈를 구했을 거니 ft_strncpy를 활용
    -   어떻게 word의 사이즈를 구할 것인가?  🚨
```.c
    char    *from;          // 단어의 시작점을 찍는 역할!!!! 🚨
    idx = -1;
    while (++ idx < count_word)
    {
        if (*str && !*is_charset)   // *is_charset 할 수도 있지만 더 깔끔! 🚨
        {
            from = str;
            while (*str && *is_charset)
                str ++;             //  공백까지 이동한다는게 카운트를 하는 모션!! 🚨
            dest[idx] = (char *)malloc(sizeof(char) * (str - from + 1));
            ft_strncpy(dest[idx], from, str - from);
        }
        str ++;
    }
```

주의할 점 🚨
-   arr의 각 idx에 단어를 입력하고 마지막 NULL을 입력할 때
```.c
    // *arr[dnt_word] = '\0'; 이 아니다
    arr[cnt_word]
```

-   ft_strncpy의 인자로 (dest[idx], from, str - from) 헷갈리지 말자
```.c
    //  특히 from은 word의 시작점, str은 word counting을 위해 사용
    //  from을 넘겨야 wordm이 입력이 가능
```




