#include <iostream>

struct VectorN
{
    int N;
    int *cord = nullptr;
};

int main()
{
    VectorN a, b;
    std::cin >> a.N;
    b.N = a.N;
    a.cord = new int[a.N];
    b.cord = new int[b.N];
    for (int i = 0; i < a.N; ++i)
    {
        std::cin >> a.cord[i];
    }
    for (int i = 0; i < b.N; ++i)
    {
        std::cin >> b.cord[i];
    }
    VectorN c;
    c.N = a.N;
    c.cord = new int[c.N];
    for (int i = 0; i < c.N; ++i)
    {
        c.cord[i] = a.cord[i] + b.cord[i];
    }
    std::cout << c.N;
    for (int i = 0; i < c.N; ++i)
    {
        std::cout << " " << c.cord[i];
    }
    std::cout << std::endl;
    delete[] a.cord;
    delete[] b.cord;
    delete[] c.cord;
    return 0;
}