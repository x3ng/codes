inc :: Int -> Int
inc x = x + 1

dec :: Int -> Int
dec x = x - 1

addt :: Int -> Int -> Int
addt 0 y = y
addt x y = addt (dec x) (inc y)

addn :: Int -> Int -> Int
addn 0 y = y
addn x y = inc (addn (dec x) y)

main = do
  print (addt 3 7)
  print (addn 3 7)
