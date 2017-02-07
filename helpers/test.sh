#!/bin/bash

i=0

if [ -n $4 ]; then
    max_tests=$4
else
    max_tests="40"
fi

if [ ! -d results-$max_tests ]; then
    mkdir -p results-$max_tests
fi

frames=$1
pages=$2
reqs=$3

if [ -z $frames ] || [ -z $pages ] || [ -z $reqs ]; then
    echo 'Usage: test.sh (nframes) (npages) (nreqs) (optional: ntests)'
    exit 1
fi

while [ $i -lt $max_tests ]; do
    src/pagesim pages LRU $frames $pages $reqs > results-$max_tests/lru-$i
    src/pagesim pages FIFO $frames $pages $reqs > results-$max_tests/fifo-$i
    i=$((i + 1))
done

