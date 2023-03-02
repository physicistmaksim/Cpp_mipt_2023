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

void DoubleSelectSort(int (&a)[N])
{
    int index_min;
    int index_max;
    for (int i = 0; i < N / 2; i++)
    {
        index_min = i;
        index_max = N - 1 - i;
        for (int j = i; j < N - i; j++)
        {
            if (a[j] < a[index_min])
            {
                index_min = j;
            }
            if (a[j] > a[index_max])
            {
                index_max = j;
            }
        }
        if (index_min != i)
        {
            if (index_max == i)
            {
                index_max = index_min;
            }
            swap(a[index_min], a[i]);
        }
        if (index_max != N - 1 - i)
        {
            swap(a[index_max], a[N - 1 - i]);
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
    DoubleSelectSort(a);
    printArray(a);
    return 0;
}