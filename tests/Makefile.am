TESTS = fifotest lrutest

check_PROGRAMS = $(TESTS)

fifotest_SOURCES = fifo-test.c++ page-manager-mock.c++
fifotest_CPPFLAGS = -I$(top_srcdir)/src $(BOOST_TEST_CPPFLAGS)
fifotest_LDFLAGS = $(BOOST_LDFLAGS) $(BOOST_UNIT_TEST_FRAMEWORK_LIB)
fifotest_LDADD = ../src/libpagesim.la

lrutest_SOURCES = lru-test.c++ page-manager-mock.c++
lrutest_CPPFLAGS = -I$(top_srcdir)/src $(BOOST_TEST_CPPFLAGS)
lrutest_LDFLAGS = $(BOOST_LDFLAGS) $(BOOST_UNIT_TEST_FRAMEWORK_LIB)
lrutest_LDADD = ../src/libpagesim.la
