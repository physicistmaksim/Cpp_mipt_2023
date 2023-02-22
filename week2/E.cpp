#include <iostream>
#ifndef N
#define N 10 // actual size of the array
#endif

void mergeArrays(int (&a)[N], int (&b)[N], int (&c)[2 * N])
{
    int k_a = 0, k_b = 0, flag = 0;
    for (int i = 0; i < 2 * N; i++)
    {
        if ((a[k_a] > b[k_b]) and (flag == 0))
        {
            c[i] = b[k_b];
            if (k_b < N - 1)
            {
                k_b++;
            }
            else
            {
                flag = 2;
            }
        }
        else if (flag == 0)
        {
            c[i] = a[k_a];
            if (k_a < N - 1)
            {
                k_a++;
            }
            else
            {
                flag = 1;
            }
        }
        else if (flag == 1)
        {
            c[i] = b[k_b];
            k_b++;
        }
        else
        {
            c[i] = a[k_a];
            k_a++;
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

void printArray(int (&a)[2 * N])
{
    for (int i = 0; i < (2 * N); i++)
    {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;
}

int main()
{
    int a[N];
    int b[N];
    int c[2 * N];
    readArray(a);
    readArray(b);
    mergeArrays(a, b, c);
    printArray(c);
}