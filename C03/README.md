# 📖 C03

📖 ***`두 개의 문자열`을 다루는 함수를 직접 만들어 본다***

-----

### [ft_strcmp](#ex00)
### [ft_strncmp](#ex01)
### [ft_strcat](#ex02)
### [ft_strncat](#ex03)
### [ft_strstr](#ex04)
### [ft_strlcat](#ex05)

## ex00 
### 📌 int     ft_strcmp(char *s1, char *s2);

두개의 문자열 s1와 s2를 `비교`

-   두개의 문자열 s1와 s2가 `모두 같을 경우`
    >   -   `return (0)`; (s1 == s2)

-   두개의 문자열 s1와 s2를 비교하다가 `다른 문자가 나왔을 경우`
    >   해당 문자들의 아스키 코드 값에 따라 return값이 달라짐
    >   -   `return (+)`; (s1 > s2)
    >   -   `return (-)`; (s1 < s2)

-   실수하기 쉬운 것
    ```.c
    while (*s1 && *s2 && (*s1 == *s2))
    ```

## ex01 
### 📌 int     ft_strncmp(char *s1, char *s2, unsigned int n);

두개의 문자열 s1와 s2를 `n 크기 만큼 비교`
-   매개변수 n은 unsigned int(size_t) 형 이므로 `0보다 큰 값이 와야한다`

n의 크기가 두 문자열의 길이 둘중 하나라도 `클 경우` 전체를 비교
-   str1 : 5, str2 : 10, n = 100인 경우 `str1이 길이만큼 비교`<br>

`return` 은 strcmp와 동일 


## ex02 
### 📌 chat    *ft_strcat(char *dest, char *src);
문자열 dest 뒤에 문자열 src을 이어붙이는, `문자열 연결함수`
-   dest의 길이는 src와 합쳐져도 남을 정도로 충분히 길어야 한다
-   dest 의 문자열 끝에 있는 '\0'을 없애고 src를 붙여넣는다
-   마지막에 붙여 넣은 문자열 끝에만 '\0'를 붙인다


## ex03 
### 📌 chat    *ft_strncat(char *dest, char *src, unsigned int nb);
문자열 dest 뒤에 문자열 src 중 문자 n번째 까지 이어붙버이는 함수

-   n개의 문자만 잘라서 넣어도 합친 문자열 끝에는 '\0'를 붙인다

-   while (src[idx_s] && idx_s < nb)로, src[idx_s]를 붙이는 이유
    > src가 n보다 작은데 n만큼 붙여넣다보면 src의 NULL이 들어가고

    > while문이 끝나고 들어가는 NULL이 또 들어가기 때문


## ex04
### 📌 char    *ft_strstr(char *str, char *to_find);

문자열 str 안에서 문자열 `to_find 를 찾는 함수`

-   to_find와 같은 내용을 찾았다면 str에서 to_find가 시작하는 주소값을 반환
    >   strcpy의 매개변수에 `str에서 바꿀 문자열의 위치를 전달`하는데에 주로 쓰이므로 to_find 시작 위치를 전달

-   일치하는 문자열을 찾지 못하면 null pointer를 반환
    >   return (0);
    
    >   찾지 못했으니까 맨 뒤에 이어 붙이기 위헤 0이라고 생각하기

-   예외처리
    >   to_find가 빈 문자열 ("")을 가리키고 있는 경우
    ```.c
    while (!*to_find)
        return (str);
    ```

실수할 수 있는 포인트

-   잘못된 코드
    ```.c
    while (str[idx + jdx] == to_find[jdx])
    {
        if (!to_find[jdx])
            return (&str[idx]);
        jdx++:
    }
    ```
    > jdx++를 통해 to_find가 NULL이 되었는데 반복문에서 비교하고 있음

-   올바른 코드
    ```.c
    while (str[idx + jdx] == to_find[jdx])
    {
        jdx++:
        if (!to_find[jdx])
            return (&str[idx]);
    }
    ```

## ex05 
### 📌 unsigned int    ft_strlcat(char *dest, char *src, unsigned int size);

dest 뒤에 src를 이어 붙이는데, `마지막에 NULL을 보장`하는 함수
-   strlcpy와 용도가 같다

-   매개변수 size의 크기는 NULL 자리가 `포함된` 크기이다
    >   size = dest_len + src_len + `1`(NULL);

-   size보다 dest의 길이가 작을 경우
    >   dest + src를 size - 1만큼 이어 붙인다

    >   그리고 size 번째에 NULL을 저장

    >   NULL을 제외한 문자열 길이를 반환
    ```.c
    return (dest_len + src_len);
    ```
    🚨 src를 모두 붙여넣지 못하더라도 src의 전체 길이를 더해서 리턴

-   size보다 dest 길이가 크거나 같을 경우
    >   src를 이어붙이지 못한다
    
    >   src의 길이와 size를 더한 값을 반환

    ```.c
    return (src_len + size);
    ```    

실수하기 쉬운 부분

    ```.c
    while(*src && dest_len + cnt < size -1)
    // 반드시 src의 값이 0인지 확인하기
    ```






