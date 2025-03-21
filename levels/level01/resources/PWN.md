# flag01

The password is DES-encrypted in plain sight in `/etc/passwd`.
```
$ cat /etc/passwd | grep flag01
flag01:42hDRfypTqqnw:3001:3001::/home/flag/flag01:/bin/bash
```

We can use tools like John the Ripper to decrypt the password.
```
$ echo 42hDRfypTqqnw > /tmp/pwn.txt
$ john /tmp/pwn.txt --show
?:<password>

1 password hash cracked, 0 left
```

We can now login as `flag01`.
