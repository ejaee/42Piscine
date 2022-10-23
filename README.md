📌 [norminette](https://github.com/42School/norminette/blob/master/pdf/ko.norm.pdf)<br>


```.vim
"<home>
set tabstop=4
set shiftwidth=4 ">>, <<키로 들여/내어쓰기 할 때, 스페이스 개수"
set cindent
set number

map <buffer> <F2> :w<CR>
map <buffer> <F3> :!norminette -R CheckForbiddenSourceHeader *.*<CR>
map <buffer> <F4> :!gcc -Wall -Werror -Wextra *.c && ./a.out<CR>
© 2022 GitHub, Inc.
Terms
Privacy
Security
Status
Docs
Contact GitHub

```
