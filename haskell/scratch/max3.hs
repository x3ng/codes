max2 :: Ord a => a -> a -> a
max2 x y = if x > y then x else y
max3 :: Ord a => a -> a -> a -> a
max3 x y z = max2 x (max2 y z)

maxThree x y z = max x (max y z)

main = do
  print (max3 1 2 3)
  print (maxThree 1 2 3)
