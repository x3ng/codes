lsumn :: [Int] -> Int
lsumn [] = 0
lsumn (x:xs) = x + lsumn xs

mlsum :: [Int] -> Int
mlsum [x] = x
mlsum (x:y:ns) = mlsum ((x + y):ns)

lsum :: [Int] -> Int -> Int
lsum [] n = n
lsum (n:ns) a = lsum ns (n + a)

nl = [1..9]

main = do
  print(lsum nl 0)
  print(mlsum nl)
  print(lsumn nl)
