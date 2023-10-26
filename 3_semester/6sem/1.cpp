#include <iostream>

template <int N>
struct Fib
{
    static const long long value = Fib<N-1>::value + Fib<N-2>::value;
};

template <>
struct Fib<0>
{
    static const long long value = 1;
};

template <>
struct Fib<1>
{
    static const long long value = 1;
};

long long int fib(int value) //much longer than struct with template
{
    if(value < 2)
        return 1;
    return fib(value - 1) + fib(value - 2);
}

int main()
{
    std:: cout << Fib<5>::value << std::endl;
    return 0;
}