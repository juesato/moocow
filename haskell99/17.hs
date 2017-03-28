split xs 0 = ("", xs)
split (x:xs) k = ([x] ++ a, b)
  where (a,b) = split xs (k-1)

main = print (split "abcdefghik" 3)