#include <iostream>
#ifndef N
#define N 10 // actual size of the array
#endif

void shiftRight(int (&a)[N], unsigned k)
{
    k = k % N;
    int b;
    int m[N];
    for (int i = 0; i < N; i++)
    {
        m[i] = a[i];
    }
    for (int i = 0; i < N; i++)
    {
        b = k + i;
        while (b > N - 1)
        {
            b = b - N;
        }
        a[b] = m[i];
    }
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
    unsigned k;
    int a[N];
    std::cin >> k;
    readArray(a);
    shiftRight(a, k);
    printArray(a);
}