#include <cassert>
template <typename T>
T error_tpl(T const &a) {
    assert(false);
    return 1; // unreachable code
}

template <>
int error_tpl<int>(int const & a)
{
    return a;
}