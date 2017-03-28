x `divs` n = (n `mod` x == 0)
helper [] n ct = []
helper (x:xs) n ct 
  | n `divs` ct = [] ++ helper xs n (ct+1)
  | otherwise  = [x] ++ helper xs n (ct+1) 
everyN xs n = helper xs n 1

main = print (everyN "abcdef" 3)