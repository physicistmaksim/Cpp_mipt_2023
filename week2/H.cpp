#include <iostream>
#ifndef N
#define N 2
#endif

#ifndef M
#define M 3
#endif

void print_transposed(int (&a)[N][M])
{
    for (int i = 0; i < M; i++)
    {
        for (int k = 0; k < N; k++)
        {
            std::cout << a[k][i] << " ";
        }
        std::cout << std::endl;
    }
}

void readArray(int (&a)[N][M])
{
    for (int i = 0; i < N; i++)
    {
        for (int k = 0; k < M; k++)
        {
            std::cin >> a[i][k];
        }
    }
}

void printArray(int (&a)[N][M])
{
    for (int i = 0; i < N; i++)
    {
        for (int k = 0; k < M; k++)
        {
            std::cout << a[i][k] << " ";
        }
        std::cout << std::endl;
    }
}

int main()
{
    int a[N][M];
    // readArray(a);
    // print_transposed(a);
    std::cout << "123" << std::endl;
}