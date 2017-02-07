#include "simulator.h++"
#include <stdexcept>
#include <sys/types.h>
#include <sys/stat.h>

template<typename FRS>
Simulator<FRS>::Simulator(const std::string &page_root, int pages, int frames)
    : _random { 0, pages - 1 }, _pages { page_root },
      _frames { frames, _pages }, _frame_strat(_frames)
{
    // Use a mersenne twister with 64 bits and a random seed available.
    _gen = std::mt19937_64 { std::random_device()() };

    struct stat finfo;

    // Try to create a page dir if none exists
    if (stat(page_root.c_str(), &finfo) == -1)
    {
        if (mkdir(page_root.c_str(), 0755) == -1)
        {
            throw std::runtime_error("Couldn't create dir: " + page_root);
        }
    }
    else
    {
        if (!S_ISDIR(finfo.st_mode))
        {
            throw std::runtime_error(
                "File \"" + page_root + "\" is not a directory!");
        }
    }

    std::uniform_int_distribution<int> random;

    // Create pages with random content
    _pages.create_pages(pages, [&random, this]() -> int {
        return random(this->_gen);
    });
}

template<typename FSR>
void Simulator<FSR>::simulate(Logger &logger, int sequence)
{
    for (int i = 0; i < sequence; i++)
    {
        int next_page = _random(_gen);

        logger.message("Requirindo página: "
            + std::to_string(next_page));

        _frame_strat.request_page(next_page);

        logger.frames(_frames);
        logger.message("\n");
    }

    logger.message("Misses: " + std::to_string(_frame_strat.misses()));
}
