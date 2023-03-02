#include <iostream>
#include <chrono>
#include <random>
const int N = 10;

void swap(int &a, int &b)
{
    int c = a;
    a = b;
    b = c;
}

bool forward_step_M(int (&a)[N], int const begin_idx, int const end_idx, int const M)
{
    bool swaped = false;
    for (int i = begin_idx; i < end_idx - M + 1; i = i + M)
    {
        if (a[i] > a[i + M])
        {
            swap(a[i], a[i + M]);
            swaped = true;
        }
    }
    return swaped;
}

void comd_sort(int (&a)[N], int k)
{
    int M = (int)(k / (1.24733));
    bool swaped = true;
    while (M != 1)
    {
        swaped = forward_step_M(a, 0, k - 1, M);
        M = (int)(M / (1.24733));
        if (M == 0)
        {
            M = 1;
        }
    }
    M = 1;
    while (swaped)
        swaped = forward_step_M(a, 0, k - 1, M);
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
    int a[N] = {0};
    unsigned seed = 100;
    std::default_random_engine rng(seed);
    std::uniform_int_distribution<int> dstr(0, N);
    for (int j = 0; j < N; j++)
    {
        a[j] = dstr(rng);
    }
    printArray(a);
    comd_sort(a, N);
    printArray(a);
    return 0;
}