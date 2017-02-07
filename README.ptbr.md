page-simulator
--------------

  Simulador de páginas de memória usando ambos LRU
e FIFO como algoritmos.

  Para compiler e executar, execute esses commandos:
```
mkdir build
cd build
../configure
make -j5
src/pagesim
```

  Existem testes de unidade para ambos algoritmos
no diretório `tests`. Para rodá-los, entre na pasta
`build` e execute `make check`.

