#!/usr/bin/env lua

x = io.read("*n")

h = math.floor(x/3600)
m = math.floor((x%3600)/60)
s = x%60

print ( string.format("%d %d %d", h, m, s))
