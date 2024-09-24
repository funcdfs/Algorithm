" funcdfs@gmail.com
" china

" ============================ key map ============================
" 
"
"
" nnoremap <F1> :w !clip.exe<CR>
" nnoremap <F2> :set nu! nu?<CR>
" nnoremap <F3> :set list! list?<CR>
" nnoremap <F4> :set wrap! wrap?<CR>
" set pastetoggle=<F5>
" au InsertLeave * set nopaste 
" nnoremap <F6> :exec exists('syntax_on') ? 'syn off' : 'syn on'<CR>
" nnoremap <F7> :w !clip.exe<CR><CR>
" kj for Esc

let g:esc_k_lasttime = 0
let g:esc_j_lasttime = 0
function! KJescape(key)
	if a:key=='k' | let g:esc_k_lasttime = reltimefloat(reltime()) | endif
	if a:key=='j' | let g:esc_j_lasttime = reltimefloat(reltime()) | endif
	let l:timediff = abs(g:esc_k_lasttime - g:esc_j_lasttime)
	return (l:timediff <= 0.05 && l:timediff >=0.001) ? "\b\e" : a:key
endfunction
inoremap <expr> k KJescape('k')
inoremap <expr> j KJescape('j')
inoremap <nowait> kj <ESC>

set timeout
set ttimeout
set timeoutlen=700
set ttimeoutlen=10

" bracket jump 
noremap <TAB> %

" remap U to <C-r> for easier redo
nnoremap U <C-r>

" remove highlight
noremap <silent><leader>/ :nohls<CR>

" Shift+H goto head of the line, Shift+L goto end of the line
nnoremap H ^
nnoremap L $
" in Visual
vnoremap H ^
vnoremap L $
" in waiting such as dL
onoremap h ^
onoremap L $
" in select
xnoremap H ^
xnoremap L $


" Map ; to : and save a million keystrokes
" if in very fast typing, this will may make a lots of eroor touch
" nnoremap ; :

" leader key is '\' 
" Quickly close the current window
nnoremap <leader>q :q<CR>
" Quickly save the current file
nnoremap <leader>w :w<CR>
" Quickly delete all content
nnoremap <Leader>d ggdG
" When normal Mode Quickly copy all content to system clipboard
nnoremap <Leader>c ggVG"+y
" When Visual Mode Quickly copy select content to system clipboard
vnoremap <leader>c "+y



" zen mode Keep search pattern at the center of the screen."
nnoremap <silent> n nzz
nnoremap <silent> N Nzz
nnoremap <silent> * *zz
nnoremap <silent> # #zz
nnoremap <silent> g* g*zz


"Reselect visual block after indent/outdent
vnoremap < <gv 
vnoremap > >gv


" y$ -> Y Make Y behave like other capitals
map Y y$


" save
cmap w!! w !sudo tee >/dev/null %


" ==================================  base ==================================


" syntax
syntax on

" history : how many lines of history VIM has to remember
set history=2000

" filetype
filetype on
" Enable filetype plugins
filetype plugin on
filetype indent on

" base
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
"   set cursorcolumn
set cursorline

" movement
set scrolloff=8                 " keep 8 lines when scrolling


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

" NOT SUPPORT
" fold
set foldenable
set foldmethod=indent
set foldlevel=99
let g:FoldMethod = 0
map <leader>zz :call ToggleFold()<cr>
fun! ToggleFold()
    if g:FoldMethod == 0
        exe "normal! zM"
        let g:FoldMethod = 1
    else
        exe "normal! zR"
        let g:FoldMethod = 0
    endif
endfun

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


" others
set backspace=indent,eol,start  " make that backspace key work the way it should
set whichwrap+=<,>,h,l

" if this not work ,make sure .viminfo is writable for you
if has("autocmd")
  au BufReadPost * if line("'\"") > 1 && line("'\"") <= line("$") | exe "normal! g'\"" | endif
endif

" NOT SUPPORT
" Enable basic mouse behavior such as resizing buffers.
set mouse=a

" ============================ theme and status line ============================

" theme
set background=dark

" set mark column color
hi! link SignColumn   LineNr
hi! link ShowMarksHLl DiffAdd
hi! link ShowMarksHLu DiffChange

" status line
set statusline=%<%f\ %h%m%r%=%k[%{(&fenc==\"\")?&enc:&fenc}%{(&bomb?\",BOM\":\"\")}]\ %-14.(%l,%c%V%)\ %P
set laststatus=2   " Always show the status line - use 2 lines for the status bar
