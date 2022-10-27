#include "Exception.h"

Exception::Exception(const char *e) {
    _msg = e;
}

const char * Exception::what() const noexcept {
    return _msg;
}