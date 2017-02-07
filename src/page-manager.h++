#ifndef _PAGE_MANAGER_HPP_
#define _PAGE_MANAGER_HPP_

#include <iostream>
#include <string>
#include <random>
#include <fstream>

#include <sys/types.h>
#include <sys/stat.h>

/**
 * A manager for the pages in the hard drive. This manager creates pages
 * and loads them.
 * This implementation uses pages as files of exactly 10B in the hd
 * and reads them to memory.
 */
class PageManager
{
private:
    std::string _root;

    template<typename T>
    void _generate_sequence(char *seq, int n, T gen_function);

public:
    PageManager(const std::string &root);
    virtual ~PageManager();

    template<typename T>
    void create_pages(int n, T random);
    virtual void get_content(char *frame, int pagen);
};

template<typename T>
void PageManager::_generate_sequence(char *seq, int n, T gen_function)
{
    for (int i = 0; i < 10; i++)
    {
        int c = gen_function() & 0xFF;

        while ((c < 'A' || c > 'Z')
                && (c < 'a' || c > 'z')
                && (c < '0' || c > '9'))
        {
            c = gen_function() & 0xFF;
        }

        seq[i] = static_cast<char>(c);
    }
}

template<typename T>
void PageManager::create_pages(int n, T random)
{
    char content[10];
    struct stat finfo;

    for (int i = 0; i < n; i++)
    {
        std::string filename = _root + "/" + std::to_string(i);
        if (stat(filename.c_str(), &finfo) == 0)
        {
            continue;
        }

        _generate_sequence(content, n, random);

        std::ofstream out { filename };
        out.write(content, 10);
        out.close();
    }
}

#endif // _PAGE_MANAGER_HPP_
