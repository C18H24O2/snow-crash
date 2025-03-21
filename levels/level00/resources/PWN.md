# flag00

We first try and find anything that our user or the flag user has access to:
```
$ find / -user flag00 2>/dev/null
/usr/sbin/john

$ cat /usr/sbin/john
cdiiddwpgswtgt
```

We can use a +15 caesar shift to get the password, we can now login as `flag00`.
