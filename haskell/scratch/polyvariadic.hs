class R r where
    sum' :: Integer -> r

instance R Integer where
    sum' x = x

instance (Integral a, R r) => R (a -> r) where
    sum' x y = sum' (x + toInteger y)

main :: IO()
main = do
    print $ ((sum' (1::Integer) (2::Integer) (3::Integer)) :: Integer)
