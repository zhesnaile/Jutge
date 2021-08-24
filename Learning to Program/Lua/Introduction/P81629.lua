#!/usr/bin/env lua

b_values={500, 200, 100, 50, 20, 10, 5}
small_coins={50, 20, 10, 5, 2}


function banknotes(e)
	for i, v in ipairs(b_values) do 
		print (string.format("%s %d %s %d", "Banknotes of", v, "euros:", math.floor(e/v)))
		e = e%v
	end
	print (string.format("%s %d", "Coins of 2 euros:", math.floor(e/2)))
	e = e%2
	print(string.format("%s %d", "Coins of 1 euro:", e))
end

function cents(c)
	for i, v in ipairs(small_coins) do 
		print (string.format("%s %d %s %d", "Coins of", v, "cents:", math.floor(c/v)))
		c = c%v
	end
	print(string.format("%s %d" , "Coins of 1 cent:", c))
end

e = io.read("*n")
c = io.read("*n")

banknotes(e)
cents(c)
