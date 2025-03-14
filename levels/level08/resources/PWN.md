# flag08

level08 contains 2 files in the home directory:

- a `level08` suid executable
- a `token` text file which we don't have the permission to execute

The executable reads a files contents with elevated privileges, the catch is if the filename has `token` anywhere in it, it will not read it
We simply create a symbolic link to the file in `/tmp/` named differently and the flag is ours: 

`ln -s ~/token /tmp/ptdr; ./level08 /tmp/ptdr`

we can now login as `level09`