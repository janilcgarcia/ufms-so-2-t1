#include "logger.h++"

void Logger::frames(const FrameTable &frame_table)
{
    const auto &content = frame_table.content();
    const auto &pages = frame_table.pages();

    this->message("Frame\t\tPágina\t\tConteúdo");

    for (int i = 0; i < frame_table.size(); i++)
    {
        this->frame(i, pages[i], content[i].data());
    }
}

void Logger::frame(int frame, int page, const char *content)
{
    std::string ret = std::to_string(frame) + "\t\t" +
            (page >= 0 ? std::to_string(page) : "(none)") +
            "\t\t" + (page >= 0 ? std::string(content, 10) : "");

    this->message(ret);
}
