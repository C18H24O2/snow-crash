# pwn

The home of this user contains a suid file named `level13`
we try to run it
```
level13@SnowCrash:~$ ./level13
UID 2013 started us but we we expect 4242
```

the executable won't do anything else while the UID isn't 4242
we can run the executable in gdb, and see that `getuid()` is called, and then compared to 4242
all we have to do is modify the value saved in the register after the function call, and set it to 4242, the executable then gives us our flag

we can now log in as `level14`