#include <iostream>
#include <chrono>
#include <random>
#ifndef N
#define N 500000 // actual size of the array
#endif

int func1_bad_average(int (&a)[N])
{
    for (int i = 0; i < N; i++)
    {
        if (a[i] == N)
        {
            return a[i];
        }
    }
    return 0;
}

int func2_bad(int (&a)[N])
{
    int start_point = 0, end_point = N - 1;
    int point;
    while (end_point - start_point > 2)
    {
        point = (end_point - start_point) / 2 + start_point;
        if (a[start_point] <= N and a[point] >= N)
        {
            end_point = point;
        }
        else
        {
            start_point = point;
        }
    }
    if (end_point - start_point == 2)
    {
        if (a[start_point + 1] == N)
        {
            return start_point + 1;
        }
        else
        {
            return start_point;
        }
    }
    else
    {
        return start_point;
    }
}

int func2_average(int (&a)[N], int r)
{
    int start_point = 0, end_point = N - 1;
    int point;
    while (end_point - start_point > 2)
    {
        point = (end_point - start_point) / 2 + start_point;
        if (a[start_point] <= r and a[point] >= r)
        {
            end_point = point;
        }
        else
        {
            start_point = point;
        }
    }
    if (end_point - start_point == 2)
    {
        if (a[start_point + 1] == r)
        {
            return start_point + 1;
        }
        else
        {
            return start_point;
        }
    }
    else
    {
        return start_point;
    }
}

int main()
{
    int arr[N]; // number array
    for (int i = 0; i < N; i++)
    {
        arr[i] = i + 1;
    }
    unsigned seed = 1001;
    std::default_random_engine rng(seed);
    std::uniform_int_distribution<unsigned> dstr(0, N);

    auto begin = std::chrono::steady_clock::now();
    func1_bad_average(arr); // linear search bad case
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> time_span = end - begin;
    std::cout << "Time (linear search bad case): ";
    std::cout << time_span.count() << std::endl;

    begin = std::chrono::steady_clock::now();
    func2_bad(arr); // binary search bad case
    end = std::chrono::steady_clock::now();
    time_span = end - begin;
    std::cout << "Time (binary search bad case): ";
    std::cout << time_span.count() << std::endl;

    int r = dstr(rng);
    double av_bin = 0;
    for (int i = 0; i < 100; i++)
    {
        begin = std::chrono::steady_clock::now();
        func2_average(arr, r); // binary search average case
        end = std::chrono::steady_clock::now();
        time_span = end - begin;
        av_bin = av_bin + time_span.count();
        r = dstr(rng);
    }
    av_bin = av_bin / 100;
    std::cout << "Time (binary search average case): ";
    std::cout << av_bin << std::endl;

    double av_lin = 0;
    for (int k = 0; k < 100; k++)
    {
        for (int i = 0; i < N; i++)
        {
            arr[i] = dstr(rng);
        }

        begin = std::chrono::steady_clock::now();
        func1_bad_average(arr); // linear search average case
        end = std::chrono::steady_clock::now();
        time_span = end - begin;
        av_lin = av_lin + time_span.count();
    }
    av_lin = av_lin / 100;
    std::cout << "Time (linear search average case): ";
    std::cout << av_lin << std::endl;
    return 0;
}