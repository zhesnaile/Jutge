#!/usr/bin/env lua 
function check_temperature(x)
	if (x <10) then 
		print("it's cold")
		if (x <= 0) then
			print("water would freeze")
		end
	elseif( x > 30 ) then
		print("it's hot")
		if ( x >= 100 ) then
			print("water would boil")
		end
	else 
		print ("it's ok")
	end
end

x = io.read("*n")
check_temperature(x)
