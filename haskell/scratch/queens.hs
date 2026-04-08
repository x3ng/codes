boardSize :: Int
boardSize = 8

queens :: Int -> [[Int]]
queens 0 = [[]]
queens n = [x:y | y <- (queens (n - 1)), x <- [1 .. boardSize], safe x y 1]
  where
    safe :: Int -> [Int] -> Int -> Bool
    safe x [] _ = True
    safe x (c:y) d = and [x/=c, x/=c+d, x/=c-d, (safe x y (d+1))]

main :: IO()
main = print (queens 8)
