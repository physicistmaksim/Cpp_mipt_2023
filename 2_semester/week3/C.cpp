#include <iostream>
#ifndef N
#define N 10 // actual size of the array
#endif

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

void swap(int &a, int &b)
{
    int m = a;
    a = b;
    b = m;
}

void reverse(int (&a)[N], int k)
{
    for (int i = 0; i < (k + 1) / 2; i++)
    {
        swap(a[i], a[k - i]);
    }
}

void pancake_sort(int (&a)[N])
{
    for (int n = N; n > 1; n--)
    {
        int i_max = n - 1;
        for (int j = 0; j < n; j++)
        {
            if (a[j] > a[i_max])
            {
                i_max = j;
            }
        }
        if (i_max != n - 1)
        {
            reverse(a, i_max);
            reverse(a, n - 1);
        }
    }
}

int main()
{
    int a[N];
    readArray(a);
    pancake_sort(a);
    printArray(a);
    return 0;
}