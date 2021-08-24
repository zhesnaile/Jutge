#!/usr/bin/env lua 
function div_with_remainder(a, b)
	local i = math.floor(a/b)
	local j = a%b
	print (string.format("%d %d", i, j))
end

a = io.read("*n")
b = io.read("*n")
div_with_remainder(a, b)
