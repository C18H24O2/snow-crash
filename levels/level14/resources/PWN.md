# flag14

## First method

level14 drops us in a fully empty profile, nothing in the user home, and running `find` to get anything owned by the user / the users group yields nothing.

Without anything to use given to us by the subject, we turn to the `getflag` binary.

Exporting our file to the host machine, we can use `ghidra` to decompile the executable.

From there, we look at the main function (see `main.c`) and, after some security measures, find that to get a flag, the main function runs the following pseudo-code:
```c
if (currentUserId == 30xx) { // 30xx is the UID of the flagXX user
    flag = decrypt("encrypted_flag");
    fputs(flag, stdout);
}
```

Here is the code for `level14` (`0xbc6` is `3014`, the UID of the `flag14` user):
```c
else {
    if (_Var6 != 0xbc6) goto LAB_08048e06;
    pcVar4 = (char *)ft_des("g <t61:|4_|!@IF.-62FH&G~DCK/Ekrvvdwz?v|");
    fputs(pcVar4,__stream);
}
```

So the encrypted flag for level 14 is `g <t61:|4_|!@IF.-62FH&G~DCK/Ekrvvdwz?v|` (note: this flag is longer than all previous flags)

We then decompile the `ft_des` function and add a main function to run it on its own (see `ft_des.c`).

We pass our encrypted flag, and get back the actual flag for level 14, completing the challenge :)

## Trollface Emoji

To make sure we did in fact have the right flag, we used a second method to get it.

Looking at the iso, we can notice that it is vulnerable to the [Dirty COW](https://en.wikipedia.org/wiki/Dirty_COW) exploit, that lets a user escalate privilege to `root`-level privileges.

We can find a [GitHub page]((https://github.com/dirtycow/dirtycow.github.io/wiki/PoCs)) listing some ready made code to use the exploit.

From there we can get root privilege, it's as easy as loging in to `flag14` and getting the flag:

```
level14@SnowCrash:~$ cd /tmp/
level14@SnowCrash:/tmp$ vim pwn.c
level14@SnowCrash:/tmp$ gcc -pthread pwn.c -o pwn -lcrypt
level14@SnowCrash:/tmp$ ./pwn
...
level14@SnowCrash:/tmp$ su snowcrash
...
snowcrash@SnowCrash:/tmp# cd
snowcrash@SnowCrash:# su flag14
flag14@SnowCrash:~$ getflag
...
```
and we've confirmed we've got the correct flag!
