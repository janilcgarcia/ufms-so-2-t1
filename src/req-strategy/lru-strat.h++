#ifndef _REQ_STRATEGY_LRU_STRAT_H_
#define _REQ_STRATEGY_LRU_STRAT_H_

#include <cstdint>
#include <list>

#include "frame-table.h++"

class LruStrategy
{
private:
    FrameTable &_table;
    std::size_t _misses;
    std::list<int> _frame_queue;

public:
    LruStrategy(FrameTable &table);

    void request_page(int page_number);

    const std::size_t misses() const;
};

inline const std::size_t LruStrategy::misses() const
{
    return _misses;
}

#endif // _REQ_STRATEGY_LRU_STRAT_H_
