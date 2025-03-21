# flag13

The home of this user contains a suid file named `level13`. When we try to run it, it boots us off:
```
level13@SnowCrash:~$ ./level13
UID 2013 started us but we we expect 4242
```

The executable won't do anything else while the UID isn't 4242.
We can run the executable in gdb, and see that `getuid()` is called, and then compared to `4242`, all we then have to do is modify the value saved in the register after the function call, and set it to 4242, the executable then gives us our flag.

```
level13@SnowCrash:~$ gdb ./level13
...
(gdb) b getuid
Breakpoint 1 at 0x400d0c: file level13.c, line 10.
(gdb) r
...
(gdb) p $eax
$1 = 2013
(gdb) set $eax = 4242
(gdb) c
<flag>
```

We can now log in as `level14`.
