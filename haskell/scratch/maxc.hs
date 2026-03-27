import Test.QuickCheck

mymax :: Int -> Int -> Int
mymax x y 
  | x >= y = x
  | x < y = y

prop_max :: Int -> Int -> Bool
prop_max x y = (x <= (mymax x y)) && (y <= (mymax x y))

main = quickCheck prop_max
