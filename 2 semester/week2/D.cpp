#include <iostream>
#ifndef N
#define N 10 // actual size of the array
#endif

void moveNegativeToEnd(int (&a)[N])
{
    int pos[N] = {0};
    int p = -1;
    int neg[N] = {0};
    int n = -1;
    for (int i = 0; i < N; i++)
    {
        if (a[i] > 0)
        {
            p++;
            pos[p] = a[i];
        }
        else
        {
            n++;
            neg[n] = a[i];
        }
    }
    int k = 0;
    while (pos[k] != 0)
    {
        a[k] = pos[k];
        k++;
    }
    int i = 0;
    while (neg[i] != 0)
    {
        a[k] = neg[i];
        k++;
        i++;
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
    moveNegativeToEnd(a);
    printArray(a);
}