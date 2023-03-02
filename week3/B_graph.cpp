#include <iostream>
#include <chrono>
#include <random>
const int N = 10000;

void swap(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

void DoubleSelectSort(int (&a)[N], int size)
{
    int index_min;
    int index_max;
    for (int i = 0; i < size / 2; i++)
    {
        index_min = i;
        index_max = size - 1 - i;
        for (int j = i; j < size - i; j++)
        {
            if (a[j] < a[index_min])
            {
                index_min = j;
            }
            if (a[j] > a[index_max])
            {
                index_max = j;
            }
        }
        if (index_min != i)
        {
            if (index_max == i)
            {
                index_max = index_min;
            }
            swap(a[index_min], a[i]);
        }
        if (index_max != size - 1 - i)
        {
            swap(a[index_max], a[size - 1 - i]);
        }
    }
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
                DoubleSelectSort(a, k);
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