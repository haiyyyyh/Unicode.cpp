#! /bin/zsh

set -e

mkdir ./tests

optimize=(-O0 -O1 -O2 -O3)
cc=(clang++ g++)

for opt in "${optimize[@]}" ; do
    clang++ ./test.cpp -o ./tests/test.out $opt -std=c++23 -stdlib=libc++
    echo "cc: clang++ $opt -stdlib=libc++"
    time ./tests/test.out
done

for _cc in "${cc[@]}" ; do
    for opt in "${optimize[@]}" ; do
        $_cc ./test.cpp -o ./tests/test.out $opt -std=c++23
        echo "cc: $_cc $opt"
        time ./tests/test.out
    done
done

rm -rf ./tests