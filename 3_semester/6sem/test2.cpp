#include <iostream>
#include <cassert>

template <unsigned N>
double apply(double (*f)(double), double result)
{
    return apply<N-1>(f, (*f)(result));
}

template <>
double apply<0>(double (*f)(double), double result)
{
    return result;
}


double sqr(double x) {
    return x * x;
}
int main() {
    assert(1.0 == apply<3>(sqr, 1.0));
    assert(256.0 == apply<3>(sqr, 2.0));
    return 0;
}