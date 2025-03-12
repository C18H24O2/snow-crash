# flag00

```
$ find / -user flag00 2>/dev/null
/usr/sbin/john

$ cat /usr/sbin/john
cdiiddwpgswtgt

$ # use a +15 caesar shift to get the flag
nottoohardhere
```

We can now login as `flag00` with the password `nottoohardhere`.
