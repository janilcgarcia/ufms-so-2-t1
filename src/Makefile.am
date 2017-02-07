
noinst_LTLIBRARIES = libpagesim.la
libpagesim_la_SOURCES = page-manager.c++ frame-table.c++ logger.c++ \
  stream-logger.c++ req-strategy/fifo-strat.c++ req-strategy/lru-strat.c++

bin_PROGRAMS = pagesim
pagesim_SOURCES = main.c++
pagesim_LDADD = libpagesim.la
