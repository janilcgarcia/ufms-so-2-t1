#include "lru-strat.h++"

LruStrategy::LruStrategy(FrameTable &table)
    : _table(table), _frame_queue {}, _misses {0}
{
}

void LruStrategy::request_page(int page_number)
{
        if (_table.has_page(page_number))
        {
                int frame = _table.find_page(page_number);

                _frame_queue.remove(frame);
                _frame_queue.push_back(frame);
        }
        else
        {
                int empty = _table.find_empty();

		_misses++;

                if (empty < 0)
                {
                        empty = _frame_queue.front();
                        _frame_queue.pop_front();
                }

                _table.swap_frame(empty, page_number);
                _frame_queue.push_back(empty);
        }
}
