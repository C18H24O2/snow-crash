#!/usr/bin/env python3

byte_stream = open("token", "rb").read()[:-1]

def algo(byte_stream):
    i = 0 
    ret = []
    for b in byte_stream:
        ret.append((b - i) % 0xff)
        i += 1
    return ret

a = algo(byte_stream)
b = bytes(a).decode("utf-8")
print(b)
