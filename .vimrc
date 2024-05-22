" kj Esc
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



" leader key is '\' 
" Quickly close the current window
nnoremap <leader>q :q<CR>

" Quickly save the current file
nnoremap <leader>w :w<CR>

" Quickly copy all content
map <Leader>s ggVG+y

" Quickly delete all content
map <Leader>d ggdG