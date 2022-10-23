# 📖 Shell00

📖 ***Unix `shell` 명령어를 학습한다***

-----

- 유닉스 셸

    유닉스 운영 체제 시스템을 위한 사용자 인터페이스
    > GUI가 아닌, 터미널 환경에 명령어를 입력해 컴퓨터의 동작을 다룬다

    > 사용자와 커널을 연결시켜주는 역할

    -----

## 📌 shell setup하기
> 셸을 유용하게 하는 다양한 개념을 정리

- 셸도 여러가지 종류가 있다

    📌 지금 내가 사용하고 있는 shell 확인하는 방법
    ```.vim
    echo $SHELL

    또는

    echo $0
    ```
    >   `$SHELL` 환경 변수는 현재 쉘의 이름을 보유

    📌 내 컴퓨터에 설치된 셸 목록을 확인하는 방법
    ```.vim
    cat /etc/shells
    ```

    📌 shell을 변경하는 방법 
    1.  로그인 셸 변경

    2.  대화 셸 변경

    📌 다른 shell을 설치하는 방법
    ```.vim
    # zsh 설치
    brew install zsh

    # 설치경로 확인
    which zsh
    #=> /usr/bin/zsh
    ```

    📌 zsh(z shell)의 기능
    1. 이동 편리성(zsh)
    bash에서의 `cd c00 -> cd .. -> cd c01` 과정을
    ```.c
    zsh에서는

    cd c00 c01 
    
    을 통해 이동할 수 있다
    ```

    2. tab 키를 통해 여러 자동완성 기능 사용 가능


    -----

