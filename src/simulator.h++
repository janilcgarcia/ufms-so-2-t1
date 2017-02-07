#ifndef _SIMULATOR_HPP_
#define _SIMULATOR_HPP_

#include <string>
#include <random>

#include "logger.h++"
#include "frame-table.h++"
#include "page-manager.h++"

/**
 * FrameReqStrategy is an strategy which respects a interface with one method:
 * request_page(int page_number)
 * And which constructor takes one parameter of type (FrameTable &)
 */
template<typename FrameReqStrategy>
class Simulator
{
private:
    std::uniform_int_distribution<int> _random;
    PageManager _pages;
    FrameTable _frames;
    std::mt19937_64 _gen;
    FrameReqStrategy _frame_strat;

public:
    Simulator(const std::string &page_root, int pages, int frames);

    void simulate(Logger &logger, int sequence);
};

#include "simulator_impl.h++"

#endif // _SIMULATOR_HPP_
