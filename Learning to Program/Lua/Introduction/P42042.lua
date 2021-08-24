#!/usr/bin/env lua

vowels = "aeiou"

function inspect_letter(c)
	y = c:lower()
	print( y ~= c and "uppercase" or "lowercase")
	if (vowels:find(y) ~= nil) then
		print ("vowel")
	else print("consonant")
	end
end

c = io.read("*l")
inspect_letter(c)
