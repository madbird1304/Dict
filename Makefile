all: main

main: preproc
	g++ -std=c++11 ./src/test_tree.cpp -o ./bin/Dict.exe

preproc:
	ghc ./src/preproc.hs -o ./bin/preproc.exe

clean:
	$(RM) ./src/*.hi ./src/*.stackdump
