#include "page-manager.h++"
#include "vector"

PageManager::PageManager(const std::string &root)
    : _root { root }
{ }

PageManager::~PageManager()
{}

void PageManager::get_content(char *frame, int pagen)
{
    std::ifstream page_file { _root + "/" + std::to_string(pagen) };

    page_file.read(frame, 10);

    page_file.close();
}
