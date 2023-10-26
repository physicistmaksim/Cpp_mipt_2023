#include <iostream>
#include <chrono>
#include <random>
const int N = 500000;

int func(int (&a)[N], int k)
{
    int start = 0, end = k - 1, m;
    while (start <= end)
    {
        m = (start + end) / 2;
        if (a[m] < k)
        {
            start = m + 1;
        }
        else if (a[m] > k)
        {
            end = m - 1;
        }
        else
        {
            return m;
        }
    }
    return -1;
}
int main()
{
    int arr[N] = {0}; // number array
    for (int i = 0; i < N; i++)
    {
        arr[i] = i + 1;
    }
    for (int k = 100; k < 5000; k = k + 100)
    {
        auto begin = std::chrono::steady_clock::now();
        for (unsigned cnt = 1000; cnt != 0; --cnt)
            func(arr, k); // binary search bad case
        auto end = std::chrono::steady_clock::now();
        std::chrono::duration<double> time_span = end - begin;

        std::cout << k << "," << time_span.count() << std::endl;
    }
    for (int k = 5000; k < N; k = k + 1000)
    {
        auto begin = std::chrono::steady_clock::now();
        for (unsigned cnt = 1000; cnt != 0; --cnt)
            func(arr, k); // binary search bad case
        auto end = std::chrono::steady_clock::now();
        std::chrono::duration<double> time_span = end - begin;

        std::cout << k << "," << time_span.count() << std::endl;
    }
    return 0;
}