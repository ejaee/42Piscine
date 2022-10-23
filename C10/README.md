# C10

### [display_file](#ex00)
### [cat](#ex01)
### [tail](#ex02)
### [hexdump](#ex03)

## ex00 
### display_file;
>   인자로 주어진 파일의 콘텐츠만을 표준 출력에 표시하는 프로그램 만들기

1.  인자 갯수 확인
2.  `open()`을 통해 fd 값 반환
3.  fd 값을 통해 `read()` 접근
4.  `read()`에서 필요 size만큼 받아온 후 `write()`
5.  모두 읽으면 `close()`
>   에러를 출력할 때 write의 fd는 `2`

## 파일을 처리하는 함수
1. open (#include <fcntl.h>)
2. close (#include <fcntl.h>)
3. read (#include <unistd.h>)
4. write (#include <unistd.h>)

💡 파일 디스크립터 (FD, File Descriptor)
- 파일을 열면 반환되는 값
- 특정 파일에 접근하기 위한 `추상 key` 역할
- 프로그램에서 파일이나 장치에 접근하는 데 사용하는 정수값

> FD 0 : 표준 입력<br>
> FD 1 : 표준 출력<br>
> FD 2 : 표준 에러 출력<br>

- 3 부터는 파일 오픈 or 소켓 생성 시 부여되는 번호
> 프로세스 실행 중 파일을 open하면 커널은 해당 프로세스의 FD 숫자 중 사용하지 않는 가장 작은 값을 할당<br>
> 두개의 파일을 open하면 각각 fd 3, 4를 할당받음


### 🔸 open 함수
> #include <fcntl.h>
```.c
int open(const char* pathname, int flags[mode_t mode]);
```
#### 매개변수

const char* `pathname`
- 열고자 하는 파일 이름
- 절대경로 파일명과 상대경로 파일명 모두 허용
- 간단하게 파일명으로 지정하고 읽고자 하는 파일을 Makefile에 두면 된다


int `flags`[mode_t mode]
- 어떤 방식으로 파일을 열지 접근 권한을 설정
- 원본 훼손하지않고 읽을 때 O_RDONLY

<img width="628" alt="스크린샷 2022-02-16 오후 8 05 27" src="https://user-images.githubusercontent.com/87407504/154251937-6b9f98d9-16e6-4532-be46-a24818b2da50.png"><br>

#### 반환 값

성공 : 양의 정수<br>
실패 : -1<br>

### 🔸 close 함수
> #include <fcntl.h>
```.c
int close(int fd);
```
#### 매개변수

int `fd`
- 닫으려하는 파일의 파일식별자

#### 반환 값

성공 : 0<br>
실패 : -1<br>

### 🔸 read 함수
> #include <unistd.h>
```.c
ssize_t read(int fd, void* buf, size_t nbytes);
//💡  size_t : size를 나타내기위한 타입
      64bit 운영체제에서 64bit에 해당
      size_t == unsigned int
    
//💡  ssize_t : signed size type의 약자로 반환값으로 해당 IO 함수의 실패여부를 알려준다
      ssize_t == signed int
```
#### 매개변수

int `fd`
- 파일식별자

void* `buf`
- 데이터를 저장하는 버퍼
- 어떠한 자료형을 읽어올지 모르기에 void* 형
- int 형 자료를 입력받고자 한다면 buf를 int형 배열로 선언 후 매개변수 넣어주기

size_t  `nbytes`
- 읽어올 데이터의 바이트 수

#### 반환 값

성공 : 읽은 바이트 수<br>
실패 : -1<br>

### 🔸 write 함수
> #include <unistd.h>
```.c
ssize_t write(int fd, void* buf, size_t nbytes);
```
#### 매개변수

int `fd`
- 파일식별자

void* `buf`
- 데이터를 저장하고있는 버퍼

size_t  `nbytes`
- 쓸 데이터의 바이트 수

#### 반환 값

성공 : 파일에 쓴 바이트 수<br>
실패 : -1<br>

## ex01 
### ft_cat;
>   cat 명령어 구현

1.    main 경우의 수
-    param 있을 때
-    param 없을 때
      >     param 없을 경우
      >     STDIN_FILENO
      >     cat - 만 쳤을때도 위와 동일
      >     옵션을 고려하지 않지만 해당사항 일단 예외처리


2.    param 있을 때 경우의 수
-     param이 오류가 아닐 때
      >     STDOUT_FILENO
-     param이 오류일 때

3.    param이 오류일 때 경우의 수
-     파일일 때
      >     strerror(errno);
-     디렉토리일 때
      >     cat /dir의 경우
      >     "Is a directory" 를 출력해야 함
      >     open(O_RDONLY)는 디렉토리에 접근할 수 없음
      >     open(O_DIRECTORY) 필요

## 오류처리

### 🔸 errno
>     #include <errno.h>

-     함수의 return 값이 -1이며 오류인 것을 알 수 있으나 이유는 모른다
-     오류 이유를 알아내기 위해 errno 변수를 사용한다
>     errno 변수는 다른 함수를 실행하면 값이 변경되기 때문에 errno 변수를 설정한 함수 호출 직후에만 유효하다

경로 : /usr/include/asm
<img width="509" alt="스크린샷 2022-02-19 오후 3 32 09" src="https://user-images.githubusercontent.com/87407504/154789558-1ceb89a1-d964-4ed9-9fa1-5a35c13f4b3b.png">


```.c
      #include <stdio.h>
      #include <errno.h>

      int main(){
      errno = E2BIG;
      perror("error meassgae");
      errno = EACCES;
      perror("error meassgae");

      return 0;
      }
```
<img width="395" alt="스크린샷 2022-02-19 오후 3 01 12" src="https://user-images.githubusercontent.com/87407504/154789521-22dce6bb-226c-41f0-bc87-b12f4bfd4bb6.png">

### 🔸 strerror
>     #include <string.h>
오류 메세지 문자열을 가리키는 포인터를 얻어온다

## 기타
### 🔸 basename [경로 + 파일, (선택)확장자]
>     #include <libgen.h>
-     절대 경로를 상대경로로 변환
-     확장자 매개변수 추가 시 확장자 제거도 가능


