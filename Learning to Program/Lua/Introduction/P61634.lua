local function gap_year(a)
    if a % 100 == 0 then
        a = a/100
    end
    if a % 4 == 0 then
        return true
    else return false 
    end
end


local x = io.read("*n")
print( gap_year(x) and "YES" or "NO" )