#ifndef _STREAM_LOGGER_HPP_
#define _STREAM_LOGGER_HPP_

#include <ostream>
#include "logger.h++"

/**
 * A simulator log using c++ std streams
 */
class StreamLogger : public Logger
{
private:
    std::ostream &_out;
public:
    /**
     * Creates a new stream logger using an ostream.
     * @param out the output stream, it must outlives this object.
     */
    StreamLogger(std::ostream &out);

    /**
     * This class only implements message, and use default implementation
     * in the superclass Logger.
     */
    virtual void message(const std::string &str) override;
};

#endif // _STREAM_LOGGER_HPP_
