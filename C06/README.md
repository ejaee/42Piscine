# C06

### [ft_print_program_name](#ex00)
### [ft_print_params](#ex01)
### [ft_rev_params](#ex02)
### [ft_sort_params](#ex03)


## ex00 
### ft_print_program_name;
>   프로그램의 이름을 출력하는 프로그램

프로그램을 작성하라<br>
== int main(int ac, char **av);<br>

```int argc```
-   main()함수에 전달되는 데이터의 갯수

```char *argv[]```
-   main()함수에 전달되는 실제적인 데이터
-   아무것도 전달받지 않았을 때
>   argv[0]에는 프로그램 파일명<br>
>   ex) C:₩Users...test.c.exe
-   입력을 주었을 경우
>   argv[0] test.c<br>
>   argv[1] 입력 1<br>
>   argv[2] 입력 2...<br>

>char *argv[] == char **argv

프로그램의 이름
-   argc == 1일때 argv[0]에 저장


## ex01 
### ft_print_params;
>   주어진 인자를 출력하는 프로그램
argv[0]를 제외한 모든 인자를 출력

-   예외처리
>   if ( argc != 1 ) 말고<br>
>   while ( idx++ < argc )


## ex02 
### ft_rev_params;
ex01의 역순버전 프로그램


## ex03 
### ft_sort_params;
>   주어진 인자를 ascii 순서로 정렬하여 출력하는 프로그램

ascii 순서로 정렬하는 방법
-   ft_strcmp 함수 사용
>   양수를 리턴하면 ascii 순서가 더 나중을 뜻함

주의
-   swap을 위한 변수 temp를 정의할 떄 대상은 char* 형 이므로
```.c
char *temp
```
로 맞춰서 정의한다
```.c
temp = s1
s1 = s2
s2 = tmep
```
