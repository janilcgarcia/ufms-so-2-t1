#include "frame-table.h++"

#include <algorithm>

FrameTable::FrameTable(int nframes, PageManager &manager)
        : _frames {}, _pages(manager),
          _page_frame_map {}, _frame_page_list {}, _empty_frames {}
{
        _frames.resize(nframes);
        _frame_page_list.resize(nframes, -1);

        for (int i = 0; i < nframes; i++)
        {
                _empty_frames.insert(i);
        }
}

bool FrameTable::has_page(int page_number) const
{
        return (_page_frame_map.find(page_number) != _page_frame_map.end());
}

int FrameTable::find_empty() const
{
        if (_empty_frames.empty())
        {
                return -1;
        }
        else
        {
                return *(_empty_frames.begin());
        }
}

int FrameTable::find_page(int page) const
{
        auto it = _page_frame_map.find(page);
        
        return (it != _page_frame_map.end()
                ? it->second
                : -1);
}

void FrameTable::swap_frame(int frame_idx, int page_number)
{
        if (_empty_frames.find(frame_idx) != _empty_frames.end())
        {
                _empty_frames.erase(frame_idx);
        }
        if (_frame_page_list[frame_idx] >= 0)
        {
                _page_frame_map.erase(_frame_page_list[frame_idx]);
        }

        _pages.get_content(_frames[frame_idx].data(), page_number);
        _page_frame_map[page_number] = frame_idx;
        _frame_page_list[frame_idx] = page_number;
}
