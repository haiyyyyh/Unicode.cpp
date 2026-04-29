# make module
.PHONY : test

unicode.pcm : unicode.cppm
	clang++ unicode.cppm -o unicode.pcm --precompile -std=c++23 -stdlib=libstdc++

test : test.cpp
	@clang++ test.cpp -o ./test.out -O0 -g -std=c++23 -stdlib=libstdc++ -fprebuilt-module-path=.
	@./test.out
	@rm ./test.out