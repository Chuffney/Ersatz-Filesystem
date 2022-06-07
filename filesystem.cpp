#include <windows.h>

#include <utility>
#include "filesystem.h"

filesystem::path::path()
= default;

filesystem::path::path(std::string source)
{
    path::str = std::move(source);
}

std::string filesystem::path::string() const
{
    return str;
}

const char* filesystem::path::c_str() const
{
    return str.c_str();
}

filesystem::path filesystem::path::filename() const
{
    for (int i = (int) str.length() - 1; i >= 0; i--)
    {
        if (str[i] == '/')
        {
            return path(str.substr(i, str.length() - i));
        }
    }
    return path(str);
}

filesystem::path filesystem::path::extension() const
{
    for (int i = (int) str.length() - 1; i >= 0; i--)
    {
        if (str[i] == '.')
        {
            return path(str.substr(i, str.length() - i));
        }
    }
    return path("");
}

std::ostream &filesystem::operator<<(std::ostream &os, const filesystem::path &p)
{
    os << p.string();
    return os;
}


bool filesystem::exists(const filesystem::path &p)
{
    LPCSTR handle = p.filename().c_str();
    if (CreateFileA(handle, 0, 0, nullptr, 3, 128, nullptr) == INVALID_HANDLE_VALUE)
    {
        return false;
    }
    return true;
}

bool filesystem::is_directory(const filesystem::path &p)
{
    LPCSTR handle = p.filename().c_str();
    HANDLE file = CreateFileA(handle,
                              0,
                              0,
                              nullptr,
                              3,
                              128,
                              nullptr);
    BY_HANDLE_FILE_INFORMATION info;
    GetFileInformationByHandle(file, &info);
    return info.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY;
}
