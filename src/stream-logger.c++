#include "stream-logger.h++"

StreamLogger::StreamLogger(std::ostream &out)
    : _out(out)
{ }

void StreamLogger::message(const std::string &str)
{
    _out << str << std::endl;
}
