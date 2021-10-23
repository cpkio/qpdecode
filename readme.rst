Quoted-Printable Stream Decoder
###############################

A small program allowing to decode Quoted-Printable text from STDIN preserving
any characters that aren't ``=FF`` QP-literal. This is a limitation of
a one-file library (see submodule) I used.

It was written for using in Vim/Neovim like
``%g/\v(%u003d[A-F0-9]{2}){2,}/.!qpdecode/`` (for all file) or just
``:.!qpdecode`` for current string.
