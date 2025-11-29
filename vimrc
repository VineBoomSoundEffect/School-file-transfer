set number
set relativenumber

set tabstop=4
set shiftwidth=4
set expandtab
set ai

syntax on
color ayu
set guifont=Jetbrains_Mono:h15
set guioptions-=m
set guioptions-=T
au GUIEnter * simalt ~x

set belloff=all
command! -nargs=1 ZOOM set guifont=Jetbrains_Mono:h<args>

set laststatus=2
let g:lightline = {
      \ 'colorscheme': 'ayu_dark',
      \   'active': {
      \     'left': [['mode', 'paste'], ['readonly', 'filename', 'modified']],
      \     'right': [['lineinfo'], ['percent'], ['filetype']]
      \   },
      \ }

