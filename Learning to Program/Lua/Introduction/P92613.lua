#!/usr/bin/env lua

function round(num, numDecimalPlaces)
  local mult = 10^(numDecimalPlaces or 0)
  return math.floor(num * mult + 0.5) / mult
end

x = io.read("*n")
mi_suelo = math.floor(x)
mi_ceil = math.ceil(x)
mi_round = round(x, 0)

print (string.format("%d %d %d", mi_suelo, mi_ceil, mi_round))
