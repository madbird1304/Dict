--{-# OPTIONS_GHC -O2 #-}
{-# LANGUAGE OverloadedStrings #-}
module Main where
import Data.Text as T
import Data.Text.Encoding as E
import Data.ByteString as BS
import Data.Char
import System.Environment



main :: IO ()
main = do
    [inp,outp] <- getArgs 
    input <- (return . E.decodeUtf8) =<< BS.readFile inp
    mapM_ (BS.appendFile outp . E.encodeUtf8 . T.map (\c -> if isAlpha c then c else '\n')) (T.lines input)