-   shell을 돕는 다양한 관리 프로그램이 있다

    📌 프로그램 사용 전, zsh 버전을 확인한다
    ```.vim
    $ zsh --version
    ```

    📌 `Homebrew`는 macOS에 특화된 패키지 관리자이다
    ```.vim
    $ /usr/bin/ruby -e "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/master/install)"
    ```
    > `brew` 명령어를 사용할 수 있다

    📌 최신버전 zsh를 설치한다
    ```.vim
    $ brew install zsh
    ```

    📌 `oh-my-zsh`는 zsh 설정 관리를 위한 프레임워크로 유용하다
    ```.vim
    # git wget curl 설치 확인

    # oh-my-zsh 설치
    $ sh -c "$(curl -fsSL https://raw.githubusercontent.com/robbyrussell/oh-my-zsh/master/tools/install.sh)"
    ```
    >   다양한 플러그인을 사용할 수 있다

    >   .zshrc 파일 수정을 통해 다양한 테마를 사용할 수 있다

    > [Guide](https://tutorialpost.apptilus.com/code/posts/tools/using-zsh-oh-my-zsh/)

    > [Plugins](https://github.com/ohmyzsh/ohmyzsh/wiki/Plugins)

    📌 테마 적용하는 방법

    > [Theme 미리보기](https://github.com/ohmyzsh/ohmyzsh/wiki/External-themes)

    ```.vim
    vim ~/.zshrc
    ZSH_THEME="agnoster"
    ```
    > 내가 원하는 테마 이름을 "" 에 넣어준다

    > 폰트가 깨질 경우 폰트를 설치해줘야한다

    - [폰트설치파일](https://github.com/powerline/fonts/blob/master/SourceCodePro/Source%20Code%20Pro%20for%20Powerline.otf)

    -  [폰트설치가이드](https://velog.io/@saemsol/Oh-My-Zsh)

    변경내용 적용하기
    ```.vim
    source ~/.zshrc
    ```

-----

## ex00 
### 📌 Z

`cat` 명령어를 사용하여 화면에 원하는 문자 + 줄바꿈을 표시할 수 있는가?

-   `cat`

    기능
    - 파일의 내용을 단순 출력한다
    - 리다이렉션 기호와 함께 사용하여 파일을 생성하고 저장할 수도 있다
    ```.vim
    # 한개의 파일을 화면에 출력
    cat file.txt

    # 여러개의 파일을 화면에 출력
    cat file1.txt file2.txt file3.txt
    ```
    > vim file.txt를 통해 파일을 확인할 수 있지만

    > 간단한 문서확인에는 cat을 사용

    자주 사용하는 옵션
    - -e : 제어 문자를 ^형태로 출력하면서 각 행의 끝에 $를 추가

-   리다이렉션

    `>`
    - 표준 출력
        명령 > 파일 : 명령의 결과를 파일로 저장
    ```.vim
    echo Z > z
    ```
    > `echo` Z는 Z를 출력하고 줄바꿈이 일어나므로

    > 문제의 결과를 구현할 수 있다

    > `-n 옵션`을 주면 줄바꿈을 제외한다

    `>>`
    - 표준 출력(추가)
        명령 >> 파일 : 명령의 결과를 기존 파일에 추가 저장한다

    `<`
    - 표준 입력
        명령 < 파일 : 파일의 내용을 명령에 입력

-   cat + 리다이렉션

    파일 생성 & 합병
    ```.vim
    # file의 내용을 new_file라는 이름으로 생성
    cat file > new_file

    # file1 + file2 + file3 내용을 new_file라는 이름으로 생성
    cat file1 file2 file3 > new_flie

    # file2의 내용을 file1에 추가함
    cat file2 >> file1
    ```

    입력 내용을 파일로 저장
    ```.vim
    # file.txt에 new content라는 내용 입력 후 저장
    cat > file.txt
    new content

    # file.txt에 new content라는 내용 추가 후 저장
    cat >> file.txt
    new content
    ```
    > 추가 완료하였다면 `ctrl + c` 로 저장완료


-----


## ex01 
### 📌 testShell00

`ls` 명령어를 이해하고 `chmod`와 `tar`를 사용할 수 있는가?

-   `ls`

    기능
    -   list의 줄임말
    -   dir에 있는 내용(dir, file)을 출력하는 명령어

    자주 사용하는 옵션
    -   -l : 파일들을 자세히 출력
    -   -a : 숨김파일까지 경로안의 모든 파일을 나열

    목록 내용
    ```.vim
    (1)       (2)(3)(4)(5) (6)   (7)       (8)
    -r--r-xr-x 1 XX XX 40 Jun 1 23:42 testShell1100
    ```
    -   (1)
        > 맨 앞에는 `d`(dir) `-`(file) `l`(link) 이 올 수 있다

        > 나머지는 권한을 의미한다 r(read), w(write), x(exe)
    -   (2)
        > 하드링크 번호를 의미한다

        > 링크된 파일의 수를 의미한다

    -   (3), (4)
        > 소유자 및 소유그룹의 이름을 나타낸다

    -   (5)
        > 파일의 크기를 바이트 단위로 나타낸다

    -   (6), (7)
        > 파일이 만들어진 날짜 및 시간을 나타낸다

        > 수정되면 수정 시간을 반영한다

    -   (8)
        > 파일 및 디렉토리의 이름이다

    -----

-    `chmod`

    기능
    -   ls에서 보이는 (1)의 권한을 수정한다
    -   rwx
        > 각 1비트 총 3비트의 공간을 가진다
        
        > 2진수로, 4 2 1 이므로 7 =rwx, 5 =r-x

        ```.vim
        $chmod 664 fileName -> rw- rw- r--
        ```

    -----

-   `특정 크기의 파일을 만드는 방법`

    `head`
    - 텍스트로된 파일의 앞부분을 지정한 만큼 출력하는 명령어
    ```.vim
    $ head [-n lines | -c bytes] [file ...]
    기본 사용법

    $ head 파일명
    앞에서부터 10행까지 내용을 보여준다

    $ head (-n) 100 파일명
    앞에서부터 100행까지 내용을 보여준다

    $ head -c 100
    앞에서부터 100 바이트 내용을 보여준다

    $ head -100 파일명 > 저장_파일명
    출력되는 파일의 내용을 출력하고 싶다면 다음과 같이 기본 파일 입출력을 이용하면 된다.    
    ```
    head를 통해서 특정 크기 파일을 만들고 싶다면

    ```.vim
    head -c 40 /dev/urandom > fileName
    ```

    `fallocate`
    -   `바이트 기준`으로 지정
    ```.vim
    $fallocate -l byteSize fileName
    ```
    >    `-l`(length)

    `truncate`
    -
    ```.vim
    $truncate -s 0 fileName
    ```
    > `-s` 옵션 후 "K, M, G, T" 혹은 "KB, MB, GB, TB"를 통해서 원하는 크기(Size)의 파일을 생성

    기타 `dd`
    > fallocate와 truncate는 mac에 존재하지 않는다

    -----

-  `생성,최종 수정 날짜 변경하는 방법`

    `touch` 
    - 파일의 생성과 파일의 날짜, 시간을 변경하는 명령어 
    ```.vim
    touch -t YYYYMMDDhhmm fileName
    ```

    옵션
    - `-m` : 서버 시간으로 시간 변경
    > 서버 시간이 출력된다

    - `-t` : 원하는 시간으로 시간 변경
    > 시간 대신 년도가 출력된다

    > 변화 시간을 확인하고 싶다면, `T`옵션을 사용하면 확인할 수 

    -----

-   `tar`

    뜻
    - "테이프 아카이버(Tape ARchiver)"
    - t : 과거의 저장 장치인 테이프로 백업하기 위해 만들어진 프로그램
    - ar : 여러파일을 하나의 파일로 합치는 프로그램
    > 아카이브(Archive) : 참고용으로 생성한 데이터 사본

    기능
    - 파일을 압축시킨다

    옵션
    -   `-c` 새로운 압축파일을 만든다
    -   `-f` 대상파일을 tar 아카이브로 지정하는 옵션
    -   tar -cf [압축파일명] [압축할 파일 또는 폴더경로]
    -   tar -cf testShell00.tar testShell00

    압축 풀기
    ```.vim
    tar -xvf testShell1100.tar
    ```
    - tar 아카이브를 현재 디렉토리에 풀기

    - `-v`는 과정을 자세하게 나열하는 옵션
    ```.vim
    $tar -xvf testShell100.tar
    x testShell00
    ```
    > 압축 해제된 파일을 표시해준다

-----

## ex02 
### 📌 Oh yeah, mooore...

> 무어의 법칙 : 반도체 직접회로의 성능이 18개월마다 약 2배로 증가한다

`하드 링크`와 `소프트 링크`의 개념을 알고 있는가?


> head를 이용하여 크기를 고려해 파일생성

- i-node

    파일이 생성될 때 마다 고유의 번호가 주어지는데 이것이 i-node
    > 8자리 숫자로 나타난다
    
    > ls -i 옵션을 주면 i-node 값을 확인할 수 있다


- 하드 링크(Hard Link)

    기능
    - 파일의 복사본을 만든다
    - 같은 i-node 값을 가진다
    - 그러므로 수정이 함께 이루어진다
    - 원본을 지워도 하드 링크 파일은 실행되고 내용이 보존된다
    - 파일 권한이 `-`로 표시된다

    ```.vim
    $ln 원본 하드링크이름
    ```
    > `cp` 명령어는 i-node가 다른 카피파일을 생성하므로

    > 원본에 영향을 끼치지 않는다


- 소프트 링크(Soft Link) or 심볼릭 링크(Symbolic Link)

    기능
    - 바로가기를 만든다
    - 하드링크와 같이 수정 내용이 함께 바뀐다
    - 그러나 원본을 삭제하면 연결이 끊어진다
    - 파일 권한이 `l`로 표시된다
    ```.vim
    $ln -s 원본 소프트링크이름
    ```

-----
   
## ex03 
### 📌 Connect me

`Kerberos` Protocol를 알고 있는가?

- 커버로스란?

    티켓을 기반으로 동작하는 컴퓨터 네트워크 인증 `암호화` 프로토콜
    - 사용자와 서버가 서로 식별할 수 있는 상호인증을 제공한다


    - 기본적으로 `대칭 키 암호로 빌드`
    
    - 즉 클라이언트와 서버구조에서 서버 접근권한에 대한 관리를 위해 대칭키 방식을 이용하여 인증하는 네트워크 인증 암호화 프로토콜

    > 아파트 출입카드를 발급받고 아파트 1층 현관 암호문을 통과


-   방식

    순서
    1. 티컷이 있는지 확인
    ```.vim
    $klist
    ```
    2. 없을 경우 초기화하여 티켓을 생성
    ```.vim
    $kinit
    ```
    3. 모든 티켓 목록 확인하는 방법
    ```.vim
    $klist -l
    ```
    [참조](https://codecademy.tistory.com/entry/Kerberos-Protocol-%EC%BB%A4%EB%B2%A0%EB%A1%9C%EC%8A%A4%EA%B0%80-%EB%AD%98%EA%B9%8C?category=962621)
    
-----

## ex04 
### 📌 midLS

현 디렉 내의 모든 f, dir를 다음 조건에 맞게 출력하기
> ls 명령어 심화 학습

1. 생성일 순서로

    `-U`
    - 디스크에 저장된 파일 순서대로 출력

    `-t`
    - 최근 수정된 파일 순으로 정렬시켜서 출력

    > 저장 순서대로 U 출력 + 수정 사항을 반영하기 위해 Ut를 함께 쓴다

2. 쉼표로 분리해 나열하기

    `-m`
    - 파일을 쉼표로 구분하여 가로로 출력

3. dir 뒤에는 / 붙여서 출력

    `-p`
    - dir 이름 뒤에 /를 추가하여 출력

-----

## ex05 
### 📌 Git commit

git log를 원하는 조건에 맞게 출력시킬 수 있는가?

- 일반적인 Commit log

    저장소의 커밋 히스토리를 시간순으로 보여준다

    ```.vim
    커밋의 SHA-1 체크섬, 저자 이름, 저자 이메일, 커밋한 날짜, 커밋 메시지
    ```

    - SHA-1
    >  임의의 길이의 입력데이터를 160비트의 출력데이터(해시값)로 바꾸는 것

    git은 commit의 순서를 기억하기 위해 hash값을 사용한다
    - 해시
    > 해시란 단방향 암호화 기법으로 해시함수를 이용하여 고정된 길이의 비트열로 변경한 값

    > 입력값이 일부만 변경되어도 전혀 다른 해시값을 출력[눈사태 효과]
    
    > 입력값 상관없이 고정된 길이의 해시값을 출력

    > 같은 입력값에 대해서는 같은 출력값을 보장

-   최근 5개의 해시값을 표시하는 쉘 스크립트 작성

    ```.vim
    >bash git_commit.sh | cat -e
    ```

    - `--pretty`
    > 출력 내용을 어떻게 출력할지 정의하는 옵션
    ```.vim
    예시)
    git log --pretty=format:"%h - %an, %ar : %s"
    ```
    - `%H` : 커밋 해시
    - %h : 짧은 길이 커밋 해시
    - %an : 저자 이름
    - %ae : 저자 메일
    - %s : 요약

    ```.vim
    git log --format="%H" -5
    ```

-----

## ex06 
### 📌 gitignore

.gitignore 가 무엇인지 알고 있는가?

- 개념 설명

    통상 원격레포에 파일을 저장하기 위해
    - git add . -> git commit -m "" -> git push
    
    git add에 포함시키기 싫은 경우가 있다면?
    - .gitignore 디렉토리에 무시할 파일을 넣어줄 수 있다

    사용 방법
    - git init한 디렉에 .gitignore 파일을 만든다
    - 그 안에 한줄 씩 제외하고싶은 파일과 폴더제목을 쓰면 끝
    > .gitignore file은 최상위 디렉에 딱 하나 존재한다

- git 저장소가 무시하는 파일들을 나열하는 명령어

    옵션
    - `ls-files`
    > 파일의 리스트만 나열하는 옵션

    - `ls-files --others`
    > add되지 않은 파일을 출력하는 옵션

    > untracked file을 말한다

    - `--exclude-standard`
    > ignore 파일의 규칙을 따르는 옵션

    > 즉, git ignore 에 명시된 파일은 표시하지 않는 옵션

    - `--ignored`
    > 무엇을 나열하든 출력에서 ​​일부 파일을 제외하는 옵션

    정리
    ```.vim
    git ls-files --others --ignored --exclude-standard
    ```
    1. untracked files 을 출력 하겠다
    2. git ignore에 명시된 파일을 표시하겠다
    (ignore 명시 파일을 표시하지 않겠다는 것을 `--ignored`하겠다)


    통상 추가된 파일을 찾을 때 사용한다
     ```.vim
    git ls-files --others -mo --exclude-standard
    ```
    [참고사이트](https://stackoverflow.com/questions/15925079/why-does-git-ls-files-ignore-require-exclude-patterns)

    

-----

## ex07 
### 📌 diff

`diff`

- 념 설명

    두 파일 사이의 내용을 행 단위로 비교해 차이를 출력하는 명령어
    > 3개까지 비교 가능
    ```.vim
    diff [option] [비교파일1][비교파일2]
    diff3 [option] [비교파일1][비교파일2][비교파일3]
    ```

    결과를 읽는 방법
    ```.vim
    2,3c2,3           // 2~3번 라인이 다르다
    < This is test1   // 오른쪽과 다르게 왼쪽(<)내용이 이렇게 다르다
    <   Thank you
    ---
    > This is test1   // 왼쪽과 다르게 오른쪽(>)내용이 이렇게 다르다
    > Thank you
    ```


- 옵션 설명

    `-u`
    - 두 파일의 변경되는 부분과 변경되는 부분의 근처의 내용도 출력

    -----

`patch`

- 개념 설명

    patch file은 diff에 의해 생성된 파일
    
    - patch 만들기

    ```.vim
    diff -urN [원본파일] [수정파일] > [패치파일이름]
    diff3 [option] [비교파일1][비교파일2][비교파일3]
    
    ex)
    a.c를 b.c로 수정한 후 b.patch를 생성

        diff -uNf a.c b.c > b.patch
    ```
    
    > A.ver 파일에 수정내용(patch file)을 더해 B.ver를 만들었다
    
    > 그말은 수정내용(patch file)은 B.ver - A.ver 이다

    - patch 적용하기

        patch file이 적용되는 위치에 따라 명령어 옵션이 달라진다
        
        ```.vim
        $ patch -p0 < patch file

        patching a.ver
        ```
    `-p` : 패치 파일과 피패치 파일의 위치 관계에 따라 조절되는 옵션
    > 동일한 위치일 경우 -p0

    > 이후 diff를 해서 아무런 반응이 없다면 패치 완료

        ```.vim
        patch [option][원본파일][패치파일]

        ex) a.c를 b.c로 수정한 후 b.patch를 생성

 	        diff a.c b.patch
        ```

    - patch 제거하기
    ```.vim
    $ patch -p0 -R < patch file

    patching a.ver
     ```
     
 - 내가 문제를 푼 방식

    폴더에 a와 sw.diff 이 있다
    > a는 비교대상 파일, diff는 패치파일

    diff 패치파일로 a를 패치하면 되겠구나
    ```.vim
    patch -p0 < sw.diff
    ```
    
    a로 패치하겠다고 추가 입력하면 패치 

-----

## ex08
### 📌 clean

`find`

-  개념 설명

    찾고자 하는 파일이나 디렉의 위치를 찾을 때 쓰는 명령어

    
- 옵션 설명

    `find .`
    - 현재 디렉 이하에서 찾겠다

    `-type f`
    - file을 찾겠다

    `\( -name "#*#"" -o -name "*~" \)`
    - 찾고자 하는 파일 이름 조건을 달겠다
    - `-o` : or 옵션
    
        > text로 여러 패턴을 찾고 싶을때
        ```.vim
        find dir \( -name "*.py" -o -name "*.html" \)
        ```

    `-print`
    - 해당 파일을 표시하겠다

    `-delete`
    - 해당 파일을 삭제하겠다
    
- 종합
    ```.vim
    $ find . -type f \( -name "#*#"" -o -name "*~" \) -print -delete
    ```


-----

## ex09
### 📌 Illusions, not tricks, Michael...

`file` 명령어를 통해 `magic file`을 만들어라

- 개념 설명

    file
    -   file의 종류를 확인하는 명령어
    -   확장자를 보지 않고 내용을 보고 ASCII, Bynary인지 확인 가능
    >   리눅스는 확장자가 존재하지 않기 때문에 file 명령어가 필요하다

    종류를 확인하는 확인 절차 방법
    1. 파일시스템 test
    2. `magic test`
    3. 언어 test

    옵션
    - -C :  매직 파일의 포맷을 검사
    - -m [매직파일] : 별도의 지정된 매직파일로 대상 파일을 확인
    ```.vim
    $file -m ./[매직파일] [검사대상파일]
    ```

    매직 파일의 구성
    - 레벨의 offset값, 데이터 종류, 값, 출력 문자열

    ```.vim
    ex)
    0   string  check ELF
    ```
    > 파일의 처음부터 0바이트 떨어진 위치의 문자열이 check와 일치하면 ELF로 표시하라

- 문제 풀이

    42번째 바이트에 "42" 문자열이 있는지 확인하라
    1. 42번째 문자열을 확인하고 싶다
    > 41로 맞춰야 다음 42를 확인한다

    2. "42" 문자열을 확인하고 싶다
    > string 42

    3. 매직파일의 결과가 일치한다면 42 file 형식이 맞다는 뜻으로 이를 출력하자
    > 42 file

- 결과 정리
    ```.vim
    (in magicfile)
    41 string 42 42 file

    file -m magicfile file
    ```
    > 맞다면 : test1: 42 file

    > 아니라면 : test1: ASCII text

-----
