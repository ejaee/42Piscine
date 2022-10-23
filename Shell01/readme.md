# 📖 Shell01

📖 ***Unix `shell` 명령어를 학습한다***

-----

## ex01
### 📌 print_groups

Linux에서는 사용자 그룹 기타사용자로 구분하여 권한 관리한다
	```.vim
	chmod 755 >> 사용자(Owner), 그룹(Group), 기타사용자(Other) 순의 권한 부여
	```
환경변수를 확인하는 방법  : `export`

-   `groups` 그룹명 명령어
	
	그룹에 속한 사용자 계정을 확인할때 사용하는 명령어
	- $groups user01 하면
	- user01 그룹에 포함되어있는 사용자를 나열

- `tr` 
    ```.vim
    tr [옵션] [문자열1] [문자열2]
    ```
	- 특정 문자를 변환하거나 삭제하는 명령어

	- 옵션
	`-d` :  문자열1에서 지정한 문자 삭제
	`-s` : 문자열2에서 반복되는 문자 삭제
	`-t` : 문자열1을 문자열2의 길이로 자르기
	```.vim
	ex)
    
    $ echo AaAa | tr 'a-z' 'A-Z'
					소문자를 대문자로
	AAAA

	$ echo a b c | tr ' ' ','
					빈칸에 쉼표넣어주기
    a,b,c
    ```
	
-   FT_user 소속 그룹의 목록을 공백대신 쉼표로 출력하고 싶다
    ```.vim
	$ groups FT_user | tr ' ' ','
    ```

또 다른 풀이법

- id

	특정 사용자의 user, group를 확인할 수 있다
	- `-G` : 모든 group ID를 확인
	- `-g` : effective group ID만 확인
	- 사용자 번호 대신, 이름을 확인


-----

## ex02
### 📌 find_sh

현재 디렉이하에서 `.sh`로 끝나는 모든 파일을 `이름만` 출력하기

- `-name` "*.sh"

    sh 확장자 파일을 찾겠다

- `basename` 명령어

    ```.vim
    basename [경로+파일 이름] [제거하고 싶은 확장자(선택사항)]
    ```
    file full path로 부터 파일 이름만 추출
	- /usr/lib64/test.co라는 파일이 있을 경우
	> $basename /usr/lib64/test.co을 실행하면
	
    > `test.co`가 출력(dir 미출력)
	
    - 접미사를 지우고 싶다면
	> $basename /usr/lib64/test.co .co를 실행하면
	
    > `test`가 출력
	
- `-exec` 표현식

    find 명령으로 검색된 결과를 사용해 다른 명령을 실행시킬 수 있음

	- `execdir command{}` 액션
    execdir 이후에 오는 명령어를 사용할 때 인자로 파일명만을 받는다
    > 경로는 제외

	> `-exec`는 인자로 경로를 포함한 파일명을 받는다
	
	끝나면 \; 로 종료

- 종합

    ```.vim
    find . -type f -name "*.sh" -exec basename {} .sh \; 
    ```

-----

## ex03 
### 📌 count_files

현재 디렉과 그 하위 모든 디렉에 있는 `일반 파일과 디렉 개수를 세어 표시`하는 명령어

- `find` + `wc` 명령어
    
    검색 파일의 문자 수 or 라인 수를 계산하여 출력

    - `-l` : 해당 파일의 줄 수를 계산

>   파일 갯수 출력 이전에 공백이 선출력된다

- `tr` 명령어로 해결

    지정한 문자를 바꾸거나 삭제하는 명령어

    - `-d` :  해당 문자를 삭제

- 종합

    ```.vim
    find . | wc -l | tr -d ' ' 
    ```

-----

## ex04
### 📌 MAC

컴퓨터의 MAC `주소를 표시`하는 `ifconfig` 명령어

- 개념 설명

	ifconfig -a 모든 네트워크 인터페이스 구성을 확인할 수 있다
	- `-a` : 비활성화된 인터페이스까지 확인할 수 있다


- 특정 주소만(either) 표시하고 싶다

    `grep` 명령어
    - 입력으로 전달된 파일의 내용에서 특정 문자열을 찾고자할 때 사용
    - `-w` : word 매칭 옵션
    - mac 주소는 ether이라고 함
	
- 불필요한 공백을 없애고 싶다

    `cut` 명령어
    - `-d` : 필드를 구분하는 문자 지정
    - `-f` : 지정할 필드만을 출력
    > -f2 : file에서 2번째 필드 출력
 

 - 종합

    ```.vim
    ifconfig -a | grep -w ether | cut -d ' ' -f2
    ```
