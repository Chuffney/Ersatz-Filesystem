#ifndef FILESYSTEM_FILESYSTEM_H
#define FILESYSTEM_FILESYSTEM_H

#include <string>

namespace filesystem
{
    class path
    {
        std::string str;
    public:
        path();
        path(std::string source);

        std::string string() const;
        const char *c_str() const;

        path filename() const;
        path stem() const;
        path extension() const;
    };

    std::ostream &operator<<(std::ostream &, const filesystem::path &);

    bool exists(const filesystem::path &p);
    bool is_directory(const filesystem::path &p);
    namespace
    {
        int tst()
        {
            return 1;
        }
    }
}
#endif //FILESYSTEM_FILESYSTEM_H