#!/usr/bin/env lua

x = io.read("*n")
y = io.read("*n")
z = io.read("*n")
a = (x > y and x or y)
print ( a > z and a or z )