[참고사이트](https://blog.naver.com/cumulusworld/220102945835)

-----

## ex05 
### 📌 Can you create it?

역슬래쉬를 파일 이름에 적고, 개행문자를 내용에서 제외할 수 있는가?

- 역슬래쉬는 파일 이름으로 사용할 수 없지만

    앞에 \를 붙이면 특수문자 사용이 가능하다
	
    ```.vim
	"\\\?\$\*’MaRViN’\*\$\?\\\"
	 "  \  ?  $  *  '
	\" \\ \? \$ \* \'
	```

- 개행문자 `\n`를 삭제하는 이유와 방법

	xxd 헥사덤프를 통해 유닉스 체제에서는 개행문자가 16진수로 0a의 값을 가짐
	
    - 파일의 크기에 영향을 주므로 반드시 삭제하는것이 맞음
    - tr -d '\n'를 통해 삭제
    > cat -e를 통해 개행문자를 $로 확인할 수 있다    

-----

## ex07 
### 📌 Skip

ls -l 명령어의 첫번째 행부터 시작해 다른 모든 행을 보여주는 명령어
	

- `awk`

    ```.vim
    awk [option] [awk program] [argument]
    ```
	awk 파일로부터 레코드를 선택하고 선택된 레코드에 포함된 값을 조작하거나 데이터화하는 것을 목적으로 사용하는 프로그램
	
    - 텍스트 파일로 저장되어있는 파일을 자신이 원하는 부분만 출력 가능
	- 파일의 내용을 모두 출력할 때
    > awk '{print}' FILE
	
    - 파일의 첫번째 두번째 필드만 출력
    > awk '{print $1, $2}' FILE) --- 1,2열 출력

	- 문자열 "A"를 포함하는 레코드만 출력
    > awk '/A/' FILE

	즉, 입력데이터로부터 주어진 패턴을 포함하는 라인을 찾기 위해 파일의 내용을 탐색한 뒤, 패턴에 일치하는 라인이 발견되면 해당 라인에 대해 지정된 액션을 실행
	
	
	 - `print NR` 옵션 : 행번호를 출력

     ```.vim
     ls -l | awk "NR%2==1"
     ```

-----

## ex07
### 📌 r_dwssap

다양한 명령어를 통해 문제의 조건에 맞게 출력하기
> /etc/passwd 파일은 라인이 필드로 구분되어 있다


    ```.vim
    cat /etc/passwd 
    | grep -v "^#" 
    | awk "NR % 2 == 0" 
    | cut -d ":" -f 1 | rev | sort -r 
    | sed -n ''$FT_LINE1','$FT_LINE2'p' 
    | tr '\n' ' ' | sed 's/ /, /g' | sed 's/, $/./g' 
    | tr -d '\n'

    ```

1. 주석 삭제
    | grep -v "^#"

2. 두번째 행부터 시작하여 출력
    | awk "NR % 2 == 0

3. 각 login 거꾸로 반전
    | `rev`
    - 모든 입력을 받아 반전한 다음 터미널 창에 출력

4. 출력 대상이 사진과 같으려면
    | cut -d ":" -f 1

5. 알파벳 역순 정렬
    | `sort` -r
    - 정렬 명령어
    - `-r` : 오름차순으로 정렬    

6. $FT_LINE1'부터 '$FT_LINE2`까지만 해당
    | sed -n ''$FT_LINE1','$FT_LINE2'p'

7. 각 login은 ","로 구분
    | tr '\n' ' ' 
    > \n 구분을 ' ' 구분으로 변경
    | sed 's/ /, /g' 
    > ' ' 문자를 ',' 로 치환
    | sed 's/, $/./g'
    > 마지막 개행이 발생하는 '$'를 "."으로 치환
8. 출력 결과는 "."로 끝
    | tr -d '\n'

`sed` 명령어

    - 편집기를 명령어 쓰듯 사용하는 명령어
    - 파일을 인자로 받아 명령어를 통해 작업 후 화면으로 확인
    - 원본 손상이 없다는 장점이 있다

    옵션
    - `-n` `from,to p`: 특정 범위만큼 내용 출력
    - `'s/from/to/g'` : from을 to로 치환
        > g는 한 행에 바꿀게 여러개 있어도 다 바꾸겠다는 뜻

-----

## ex08
### 📌 add_chelou


다양한 명령어를 통해 문제의 조건에 맞게 출력하기
> 서로 다른 베이스를 가진 5진수 2개를 더한 결과를 13진법으로 나타내라

    ```.vim
    echo $FT_NBR1 + $FT_NBR2 
    | sed "s/\'/0/g" 
    | tr '\\\"\?\!' 1234 | tr 'mrdoc' 01234 
    | xargs echo 'obase=13; ibase=5;' 
    | bc | tr 0123456789ABC 'gtaio luSnemf'
    ```
`xargs` 명령어
    - 표준 입력에서 데이터 스트림을 읽고 명령 줄을 생성하고 실행
    - 명령을 실행하지 않으면 echo를 실행

    ```.vim
    echo "obase=2; 27: | bc

    10진수 27을 2진수로 변환
    ```

`bc` 명령어
    - 산수 계산하는 명령어
-----