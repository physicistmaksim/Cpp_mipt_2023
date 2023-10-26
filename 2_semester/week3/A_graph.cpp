#include <iostream>
#include <chrono>
#include <random>
const int N = 1000;

void swap(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

void func(int (&a)[N], int k)
{
    int m = 0;
    for (int i = 0; i < k - 1; i++)
    {
        for (int j = i; j < k; j++)
        {
            if (a[j] < a[m])
            {
                m = j;
            }
        }
        if (m != i)
        {
            swap(a[m], a[i]);
        }
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

    for (int k = 10; k < N; k = k + 10)
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
                func(a, k);
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