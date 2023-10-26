#include <iostream>

template <typename A, typename B, typename ...Tail>
struct is_homogeneous
{
    static const bool value = false;
};

template <typename A, typename ...Tail>
struct is_homogeneous<A, A, Tail...>
{
    static const bool value = is_homogeneous<A, Tail...>::value;
};

template <typename A, typename B>
struct is_homogeneous<A, B>
{
    static const bool value = false;
};

template <typename A>
struct is_homogeneous<A, A>
{
    static const bool value = true;
};