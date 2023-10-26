#include <iostream>

using namespace std;

template<typename T>
T min(T &a, T &b)
{
    return a < b ? a : b;
}

template<typename T>
T max(T &a, T &b)
{
    return a > b ? a : b;
}

template<typename T>
bool greater(T &a, T &b)
{
    return a > b ? true : false;
}

template<typename T>
bool less(T &a, T &b)
{
    return a < b ? true : false;
}

int main()
{
    return 0;
}