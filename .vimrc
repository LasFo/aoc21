set visualbell
set ttimeoutlen=5
syntax on
au BufNewFile,BufRead shader.*,*.glsl setf glsl

set rnu nu
set hlsearch
set smartcase
set ignorecase
set tabstop=4 softtabstop=4
set shiftwidth=4
set expandtab
set ruler
set autochdir

set colorcolumn=80
highlight ColorColumn ctermbg=0 guibg=lightgrey

set updatetime=250

" highlight the word under cursor (CursorMoved is inperformant)
autocmd CursorHold * call HighlightCursorWord()
function! HighlightCursorWord()
    " if hlsearch is active, don't overwrite it!
    let search = getreg('/')
    let cword = expand('<cword>')
    if match(cword, search) == -1
        exe printf('match StatusLineTerm /\V\<%s\>/', escape(cword, '/\'))
    endif
endfunction
hi Search cterm=bold ctermfg=128

highlight DiffAdd    cterm=bold ctermfg=10 ctermbg=17 gui=none guifg=bg guibg=Red
highlight DiffDelete cterm=bold ctermfg=10 ctermbg=17 gui=none guifg=bg guibg=Red
highlight DiffChange cterm=bold ctermfg=10 ctermbg=17 gui=none guifg=bg guibg=Red
highlight DiffText   cterm=bold ctermfg=10 ctermbg=88 gui=none guifg=bg guibg=Red
filetype plugin indent on

call plug#begin('~/.vim/plugged')

Plug 'ycm-core/YouCompleteMe'

call plug#end()
set background=dark
let g:ycm_enable_diagnostic_signs = 0
let g:ycm_enable_diagnostic_highlighting = 0
set completeopt-=preview

let mapleader=' '

nnoremap <leader>s :syntax sync fromstart<CR>

nnoremap <leader>h :wincmd h<CR>
nnoremap <leader>j :wincmd j<CR>
nnoremap <leader>k :wincmd k<CR>
nnoremap <leader>l :wincmd l<CR>

let target = '//:main'
nnoremap <leader>t :exec '!cat input \|  bazel.exe run '.target<CR>

vnoremap J :m '>+1<CR>gv=gv
vnoremap K :m '<-2<CR>gv=gv

fun! TrimWhitespace()
    let l:save = winsaveview()
    keeppatterns %s/\s\+$//e
    call winrestview(l:save)
endfun

autocmd BufWritePre * :call TrimWhitespace()
