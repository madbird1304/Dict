all: main

main: preproc
	g++ -std=c++11 -O2 ./src/test_tree.cpp -o ./bin/Dict.exe

preproc:
	ghc -O2 ./src/preproc.hs -o ./bin/preproc.exe

clean:
	$(RM) ./src/*.hi ./src/*.stackdump
