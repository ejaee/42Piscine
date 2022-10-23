# C09

### [libft.a](#ex00)
### [Makefile](#ex01)
### [ft_split.c](#ex02)

## ex00 
### libft.a;
>   쉘 스크립트를 활용해 ft 라이브러리 만들기

### 쉘 스크립트
-   Unix 커맨드등을 나열해서 실행하는 것
-   쉘 스크립트 파일은 기본적으로 .sh 확장자로 작성

1.  셸 스크립트를 쓴다는 사실을 알리기 위해 첫 행에 `#!/bin/sh`를 쓴다
2.  Unix 커멘드 작성
3.  스크립트 실행 명령어 `sh filename.sh`


정적 라이브러리 작성 명령어
-   `ar`
-   <ar 옵션> <생성하고자 하는 라이브러리의 이름> <오브젝트 파일들의 이름>

ar 옵션
-   `-r` : 지정한 아카이브로 모듈(obj파일) 추가. 새로운 obj파일이면 추가, 기존 파일이면 치환

-   `-c` : 아카이브 (라이브러리 파일) 생성

-   `-s` : 아카이브 인덱스를 생성. 아카이브 인덱스를 생성하지 않으면 링크 속도가 느려지고, 시스템 환경에 따라서는 에러가 발생.

```.sh
    #!/bin/sh
    // obj파일을 만들기 위한 컴파일 -c
    gcc -c -Wall -Wextra -Werror *.c
    // 이후 obj파일 묶어주어 라이브러라 생성
    ar -rc libft.a *.o
```
정적 라이브러리의 쓰임

목적파일들을 만들어 묶어두면 소스파일을 링크하는 단계에서 소스파일의 obj파일과 해당 라이브러리의 obj파일들을 하나로 결합하여 실행파일을 생성

> CF) 동적 라이브러리
```.vim
정적라이브러리처럼 컴파일 시에 함수가 연결되는 방식이 아닌 런타임시에 함수가 실행파일에 연결된다. 

실행파일에는 호출할 함수의 정보만 포함되고 실제 함수 코드는 복사되지 않으므로 실행 파일의 크기가 작아진다. 

하지만 실행 파일은 함수에 대한 정보만 가지고 있을 뿐 실제 코드를 가지고 있지 않기 때문에 

프로그램 실행시에는 dll 파일이 항상 존재해야 한다.
```

### gcc 컴파일러 옵션
-c
-   링크의 과정은 생략하고 컴파일만 수행

-o ( outputfilename )
-   컴파일한 결과를 저장하는 파일명을 직접 지정해 주는 옵션
-   -c 옵션이 주어졌을 때는 sourcefilename.o 파일이 생성
-   이 옵션이 사용되지 않으면 기본적으로 a.out 실행파일 생성

-g
-   실행파일을 생성할 때, 디버거를 위한 변수테이블을 함께 생성

## 라이브러리
>   프로그램을 만드는 데 필요한 함수들을 모아놓은 파일
>   -   확장자가 c인 소스 파일에는 함수를 정의
>   -   확장자가 h인 헤더 파일에는 함수를 선언

컴파일 과정

1.  소스파일에서 라이브러리에 있는 함수를 호출하는 코드를 사용하면, 
2.  랑크 단계에서 소스파일의 오브젝트 파일과 해당 라이브러리의 오브젝트 파일을 하나로 결합하여 실행파일을 생성

종류

-   동적 라이브러리 : 완성된 프로그램을 실행할 때 포함시키는 동적 라이브러리

-   정적 라이브러리 : 프로그램을 컴파일하는 과정에서 포함시키는 오브젝트 파일들이 묶여있는 형태

확장자별 라이브러리 구분

-   .a : 리눅스 / 정적 라이브러리

-   .so : 리눅스 / 동적 라이브러리

-   .lib : 윈도우 / 정적 라이브러리

-   .dll : 윈도우 / 동적 라이브러리

## ex01 
### Makefile;
>   Makefile를 활용해 ft 라이브러리 만들기

