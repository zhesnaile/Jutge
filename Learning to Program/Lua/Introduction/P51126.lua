local function my_intersection(a, b, c, d)
    local x = "[]"
    if b <= d and c <= b then
        if a <= c then
            x =  string.format("%s%d%s%d%s", "[", c, ",", b, "]")
        else x = string.format("%s%d%s%d%s", "[", a, ",", b, "]")
        end
    elseif d <= b and a <= d then
        if c <= a then
            x = string.format("%s%d%s%d%s", "[", a, ",", d, "]")
        else x = string.format("%s%d%s%d%s", "[", c, ",", d, "]")
        end
    end
    print(x)
end

local a0 = io.read("*n")
local b0 = io.read("*n")
local a1 = io.read("*n")
local b1 = io.read("*n")

my_intersection(a0, b0, a1, b1)