--{-# OPTIONS_GHC -O2 #-}
module Main where
import Data.Char
import System.Environment
import Data.List


proc :: String -> String
proc = tail . foldl' fn "\n" where
    fn (l:ls) r | l == '\n' = if isAlpha r then r:l:ls else l:ls
                | otherwise = '\n' : l : ls


--proc = map toLower  . filter isAlpha . 

main :: IO ()
main = do
    [inp,outp] <- getArgs
    input <- readFile inp
    writeFile outp (proc input)