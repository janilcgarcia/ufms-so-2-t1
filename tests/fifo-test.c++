#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE "FIFO Algorithm Test"
#include <boost/test/unit_test.hpp>

#include <cstring>

#include <page-manager.h++>
#include <frame-table.h++>
#include <req-strategy/fifo-strat.h++>

#include "page-manager-mock.h++"

BOOST_AUTO_TEST_CASE(OnEmptyFramesInsertPage)
{
    PageManagerMock mock;
    FrameTable table(4, mock);
    FifoStrategy fifo(table);

    fifo.request_page(13);

    BOOST_ASSERT_MSG(table.has_page(13),
        "It was suppose to load page 13");

    BOOST_ASSERT_MSG(table.pages()[0] == 13,
        "Page 13 should be on frame 0");

    BOOST_ASSERT_MSG(
        strncmp(table.content()[0].data(), "000000000D", 10) == 0,
        "Page 13 has the wrong content"
    );

    fifo.request_page(19);

    BOOST_ASSERT_MSG(table.has_page(19),
        "The table should have page 19");

    BOOST_ASSERT_MSG(table.pages()[1] == 19,
        "Page 19 should be at frame 1");
}

BOOST_AUTO_TEST_CASE(WhenNoEmptyFramesShouldUnloadOldest)
{
    PageManagerMock mock;
    FrameTable table(4, mock);
    FifoStrategy fifo(table);

    fifo.request_page(1);
    fifo.request_page(2);
    fifo.request_page(3);
    fifo.request_page(4);

    BOOST_ASSERT(table.find_empty() == -1);

    fifo.request_page(5);
    BOOST_ASSERT_MSG(
        !table.has_page(1),
        "Table should have swapped page 1"
    );

    fifo.request_page(2);
    BOOST_ASSERT_MSG(
        table.has_page(2),
        "Table should not have swapped page 2"
    );

    fifo.request_page(8);
    BOOST_ASSERT_MSG(
        !table.has_page(2),
        "Table should have swapped page 2"
    );
}
