#include <iostream>
#include <chrono>
#include <random>
const int N = 100000;

int func(int (&a)[N], int k, int S)
{
    for (int i = 0; i < k; i++)
    {
        int q = a[i];
        for (int j = 0; j < k; j++)
        {
            if (i != j && a[j] + a[i] == S)
            {
                return 1;
            }
        }
    }
    return -1;
}
int main()
{
    int arr[N] = {0};
    int S = -1;
    for (int k = 100; k < 1000; k = k + 100)
    {
        auto begin = std::chrono::steady_clock::now();
        for (unsigned cnt = 10; cnt != 0; --cnt)
            func(arr, k, S);
        auto end = std::chrono::steady_clock::now();
        std::chrono::duration<double> time_span = end - begin;

        std::cout << k << "," << time_span.count() << std::endl;
    }
    for (int k = 1000; k < N; k = k + 1000)
    {
        auto begin = std::chrono::steady_clock::now();
        for (unsigned cnt = 10; cnt != 0; --cnt)
            func(arr, k, S);
        auto end = std::chrono::steady_clock::now();
        std::chrono::duration<double> time_span = end - begin;

        std::cout << k << "," << time_span.count() << std::endl;
    }
    return 0;
}