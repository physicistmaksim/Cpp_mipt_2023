#include <iostream>
#include <chrono>
#include <random>
const int N = 10000;

void insert_sort_gap(int (&a)[N], int const begin, int const end, int gap)
{
    for (int i = gap; i < end; i++)
    {
        int temp = a[i];
        int k = i;
        for (; (k >= gap) && (a[k - gap] > temp); k -= gap)
        {
            a[k] = a[k - gap];
        }
        a[k] = temp;
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

    for (int k = 100; k < N; k = k + 100)
    {
        double av = 0;
        for (int i = 0; i < 100; i++)
        {
            std::default_random_engine rng(1001);
            std::uniform_int_distribution<int> dstr(0, k);
            for (int j = 0; j < k; j++)
            {
                a[j] = dstr(rng);
            }
            auto begin = std::chrono::steady_clock::now();
            for (unsigned cnt = 100; cnt != 0; --cnt)
            {
                insert_sort_gap(a, 0, k, 1);
            }
            auto end = std::chrono::steady_clock::now();
            auto time_span = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
            av = av + time_span.count();
        }
        av = av / 100;
        std::cout << k << "," << av << std::endl;
    }
    return 0;
}