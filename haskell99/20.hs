removeAt k xs = [x | (x, i) <- zip xs [1..(length xs)], k /= i]

main = print (removeAt 2 "abcd")