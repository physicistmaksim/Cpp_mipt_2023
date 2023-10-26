#include <iostream>
#ifndef N
#define N 10 // actual size of the array
#endif

void shiftRight(int (&a)[N])
{
    int a_1 = a[N - 1];
    for (int i = N - 1; i > 0; i--)
    {
        a[i] = a[i - 1];
    }
    a[0] = a_1;
}

void readArray(int (&a)[N])
{
    for (int i = 0; i < N; i++)
    {
        std::cin >> a[i];
    }
}

void printArray(int (&a)[N])
{
    for (int i = 0; i < N; i++)
    {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;
}

int main()
{
    int a[N];
    readArray(a);
    shiftRight(a);
    printArray(a);
}