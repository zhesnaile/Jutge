#!/usr/bin/env lua

mi_char = io.read("*l")
char2 = mi_char:upper()
print (char2 == mi_char and mi_char:lower() or char2)
