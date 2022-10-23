# C13

### [btree_create_node](#ex00)
### [btree_apply_prefix](#ex01)
### [btree_apply_infix](#ex02)
### [btree_apply_suffix](#ex03)
### [btree_insert_data](#ex04) 🚨
### [btree_search_item](#ex05) 🚨
### [btree_level_count](#ex06) 
### [btree_](#ex07)

## [ft_list.h]()
```.h
    typedef struct      s_list
    {
        struct s_list       *next;
        void                *data;
    }                       t_list;
```

## ex04
### btree_insert_data
### (t_btree ** root, void * item, int (*cmpf)(void *, void *)))
>   새로 들어오는 값을 저장된 값들과 비교하여 조건 입력하기

1. 해당 함수가 쓰일 때마다 root 노드부터 내려오며 배교가 되어야 한다
2. 인자로 node를 이어받기 때문에 호출때마다 root의 최상위 노드부터 시작되어야 한다
```.c
int main()
{
    ...
    t_btree *node;

    node = 0                    // 필수! bus error의 원인이였음
    btree_insert_data(&node 🚨, "5", (void*)ft_strcmp 🚨)

    // t_btree **root = &node;
}

```
3. 위와같이 연결되어야 호출때마다 루트노드부터 아래로 비교하며 내려갈 수 있다
4. 함수포인터 형변환 필요! (아래 참조)

함수포인터 형변환 실력 미숙 🚨<br>
> void* 형 포인터 활용
- void형 포인터는 뭐든 담을 수 있는 바구니
- void형 포인터 변수를 선언하게 되면 변수, 함수, 포인터 변수까지도 저장 가능
- 일단 void형 포인터에 주소 값을 저장 ->  이후 형 변환을 통해서 포인터의 타입은 나중에 결정

일반적인 경우(형변환 필요 없음)
```.c
int fct1(int num1);
double fct2(double num1, double num2);
 
int main()
{
    //포인터 함수 선언
    int(*point_fct1)(int) = fct1;    
    double(*point_fct2)(double, double) = fct2;
 
    //포인터 함수를 통한 호출
    point_fct1(1);
    point_fct2(1.0, 1.0);
}
 
int fct1(int num1)    // 반환형이 int형이며 전달 인자 int형 변수 하나
{
    num1++;
    return num1;
}
 
double fct2(double num1, double num2) //반환형이 double형이고 전달 인자 double형 변수 두 개
{
    num1 = num1 + num2;
    return num1;
}
```

형변환이 필요한 경우(void* 를 활용)
```.c
int main()
{
    double num1 = 1.0;
    int num2 = 1;
 
    void *pointer;        //void형 포인터 선언
    pointer1 = &num1;    //void형 포인터에 int형 변수의 주소 저장
    pointer2 = &num2;    //void형 포인터에 double형 변수 주소 저장
    *((int*)pointer1) = 10;    // 값을 변경하기 위해서는 int*형으로 형변환
}
```
<정리>
-   따라서 해당 문제도 일단 각각 함수를 만들 때 함수에 맞는 자료형을 부여할 것
-   연결 시 (void *)활용

```.c
    void btree_insert_data(t_btree **root, void *item, int (*cmpf)(void*, void*));

    int ft_strcmp(char *s1, char *s2);

    int main()
    {

        ...

        btree_insert_data(&node, item, (void*)ft_strcmp);
    }
```

## ex05
### btree_search_data
### (t_btree * root, void * data_ref, int (*cmpf)(void *, void *)))
>   infix로 data 탐색

```.c
void    *btree_search_item(t_btree *root, void *data_ref, \
        int (*cmpf)(void *, void *))
{
    void    *find;

    find = 0;
    if (root)
    {
        find = btree_search_item(root->left, data_ref, cmpf);   // 재귀를 통해 제일 왼쪽으로 이동 0이 나올때 까지
        if (!find && !cmpf(root->item, data_ref))               // find가 0이라는 것은 왼쪽 끝까지 갔다는 것
            find = root->item;                                  // 끝까지 갔으니 함수 적용
        if (!find)      // 아직 find가 0이라는 것은 root->item을 찾지 못했다는 것 오른쪽도 봐야함
            find = btree_search_item(root->right, data_ref, cmpf);  // 오른쪽 재귀를 하더라도 바로 왼쪽부터 확인되도록
    }
    return (find);
}
```

🚨Q) 요소를 찾을 수 없을 때 NULL 반환이 안되고 오류가 뜬다[문제 미해결]()

## ex06
### btree_level_count(t_btree * root)
>   트리의 가장 큰 브랜치 크기 반환 함수

```.c
    int reculsive_count(t_btree * root)
    {
        if (root)
        {
            if (reculsive_count(root->left) > reculsive_count(root->right))
                return (1 + reculsive_count(root->left));
            else
                return (1 + reculsive_count(root->right));
        }
        return (0);
    }
```
> 브랜치가 최 하단까지 내려가 0을 찍고 올라오는 과정에서 각각의 왼, 오 크기가 비교되어 count 된다
머릿속으로 재귀 상상하기

## ex07
### btree_level_count(t_btree * root)
>  
