# C12

### [ft_create_elem](#ex00)
### [ft_list_push_front](#ex01)
### [ft_list_size](#ex02)
### [ft_list_last](#ex03)
### [ft_list_push_back](#ex04)
### [ft_list_push_strs](#ex05)
### [ft_list_clear](#ex06) 🚨
### [ft_list_at](#ex07)
### [ft_list_reverse](#ex08) 🚨
### [ft_list_foreach](#ex09)
### [ft_list_foreach_if](#ex10)
### [ft_list_find](#ex11)
### [ft_list_remove_if](#ex12)
### [ft_list_merge](#ex13)
### [ft_list_sort](#ex14) 🚨
### [ft_list_reverse_fun](#ex15) 🚨
### [ft_sorted_list_insert](#ex16)
### [ft_sorted_list_merge](#ex17)

## [ft_list.h]()
```.h
    typedef struct      s_list
    {
        struct s_list       *next;
        void                *data;
    }                       t_list;
```

## ex00 
### t_list*    ft_create_elem(void* data);
>   연결 리스트 새 노드를 생성

노드를 삽입/삭제 하기 전 새 노드를 생성하는 함수가 필요하다

1.  새 노드 동적할당
2.  받은 data를 새 노드에 저장
3.  next를 아직 연결하지 않기위해 NULL

```.c
Node* create(void* data)
{
 // 새 노드 동적할당
 Node* NewNode = (Node*)malloc(sizeof(Node)); 

 NewNode->data = data;
 NewNode->next = NULL; // 아직 리스트에 연결하지 않음.
 return NewNode;// 새 노드의 주소를 호출한 곳으로 반환한다.
}
```
새 노드(구조체)를 생성하여 아직 연결리스트에 연결하지 않은상태.


## ex01
### void    ft_list_push_front(t_list **begin_list, void *data);
>   생성한 노드 앞에서부터 삽입
1.  노드 생성 ft_create_list(void *data)
2.  맨 앞은 head 다음이므로 찾을 필요 없음
3.  링크 연결
```.c
void push_front(void* data)
{
// 1)

Node* NewNode = ft_create_list(data);
 
// 2) 맨 앞은 begin_list가 가리키므로 찾을 필요 없음
 
// 3) new_node를 먼저 이어주고 이후에 begin_list 연결

NewNode->next = (*begin_list); //begin_list가 가리키는 것을 newnode가 가리키기

(*begin_list) = NewNode;
}
```

## ex02
### void    ft_list_size(t_list *begin_list);
>   노드의 갯수 세기
인자 : *begin_list

```.c
while (begin_list)
{
    count ++;
    begin_list = begin_list->next;
}
```
main에서 주의할 점
```.c
t_list  **begin_list;
t_list  *list;

    ...

begin_list = &list;
ft_list_size(list);
==  ft_list_size(*begin_list);
```

## ex03
### t_list    *ft_list_last(t_list *begin_list);
>  노드들 중 마지막 노드 값을 반환

```.c
while (begin_list->next)
    begin_list = begin_list->next;
return (begin_list);
```

## ex04
### void    ft_list_push_back(t_list **begin_list, void *data);
>   생성한 노드 뒤에서부터 삽입

1.  노드 생성 ft_create_list(void *data)
2.  [ex03] 방식을 이용하여 마지막 노드 찾기
3.  링크 연결
```.c
void push_front(void* data)
{
// 1)

Node* NewNode = ft_create_list(data);
 
// 2) [ex03]방식을 통해 맨 뒤 노드를 찾는다
 
while ((*begin_list)->next)
    *begin_list = (*begin_list)->next;

// 3) new_node 이어주기

(*begin_list)->next = NewNode;   //  마지막 노드가 new_node 가리키기
}
```

## ex05
### t_list  *ft_list_push_strs(int size, char **strs);
>   strs의 str들을 첫번째 요소부터 push_front하기
두번째 요소를 노드에 넣고 첫번째 노드를 가리켜야함

1.  strs[0]노드 만들기
2.  strs[1]노드 만들기
3.  strs[1]노드->next = strs[0] 노드
4.  strs[2]노드 만들기
5.  strs[2]노드->next = strs[1] 노드
strs[1]은 처음에 `가리켜야`하고 두번째 `가리킴을 받아야`한다
> temp로 해결
```.c
t_list  *temp;
t_list  *new_node;

temp = ft_craete(strs[0]);
while (size--)
{
    new_node = ft_craete(strs[1]);
    new_node->next = temp;
    temp = new_node;
}
```

## ex06
### t_list  * ft_list_clear(t_list * begin_list, void (* free_fct)(void*)); 🚨🚨
>   동적 할당한 메모리 해제
그냥 한꺼번에 free할 수 있지만 문제에서 인자를 주었음을 고려

```.c
void*   free_fct(void* data)
{
    free(data);
}
```
0. 이동과 free를 동시에할 수 없으니 temp 변수 추가
1. free 하기전에 이동루트 먼저 설정
2. void* 형 data free
3. node free

구조체
```.c
typedef struct s_list
(
    struct s_list   next;
    void            *data;
)                   t_list;
```


