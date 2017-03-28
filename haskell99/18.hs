--(**) Extract a slice from a list.
--Given two indices, i and k, the slice is the list containing the elements between the i'th and k'th element of the original list (both limits included). Start counting the elements with 1. 

slice [] _ _ = []
slice xs 1 0 = []
slice (x:xs) 1 k = x : slice xs 1 (k-1)
slice (x:xs) i k = slice xs (i-1) (k-1)

main = print (slice ['a','b','c','d','e','f','g','h','i','k'] 3 7)