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

" bracket jump 
noremap <TAB> %

" remap U to <C-r> for easier redo
nnoremap U <C-r>


set timeout
set ttimeout
set timeoutlen=500
set ttimeoutlen=10

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


" remove highlight
noremap <silent><leader>/ :nohls<CR>


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


"Reselect visual block after indent/outdent.调整缩进后自动选中，方便再次操作
vnoremap < <gv 
vnoremap > >gv


" y$ -> Y Make Y behave like other capitals
map Y y$

" save
cmap w!! w !sudo tee >/dev/null %
