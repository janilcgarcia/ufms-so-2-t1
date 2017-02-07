#include "page-manager-mock.h++"

#include <cstdio>
#include <cstring>

PageManagerMock::PageManagerMock()
    : PageManager(".")
{ }

PageManagerMock::~PageManagerMock() { }

void PageManagerMock::get_content(char *frame, int pagen)
{
    char full_string[11];
    sprintf(full_string, "%010X", pagen);

    strncpy(frame, full_string, 10);
}
