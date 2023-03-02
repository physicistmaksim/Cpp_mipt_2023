#include <iostream>
#ifndef N
#define N 10 // actual size of the array
#endif

void swap(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

void func(int (&a)[N], int k)
{
    int m = 0;
    for (int i = 0; i < k - 1; i++)
    {
        for (int j = i; j < k; j++)
        {
            if (a[j] < a[m])
            {
                m = j;
            }
        }
        if (m != i)
        {
            swap(a[m], a[i]);
        }
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
    int a[N];
    readArray(a);
    func(a, N);
    printArray(a);
    return 0;
}