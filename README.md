page-simulator
--------------

  Simulates a sequence of page requests using both LRU
and FIFO algorithms.

  To compile and run use these commands:
```
mkdir build
cd build
../configure
make -j5
src/pagesim
```

  Unit tests are available for both algorithms in tests,
to run them use `make check`.