## ex07
### t_list  * ft_list_at(t_list * begin_list, unsigned int nbr);
>   목록의 n번째 요소 반환하는 함수

nbr만큼 
```.c
    begin_list = begin_list->next;
```
반복

## ex08
### t_list  * ft_list_reverse(t_list * begin_list); 🚨
>   목록 요소 순서를 뒤바꾸는 함수

[reverse_linked_list](https://www.youtube.com/watch?v=sYcOK51hl-A)<br>
![KakaoTalk_Photo_2022-02-22-03-49-56](https://user-images.githubusercontent.com/87407504/155015859-14ce29bb-229c-4412-ad80-b8571d93e94c.jpeg)<br>

## ex10
### void    ft_list_foreach(t_list * begin_list, void (* f)(void* ));
> 인자로 주어진 함수를 목록의 각 요소에 적용하는 함수

두번째 인자가 ft_putstr이라면, 함수포인터를 사용해 리스트를 출력하는 함수인 것

```.c
    while (list)
    {
        (*f)(list->data);
        list = list->next;
    }
```

## ex10
### void    ft_list_foreach_if(t_list * begin_list, void (* f)(void* ), void* data_ref, int (*cmp)());
> ex09 + if문을 통해 포인터 함수 체크

자료형에 유의하기
```.c
    while (list)
    {
        if (!(*cmp)(list->data, data_ref))
            (*f)(list->data);
        list = list->next;
    }
```

int main함수에서는
```.c
    
            ...

    ft_list_foreach_if(list, ft_putstr, "keyWord", cmp)
```

ft_putstr의 함수원형이 void(*f)(void *) 이므로
```.c
    void    ft_putstr(void *str)
    {
        while (*(char*)str)
            write(1, (char*)str, 1);
    // (char*)*str 이 아니다! 🚨
    }
```

## ex11
### void    ft_list_find(t_list * begin_list, void (* f)(void* ), void* data_ref, int (*cmp)());
> ex10의 if문 체크를 활용

TRUE의 경우 첫 번째 요소의 해당데이터 주소를 반환
```.c
    while (begin_list)
    {
        if (!(*cmp)(begin_list->data, data_ref))
            return (begin_list);
        begin_list = begin_list->next;
    }
    return (0);
```

## ex12 
### void    ft_list_remove_if(t_list ** begin_list, void* data_ref, int (* cmp)(), void (*free_fct)(void *));
> 

🚨🚨🚨 놈 error : 25줄 이하로 줄이기

## ex13
### void    ft_list_merge(t_list ** begin_list1, t_list * begin_list2);
> 두번째 인자를 첫번째 list 끝에 연결짓기

list가 있는지 check 필요
-   있으면 head->next까지 접근
-   head-next에 연결하고자 하는 node의 주소값 주기

list가 없으면
-   *being_list1에 node 주소값 주기

머릿속으로 그림 그리기

## ex14
### void    ft_list_sort(t_list ** begin_list, int (* cmp)()) 🚨
> list 오름차순 정렬

어떻게 정렬할 것인가?

- 알고리즘 없이 모두 비교하기
>   head : node 갯수 n 만큼 비교
>   cur : node 갯수 n 중 2개씩 n-1번 비교
```.c
    head = *begin_list;
    while (head)
    {
        cur = *begin_list;
        while (cur->next)
        {
            if (cmp(cur->data, cur->next->data) > 0)
            {
                temp = cur->data;
                cur->data = cur->next->data;
                cur->next->data = temp;
            }
            cur = cur->next;
        }
        head = head->next;
    }
```
> head와 cur는 서로 관여하지 않는다

주의사항
- cur은 두개를 비교하므로 `while (cur->next)` !!!


## ex15
### void    ft_list_reverse_fun(t_list * begin_list) 🚨
> 요소의 순서 뒤바꾸기

어떻게 정렬할 것인가?

- 가장 왼쪽 노드 하나 고정하고 오른쪽 노드들과 한번씩 다 바꾸기
- turn 끝나면 왼쪽노드 오른쪽 1 이동
> str : 고정하는 왼쪽 노드
> move : 게속 바뀌고 이동하는 오른쪽 노드
```.c
std = begin_list;
    while (std)
    {
        move = std->next;
        while (move)
        {
            temp = std->data;
            std->data = move->data;
            move->data = temp;
            move = move->next;
        }
        std = std->next;
    }
```

## ex16
### ft_sorted_list_insert(t_list ** begin_list, void *data, int (* cmp)())
> create_elem(ex00) + list_sort(ex14)

주의사항
- 인자 넘길 때 ft_list_sort(begin_list, cmp);
> 포인터 함수에 맞게 cmp로 전달하기

- sort에서 cur은 반드시
> while (cur->next)까지

- create_elem 사용할 때 주소값을 new_node 에 전달받지 않기
> if) head->next = ft_create_elem(data);
> else) *begin_list = ft_create_elem(data);

## ex17
### ft_sorted_list_merge(t_list ** begin_list1, t_list * begin_list2, int (* cmp)())
> list_merge(ex13) + list_sort(ex14)
