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
    unsigned seed = 1001;
    std::default_random_engine rng(seed);
    for (int i = 10000; i < 500000; i = i + 10000)
    {

        double av_lin = 0;
        std::uniform_int_distribution<unsigned> dstr(0, i);
        for (int k = 0; k < 100; k++)
        {
            for (int j = 0; j < i; j++)
            {
                arr[j] = dstr(rng);
            }

            auto begin = std::chrono::steady_clock::now();
            for (unsigned cnt = 100; cnt != 0; --cnt)
                func1_bad_average(arr, i); // linear search bad case
            auto end = std::chrono::steady_clock::now();
            auto time_span = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);

            av_lin = av_lin + time_span.count();
        }
        av_lin = av_lin / 100;

        std::cout << i << "," << av_lin << std::endl;
    }
    return 0;
}