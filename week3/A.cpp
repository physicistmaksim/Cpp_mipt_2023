#include <iostream>
#ifndef N
#define N 10 // actual size of the array
#endif

void insert_sort_gap(int (&a)[N], int const begin, int const end, int gap)
{
    for (int i = gap; i < end; i++)
    {
        int temp = a[i];
        int k = i;
        for (; (k >= gap) && (a[k - gap] > temp); k -= gap)
        {
            a[k] = a[k - gap];
        }
        a[k] = temp;
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
    insert_sort_gap(a, 0, N, 1);
    printArray(a);
    return 0;
}