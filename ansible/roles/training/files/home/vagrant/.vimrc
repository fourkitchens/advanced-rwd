"Enable filetype detection
:filetype on

"General settings
set background=dark         "Dark background"
set fileformats=unix        "Use Unix line endings
set smartindent             "Smart autoindenting on new line
set smarttab                "Respect space/tab settings
set history=300             "Number of commands to remember
set showmode                "Show whether in Visual, Replace, or Insert Mode
set showmatch               "Show matching brackets/parentheses
set backspace=2             "Use standard backspace behavior
set ruler                   "Show line and column number
set formatoptions=1         "Don't wrap text after a one-letter word
set linebreak               "Break lines when appropriate

"Drupal settings
set expandtab               "Tab key inserts spaces
set tabstop=2               "Use two spaces for tabs
set shiftwidth=2            "Use two spaces for auto-indent
let php_htmlInStrings = 1   "Syntax highlight for HTML inside PHP strings
let php_parent_error_open = 1 "Display error for unmatch brackets

"Enable syntax highlighting
if &t_Co > 1
  syntax enable
endif

"Set filetype for Drupal PHP files.
if has("autocmd")
  augroup module
    autocmd BufRead,BufNewFile *.module set filetype=php
    autocmd BufRead,BufNewFile *.php set filetype=php
    autocmd BufRead,BufNewFile *.install set filetype=php
    autocmd BufRead,BufNewFile *.inc set filetype=php
    autocmd BufRead,BufNewFile *.profile set filetype=php
    autocmd BufRead,BufNewFile *.theme set filetype=php
  augroup END
endif
syntax on

" Uncomment the following to have Vim jump to the last position when
" reopening a file
if has("autocmd")
 au BufReadPost * if line("'\"") > 0 && line("'\"") <= line("$")
 \| exe "normal! g'\"" | endif
endif

" Highlight long comments and trailing whitespace.
highlight ExtraWhitespace ctermbg=red guibg=red
let a = matchadd('ExtraWhitespace', '\s\+$')
highlight OverLength ctermbg=red ctermfg=white guibg=red guifg=white
let b = matchadd('OverLength', '\(^\(\s\)\{-}\(*\|//\|/\*\)\{1}\(.\)*\(\%81v\)\)\@<=\(.\)\{1,}$')
