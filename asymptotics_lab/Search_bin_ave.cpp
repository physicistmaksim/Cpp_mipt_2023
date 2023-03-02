#include <iostream>
#include <chrono>
#include <random>
const int N = 500000;

int func(int (&a)[N], int k, int r)
{
    int start = 0, end = k - 1, m;
    while (start <= end)
    {
        m = (start + end) / 2;
        if (a[m] < r)
        {
            start = m + 1;
        }
        else if (a[m] > r)
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
    unsigned seed = 1001;
    std::default_random_engine rng(seed);
    for (int i = 100; i < 500000; i = i + 100)
    {
        double av_bin = 0;
        std::uniform_int_distribution<unsigned> dstr(0, i);
        for (int k = 0; k < 100; k++)
        {
            int r = dstr(rng);

            auto begin = std::chrono::steady_clock::now();
            for (unsigned cnt = 1000; cnt != 0; --cnt)
                func(arr, i, r); // linear search average case
            auto end = std::chrono::steady_clock::now();
            std::chrono::duration<double> time_span = end - begin;

            av_bin = av_bin + time_span.count();
        }
        av_bin = av_bin / 100;

        std::cout << i << "," << av_bin << std::endl;
    }
    return 0;
}