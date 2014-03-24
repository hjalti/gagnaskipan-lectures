if &cp | set nocp | endif
let s:cpo_save=&cpo
set cpo&vim
inoremap <silent> <S-Tab> =UltiSnips_JumpBackwards()
inoremap <silent> <C-Tab> =UltiSnips_ListSnippets()
imap <silent> <Plug>IMAP_JumpBack =IMAP_Jumpfunc('b', 0)
imap <silent> <Plug>IMAP_JumpForward =IMAP_Jumpfunc('', 0)
map! <S-Insert> <MiddleMouse>
nmap v :call Screen_Vars()
nmap  vip
vmap  "ry:call Send_to_Screen(@r)
nnoremap  :call NumberToggle()
xnoremap 	 :call UltiSnips_SaveLastVisualSelection()gvs
snoremap <silent> 	 :call UltiSnips_ExpandSnippetOrJump()
vmap <NL> <Plug>IMAP_JumpForward
nmap <NL> <Plug>IMAP_JumpForward
nnoremap  :cn
nnoremap <silent>  :CtrlPMixed
map ,t <Plug>TaskList
nnoremap ," viwa"hbi"lel
nnoremap ,sv :source $MYVIMRC
nnoremap ,ev :vsplit $MYVIMRC
noremap ,J :wincmd J
noremap ,L :wincmd L
noremap ,K :wincmd K
noremap ,H :wincmd H
noremap ,wr r
noremap ,wc :wincmd q
noremap ,j :call WinMove('j')
noremap ,l :call WinMove('l')
noremap ,k :call WinMove('k')
noremap ,h :call WinMove('h')
map <,-Enter> O
noremap P :TlistToggle
map Q gq
xmap S <Plug>VSurround
noremap T :TaskList
noremap Y y$
vmap [% [%m'gv``
vmap ]% ]%m'gv``
vmap a% [%v]%
nmap cs <Plug>Csurround
nmap ds <Plug>Dsurround
nmap gx <Plug>NetrwBrowseX
xmap gS <Plug>VgSurround
nmap j gj
nmap k gk
xmap s <Plug>Vsurround
nmap ySS <Plug>YSsurround
nmap ySs <Plug>YSsurround
nmap yss <Plug>Yssurround
nmap yS <Plug>YSurround
nmap ys <Plug>Ysurround
nnoremap <silent> <Plug>NetrwBrowseX :call netrw#NetrwBrowseX(expand("<cWORD>"),0)
snoremap <silent> <BS> c
snoremap <silent> <C-Tab> :call UltiSnips_ListSnippets()
snoremap <silent> <S-Tab> :call UltiSnips_JumpBackwards()
vmap <silent> <Plug>IMAP_JumpBack `<i=IMAP_Jumpfunc('b', 0)
vmap <silent> <Plug>IMAP_JumpForward i=IMAP_Jumpfunc('', 0)
vmap <silent> <Plug>IMAP_DeleteAndJumpBack "_<Del>i=IMAP_Jumpfunc('b', 0)
vmap <silent> <Plug>IMAP_DeleteAndJumpForward "_<Del>i=IMAP_Jumpfunc('', 0)
nmap <silent> <Plug>IMAP_JumpBack i=IMAP_Jumpfunc('b', 0)
nmap <silent> <Plug>IMAP_JumpForward i=IMAP_Jumpfunc('', 0)
nnoremap <Plug>FireplaceSource :Source 
noremap <F12> :!ctags -R --c++-kinds=+p --fields=+iaS --extra=+q .
noremap <F4> :e %:p:s,.h$,.X123X,:s,.cpp$,.h,:s,.X123X$,.cpp,
nnoremap <F9> :exec ‘vimgrep /\<’.expand(’<cword>’).’\>/g **/*.xml **/*.java’
map <F7> :!python % 
map <F10> :!g++ -Wall -pedantic *.cpp && valgrind ./a.out 
vmap <F9> :!g++ -Wall -pedantic % && valgrind ./a.out 
omap <F9> :!g++ -Wall -pedantic % && valgrind ./a.out 
nnoremap <silent> <F8> :TlistToggle
map <S-Insert> <MiddleMouse>
imap S <Plug>ISurround
imap s <Plug>Isurround
inoremap <silent> 	 =UltiSnips_ExpandSnippetOrJump()
imap <NL> <Plug>IMAP_JumpForward
imap  <Plug>Isurround
inoremap jk 
cnoremap w!! %!sudo tee > /dev/null %
abbr hks Helgi Kristvin Sigurbjarnarson
let &cpo=s:cpo_save
unlet s:cpo_save
set autoindent
set autowrite
set backspace=indent,eol,start
set backup
set backupdir=~/.vimtmp/vimswaps
set completeopt=menuone,menu,longest,preview
set fileencodings=ucs-bom,utf-8,default,latin1
set formatoptions=ql
set grepprg=grep\ -nH\ $*
set helplang=en
set hidden
set history=100
set hlsearch
set ignorecase
set incsearch
set mouse=a
set omnifunc=omni#cpp#complete#Main
set ruler
set runtimepath=~/.vim/bundle/rainbow_parentheses.vim,~/.vim/bundle/paredit.vim,~/.vim/bundle/vim-fireplace,~/.vim/bundle/vim-clojure-static,~/.vim/bundle/vim-classpath,~/.vim/bundle/pyflakes.vim,~/.vim/bundle/ack.vim,~/.vim/bundle/ctrlp.vim,~/.vim,/usr/share/vim/vimfiles,/usr/share/vim/vim74,/usr/share/vim/vimfiles/after,~/.vim/after'
set shiftwidth=4
set smartcase
set softtabstop=4
set suffixes=.bak,~,.swp,.o,.info,.aux,.log,.dvi,.bbl,.blg,.brf,.cb,.ind,.idx,.ilg,.inx,.out,.toc
set tabstop=4
set tags=./tags,./TAGS,tags,TAGS,~/.vim/tags/cpp,~/.vim/tags/gl,~/.vim/tags/sdl,~/.vim/tags/qt4,~/.vim/tags/opencv,~/.vim/tags/opencv2
set textwidth=79
set ttimeout
set ttimeoutlen=50
set undodir=~/.vimtmp/undo
set undofile
set viewdir=~/.vimtmp/view
set viminfo=!,%,'50,\"100,n~/.viminfo
set visualbell
set winminheight=0
" vim: set ft=vim :
