#ifndef _PAGE_MANAGER_MOCK_HPP_
#define _PAGE_MANAGER_MOCK_HPP_

#include <page-manager.h++>

class PageManagerMock : public PageManager
{
public:
    PageManagerMock();
    virtual ~PageManagerMock();
    virtual void get_content(char *frame, int pagen);
};

#endif // _PAGE_MANAGER_MOCK_HPP_
