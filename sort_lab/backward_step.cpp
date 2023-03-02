#include <iostream>
#include <chrono>
#include <random>
#include <math.h>
const int N = 10000;

void swap(int &a, int &b)
{
    int c = a;
    a = b;
    b = c;
}

bool forward_step(int (&a)[N], int const begin_idx, int const end_idx)
{
    bool swaped = false;
    for (int i = begin_idx; i < end_idx; i++)
    {
        if (a[i] > a[i + 1])
        {
            swap(a[i], a[i + 1]);
            swaped = true;
        }
    }
    return swaped;
}
bool backward_step(int (&a)[N], int const begin_idx, int const end_idx)
{
    bool swaped = false;
    for (int i = end_idx; i > begin_idx; i--)
    {
        if (a[i] < a[i - 1])
        {
            swap(a[i], a[i - 1]);
            swaped = true;
        }
    }
    return swaped;
}
void shaker_sort(int (&a)[N], int k)
{
    int begin_idx = 0;
    int end_idx = k - 1;
    bool swaped = true;
    while (swaped)
    {
        swaped = forward_step(a, begin_idx, end_idx);
        end_idx--;
        if (not swaped)
            break;
        swaped = backward_step(a, begin_idx, end_idx);
        begin_idx++;
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
            std::default_random_engine rng(i);
            std::uniform_int_distribution<int> dstr(0, k);
            for (int j = 0; j < k; j++)
            {
                a[j] = dstr(rng);
            }
            auto begin = std::chrono::steady_clock::now();
            for (unsigned cnt = 100; cnt != 0; --cnt)
            {
                shaker_sort(a, k);
            }
            auto end = std::chrono::steady_clock::now();
            auto time_span = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
            av = av + time_span.count();
        }
        av = av / 100;
        std::cout << k << "," << av << "," << std::endl;
    }
    return 0;
}