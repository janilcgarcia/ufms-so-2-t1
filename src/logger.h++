#ifndef _LOGGER_HPP_
#define _LOGGER_HPP_

#include "frame-table.h++"

/**
 * Logger for the simulator. It is *not* a logger for the entire application,
 * it only has the responsabilty of printing status of the simulation.
 */
class Logger
{
public:
    /**
     * Print a simple message. This is the base for the other functions.
     */
    virtual void message(const std::string &) = 0;

    /**
     * Print information about one frame.
     * @param frame frame index in the table
     * @param page page number of the page contained in the frame
     * @param content content of the page
     */
    virtual void frame(int frame, int page, const char *content);

    /**
     * Print a colleciton of frames contained inside a frame table
     */
    virtual void frames(const FrameTable &frame_table);
};

#endif // _LOGGER_HPP_
