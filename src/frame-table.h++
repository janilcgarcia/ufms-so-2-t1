#ifndef _FRAME_TABLE_HPP_
#define _FRAME_TABLE_HPP_

#include <array>
#include <vector>
#include <set>
#include <unordered_map>

#include "page-manager.h++"

/**
 * Frame table, it holds all memory frames and execute some basic
 * operations on them.
 */
class FrameTable
{
private:
        std::vector<std::array<char, 10>> _frames;

        // Maps page numbers to frames indexes
        std::unordered_map<int, int> _page_frame_map;
        // Bimap to ensure fast operations
        std::vector<int> _frame_page_list;
        std::set<int> _empty_frames;

        PageManager &_pages;

public:
        FrameTable(int nframes, PageManager &pages);

        bool has_page(int page_number) const;
        /**
         * Find the first empty frame.
         * @return the first empty frame index or -1 if none exist
         */
        int find_empty() const;

        /**
         * Find frame holding page
         * @param page page number to search for
         * @return the frame number or -1 if none is found
         */
        int find_page(int page) const;

        /**
         * Unloads content of a frame and substitute it a the contents
         * of a new page.
         * @param frame_idx index of the frame
         * @param page_number number of the page with the new content to load
         */
        void swap_frame(int frame_idx, int page_number);

        /**
         * Get the list of pages loaded into the frames
         */
        const std::vector<int> &pages() const;
        /**
         * Get the content of the frames
         */
        const std::vector<std::array<char, 10>> &content() const;

        /**
         * Size of the frame table
         */
        int size() const;
};

inline const std::vector<int> &FrameTable::pages() const
{
        return _frame_page_list;
}

inline const std::vector<std::array<char, 10>> &FrameTable::content() const
{
        return _frames;
}

inline int FrameTable::size() const
{
        return _frames.size();
}

#endif // _FRAME_TABLE_HPP_