[makefile 자료 참조](http://www.nicklib.com/library/make/Make-1.html)

### Makefile 내부 구조
>   목표(target), 의존 관계(dependency), 명령(command)의 세개로 이루어진 기분적인 규칙(rule)들이 계속적으로 나열
```
    target ... : dependency ...
                    command
                    ...
                    ...
```
-   목표(target)는 명령(command)이 수행이 되어서 나온 결과 파일을 지정
>   당연히 목적 파일(object file)이나 실행 파일이 될 것이다

-   명령(command)에 정의된 명령들은 의존 관계(depenency)부분에 정의된 파일의 내용이 바뀌었거나, 목표 부분에 해당하는 파일이 없을 때 이곳에 정의된 것들이 차례대로 실행
>   쉘에서 쓸 수 있는 모든 명령어들을 사용할 수 있음
    
-   명령 부분은 꼭 `TAB` 글자로 시작
-   명령 부분은 Dependency가 들어가면 안된다

Makefile 장점
-   컴파일 때 사용하는 반복되는 명령을 매크로처럼 사용 가능
-   목적 파일을 보다 쉽게 관리
-   종속성(Dependency)을 이용한 incremental build
>   Incremental build란 반복적인 빌드 과정에서 변경된 소스코드에 의존성(Dependency)이 있는 대상들만 추려서 다시 빌드하는 기능

### 일반적 예제
1.  main.c read.c write.c로 구성되어 있고 모두 io.h라는 헤더 파일을 사용
2.  각각 컴파일해서 test 라는 실행 파일을 생성

🔸 Makefile을 사용하지 않을 때
```vim
% gcc -c main.c
% gcc -c read.c
% gcc -c write.c

% gcc -o test main.o read.o write.o
```

🔸 Makefile 단순 사용
```.c
test : main.o read.o write.o
                gcc -o test main.o read.o write.o

main.o : io.h main.c 
                gcc -c main.c
read.o : io.h read.c
                gcc -c read.c
write.o: io.h write.c
                gcc -c write.c

```

🔸 Makefile 매크로 사용
```.c
OBJECTS = main.o read.o write.o

test : $(OBJECTS)
                gcc -o $(OBJECTS)

main.o : io.h main.c
                gcc -c main.c
read.o : io.h read.c
                gcc -c read.c
write.o: io.h write.c
                gcc -c write.c
```

🔸 레이블 사용 가능
```.c
clean :
                rm $(OBECTS)
```
>   % make clean<br>
    rm main.o read.o write.o <- OK

-   레이블 clean과 같은 파일이름이 존재할 경우 명령어가 제한됨

이를 예방하기위해 .PHONY를 달아주기도 함

```.c
# .PHONY: all clean fclean
```

🔸 make에서 사용되는 매크로, 변수를 활용 `make -p`
```.c
OBJECTS = main.o read.o write.o
SRCS = main.c read.c write.c <- 없어도 됨

CC = gcc <- gcc 로 세팅
CFLAGS = -g -c <- gcc 의 옵션에 -g 추가

TARGET = test <- 결과 파일을 test 라고 지정

$(TARGET) : $(OBJECTS)
$(CC) -o $(TARGET) $(OBJECTS)

clean : 
                rm -rf $(OBJECTS) $(TARGET) core 

//  어떤 파일이 어디에 의존하고 있는지를 표시해 주기 위해서 꼭 필요
main.o : io.h main.c
read.o : io.h read.c
write.o: io.h write.c
```
>   make는 쉘상에서 정의한 환경 변수값들을 그대로 이용한다

🔸 확장자 규칙(.SUFFIXES) 사용
```.c
.SUFFIXES = .c .o 

OBJECTS = main.o read.o write.o
SRCS = main.c read.c write.c

CC = gcc 
CFLAGS = -g -c

TARGET = test

$(TARGET) : $(OBJECTS)
                $(CC) -o $(TARGET) $(OBJECTS)

clean : 
                rm -rf $(OBJECTS) $(TARGET) core 

main.o : io.h main.c 
read.o : io.h read.c
write.o: io.h write.c
```
>   굳이 확장자 연산을 정의하지 않아도 무방<br>
>    make 내부에서 기본적으로 서비스를 제공

🔸 내부 매크로의 활용
-   $* <- 확장자가 없는 현재의 목표 파일(Target)
-   $@ <- 현재의 목표 파일(Target)
-   $< <- 현재의 목표 파일(Target)보다 더 최근에 갱신된 파일 이름
-   $? <- 현재의 목표 파일(Target)보다 더 최근에 갱신된 파일이름
```.c
main.o : main.c io.h
gcc -c $*.c
//  $* 는 확장자가 없는 현재의 목표 파일
//  $* 는 결국 main 에 해당한다.

test : $(OBJS)
gcc -o $@ $*.c
//  $@는 현재의 목표 파일
//  $@는 즉 test에 해당된다.

.c.o :
gcc -c $< (또는 gcc -c $*.c)
//  $< 는 현재의 목표 파일보다 더 최근에 갱신된 파일 이름
//  .o 파일보다 더 최근에 갱신된 .c 파일은 자동적으로 컴파일이 된다. 가령 main.o를 만들고 난 다음에 main.c를 갱신하게 되면 main.c는 $<의 작용에 의해 새롭게 컴파일이 된다.
```

🔸 Makefile 작성 가이드라인
```.c
.SUFFIXES = .c .o     --+
CFLAGS = -g             |
                        |
OBJS = main.o \         |
read.o \                | 매크로 정의
write.o                 |
SRCS = $(OBJS:.o=.c)    |
                        |
TARGET = test         --+

$(TARGET): $(OBJS)                            --+
                $(CC) -o $@ $(OBJS)             |
dep :                                           |
                gccmakedpend $(SRCS)            |
new :                                           | 명령어 정의
                touch $(SRCS) ; $(MAKE)         |
clean :                                         |
                $(RM) $(OBJS) $(TARGET) core  --+


- 여기부터 의존관계

```
