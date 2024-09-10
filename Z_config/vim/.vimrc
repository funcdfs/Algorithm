
" ====================================== key map ================================


" better kj for quick Esc
let g:esc_j_lasttime = 0
let g:esc_k_lasttime = 0
function! JKescape(key)
	if a:key=='j' | let g:esc_j_lasttime = reltimefloat(reltime()) | endif
	if a:key=='k' | let g:esc_k_lasttime = reltimefloat(reltime()) | endif
	let l:timediff = abs(g:esc_j_lasttime - g:esc_k_lasttime)
	return (l:timediff <= 0.05 && l:timediff >=0.001) ? "\b\e" : a:key
endfunction
inoremap <expr> j JKescape('j')
inoremap <expr> k JKescape('k')
inoremap <nowait> kj <ESC>
noremap <TAB> %


" Shift+H goto head of the line, Shift+L goto end of the line
nnoremap H ^
nnoremap L $


nnoremap <F5> :set nu! nu?<CR>
nnoremap <F6> :set list! list?<CR>
nnoremap <F7> :set wrap! wrap?<CR>
set pastetoggle=<F8>            
"    when in insert mode, press <F5> to go to
"    paste mode, where you can paste mass data
"    that won't be autoindented
au InsertLeave * set nopaste
nnoremap <F9> :exec exists('syntax_on') ? 'syn off' : 'syn on'<CR>



" leader key is '\' 

nnoremap <leader>q :q<CR>       
" Quickly close the current window

nnoremap <leader>s :w<CR>       
" Quickly save the current file

map <Leader>y ggVG+y            
" Quickly copy all content

map <Leader>d ggdG              
" Quickly delete all content


"Keep search pattern at the center of the screen."
nnoremap <silent> n nzz
nnoremap <silent> N Nzz
nnoremap <silent> * *zz
nnoremap <silent> # #zz
nnoremap <silent> g* g*zz



"Reselect visual block after indent/outdent.调整缩进后自动选中，方便再次操作
vnoremap < <gv 
vnoremap > >gv



" y$ -> Y Make Y behave like other capitals
map Y y$



"Map ; to : and save a million keystrokes
" ex mode commands made easy 用于快速进入命令行
nnoremap ; :




" ================================ with neovide =========================

if exists("g:neovide")
    " Put anything you want to happen only in Neovide here
    set guifont=source_code_pro:h10

    "  let g:neovide_transparency = 0.97
    let g:neovide_scroll_animation_length = 0.2
    let g:neovide_cursor_trail_size = 0.4
endif


set background=dark
" colorscheme oceanic_material



" ==================================  base ==================================

set noeb

" set cursorcolumn  "or set cuc 设置光标所在的列
set cursorline    "or set cul 设置光标所在的行
" cterm 表示原生 vim 设置样式, 设置为 NONE 表示可以自定义设置
" red（红），white（白），black（黑），green（绿），yellow（黄），blue（蓝），purple（紫），
" gray（灰），brown（棕），tan(褐色)，syan(青色)

" 更多高亮颜色设置, 可以:h highlight 查看manual
highlight CursorLine   cterm=NONE ctermbg=NONE ctermfg=NONE guibg=NONE guifg=NONE
highlight CursorColumn cterm=NONE ctermbg=NONE ctermfg=NONE guibg=NONE guifg=NONE

set noswapfile
set mouse=a

set shortmess=a
set cmdheight=2



set nocompatible                " don't bother with vi compatibility
set autoread                    " reload files when changed on disk, i.e. via `git checkout`
set shortmess=atI

set magic                       " For regular expressions turn magic on
set title                       " change the terminal's title
set nobackup                    " do not keep a backup file

set novisualbell                " turn off visual bell
set noerrorbells                " don't beep
set tm=500


" show location
" set cursorcolumn
set cursorline



" movement
set scrolloff=7                 " keep 6 lines when scrolling


" show
set ruler                       " show the current row and column
set number                      " show line numbers
set nowrap
set showcmd                     " display incomplete commands
set showmode                    " display current modes
set showmatch                   " jump to matches when entering parentheses
set matchtime=2                 " tenths of a second to show the matching parenthesis



" search
set hlsearch                    " highlight searches
set incsearch                   " do incremental searching, search as you type
set ignorecase                  " ignore case when searching
set smartcase                   " no ignorecase if Uppercase char present


" tab
set expandtab                   " expand tabs to spaces
set smarttab
set shiftround

" indent
set autoindent smartindent shiftround
set shiftwidth=4
set tabstop=4
set softtabstop=4                " insert mode tab and backspace use 4 spaces


" encoding
set encoding=utf-8
set fileencodings=ucs-bom,utf-8,cp936,gb18030,big5,euc-jp,euc-kr,latin1
set termencoding=utf-8
set ffs=unix,dos,mac
set formatoptions+=m
set formatoptions+=B



" select & complete
set selection=inclusive
set selectmode=mouse,key

set completeopt=longest,menu
set wildmenu                           " show a navigable menu for tab completion"
set wildmode=longest,list,full
set wildignore=*.o,*~,*.pyc,*.class
