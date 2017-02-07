#include "fifo-strat.h++"

#include <stdio.h>

FifoStrategy::FifoStrategy(FrameTable &table)
    : _frame_queue {}, _table {table}, _misses {0} 
{}

void FifoStrategy::request_page(int page_number)
{
    if (!_table.has_page(page_number)) {
        int frame_idx = _table.find_empty();

	_misses++;

        if (frame_idx < 0) {
            frame_idx = _frame_queue.front();
            _frame_queue.pop();
        }

        _table.swap_frame(frame_idx, page_number);
        _frame_queue.push(frame_idx);
    }
}
