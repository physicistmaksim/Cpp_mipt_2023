#include <iostream>

struct Complex
{
    int re;
    int im;
};

Complex complexMul(const Complex &lhs, const Complex &rhs)
{
    Complex a;
    a.re = (lhs.re) * (rhs.re) - (lhs.im) * (rhs.im);
    a.im = (lhs.re) * (rhs.im) + (rhs.re) * (lhs.im);
    return a;
}

int main()
{
    Complex a, b;
    std::cin >> a.re >> a.im >> b.re >> b.im;

    return 0;
}