--(**) Rotate a list N places to the left.

--Hint: Use the predefined functions length and (++). 
import Debug.Trace 

rotate xs 0 = xs
rotate (x:xs) n
  | n < 0 = rotate (x:xs) (n + length (x:xs))
  | n > 0 = rotate (xs ++ [x]) (n-1)

main = print (rotate ['a','b','c','d','e','f','g','h'] (-2))
--main = print (rotate ['a','b','c','d','e','f','g','h'] (6))
--main = print (length "abcdefgh")