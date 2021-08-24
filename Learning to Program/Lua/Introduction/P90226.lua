#!/usr/bin/env lua 
local function compara_strings(s1, s2)
	local mi_op = "<"
	if s1 > s2 then
		mi_op = ">"
	elseif s1 == s2 then 
		mi_op = "="
	end
	print(string.format("%s %s %s", s1, mi_op, s2))
end

local string_dinput = io.read("*a")
local t = {}
for word in string_dinput:gmatch("%a+") do table.insert(t, word) end
compara_strings(t[1], t[2])
