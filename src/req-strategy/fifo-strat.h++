#ifndef _REQ_STRATEGY_FIFO_STRAT_HPP_
#define _REQ_STRATEGY_FIFO_STRAT_HPP_

#include <queue>

#include "frame-table.h++"
#include "page-manager.h++"

/**
 * This implements the FIFO straegy for page/frame swapping.
 */
class FifoStrategy
{
private:
    std::queue<int> _frame_queue;
    std::size_t _misses;
    
    FrameTable &_table;

public:
    FifoStrategy(FrameTable &table);

    void request_page(int page_number);

    const std::size_t misses() const;
};

inline const std::size_t FifoStrategy::misses() const
{
    return _misses;
}

#endif // _REQ_STRATEGY_FIFO_STRAT_HPP_
