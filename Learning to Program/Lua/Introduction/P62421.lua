#!/usr/bin/env lua

string_dinput = io.read("*a")
t = {}
for word in string_dinput:gmatch("%a+") do table.insert(t, 1, word) end
print (table.concat(t, " "))
