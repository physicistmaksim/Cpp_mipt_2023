#include <iostream>
#include <chrono>
#include <random>
const int N = 500000;

int func1_bad_average(int (&a)[N], int k)
{
    for (int i = 0; i < k; i++)
    {
        if (a[i] == k)
        {
            return a[i];
        }
    }
    return 0;
}
int main()
{
    int arr[N] = {0}; // number array
    for (int i = 0; i < N; i++)
    {
        arr[i] = i + 1;
    }
    for (int k = 100; k < 500000; k = k + 100)
    {
        auto begin = std::chrono::steady_clock::now();
        for (unsigned cnt = 100; cnt != 0; --cnt)
            func1_bad_average(arr, k); // linear search bad case
        auto end = std::chrono::steady_clock::now();
        auto time_span = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);

        std::cout << k << "," << time_span.count() << std::endl;
    }
    return 0;
}