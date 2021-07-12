" 自动补全括号
imap ( ()<Left>
imap [ []<Left>
imap {<CR> {}<Left><CR><Tab><CR><Esc><Up><S-A>
inoremap " ""<Left>
inoremap ' ''<Left>

nmap <Enter> o 

" esc 键更新为 jj
inoremap jj <esc>

" 缩进为4
set tabstop=4
set softtabstop=4
set shiftwidth=4
" 将tab键转换为空白
set expandtab
" 自动填充部分缩进内容
set autoindent


" 同步Windows和暂存器的剪切板
set clipboard=unnamed

" 开启搜索高亮
set hlsearch

" 当前行增加下划线
set cursorline

" 开启
set number

" 面包屑大于 2 时开启
set showtabline=1

" 新窗口位置移动到下面和右侧 new vnew
set splitbelow
set splitright

" 搜索的时候是不完全匹配。忽略大小写
set ignorecase

" 搜索字符实时匹配
set incsearch
set smartcase

" colorscheme

filetype on
filetype indent on
filetype plugin on

set scrolloff=4
set showcmd 

" 去除括号高亮，太难看了
" :NoMatchParen
let loaded_matchparen=1
set noswapfile
