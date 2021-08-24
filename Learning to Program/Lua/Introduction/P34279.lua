#!/usr/bin/env lua

h = io.read("*n")
m = io.read("*n")
s = io.read("*n")

s = (s + 1) % 60

if ( s == 0) then
	m = (m+1) % 60
	if ( m == 0) then 
		h = (h+1)% 24
	end
end


print(string.format("%02d:%02d:%02d", h, m, s))
