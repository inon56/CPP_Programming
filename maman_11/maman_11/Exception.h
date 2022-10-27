#pragma once
#include <exception>

class Exception : public std::exception  {
    private:
        const char* _msg;
    public:
        explicit Exception(const char *e);
        [[nodiscard]] const char * what() const noexcept override;
};

