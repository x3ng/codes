import Control.Monad.State

getX :: State Int ()
getX = state $ \s -> ((), s)

incX :: State Int ()
incX = state $ \s -> ((), s + 1)

decX :: State Int ()
decX = state $ \s -> ((), s - 1)

add :: Int -> State Int ()
add a = state $ \s -> ((), s + a)

sub :: Int -> State Int ()
sub a = state $ \s -> ((), s - a)

cStyleCode :: State Int ()
cStyleCode = do
    incX
    decX
    decX
    add 10
    add 10
    sub 10
    getX

main :: IO ()
main = do
    let (finalVal, finalX) = runState cStyleCode 0
    putStrLn $ "final x: " ++ show finalX
