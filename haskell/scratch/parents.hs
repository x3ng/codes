import Control.Applicative
import Control.Monad (ap, liftM)

data Maybe_ a = Just_ a | Nothing_ String
    deriving (Show)

instance Functor Maybe_ where
    fmap = liftM

instance Applicative Maybe_ where
    -- pure = return
    pure = Just_
    (<*>) = ap

instance Monad Maybe_ where
    -- return x = Just_ x
    return = pure
    (>>=) (Just_ x) f = f x
    (>>=) (Nothing_ s) f = Nothing_ $ s

type Person = String

father :: Person -> Maybe_ Person
father "mom1" = Just_ "grandpa1"
father "mom2" = Just_ "grandpa2"
father p = Nothing_ $ "No father: " ++ p

mother :: Person -> Maybe_ Person
mother "son1" = Just_ "mom1"
mother "son2" = Just_ "mom2"
mother p = Nothing_ $ "No mother: " ++ p

maternalGrandfather :: Person -> Maybe_ Person
maternalGrandfather s = do
    m <- mother s
    father m

main :: IO ()
main = do
    print $ maternalGrandfather "son2"
    print $ maternalGrandfather "son1"
    print $ maternalGrandfather "unknown"
