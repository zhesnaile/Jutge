#!/usr/bin/env lua 
local function div_with_remainder(a, b)
	local i = math.floor(a/b)
	local j = a%b
	print (string.format("%d %d", i, j))
end

local a = io.read("*n")
local b = io.read("*n")
div_with_remainder(a, b)
