#include <iostream>
#include <chrono>
#include <random>
const int N = 10000;
int swap_counter = 0;

void swap(int &a, int &b)
{
    int c = a;
    a = b;
    b = c;
    swap_counter++;
}

bool forward_step_M(int (&a)[N], int const begin_idx, int const end_idx, int const M)
{
    bool swaped = false;
    for (int i = begin_idx; i < end_idx - M + 1; i = i + M)
    {
        if (a[i] > a[i + M])
        {
            swap(a[i], a[i + M]);
            swaped = true;
        }
    }
    return swaped;
}

void comd_sort(int (&a)[N], int k)
{
    int M = (int)(k / (1.24733));
    bool swaped = true;
    while (M != 1)
    {
        swaped = forward_step_M(a, 0, k - 1, M);
        M = (int)(M / (1.24733));
        if (M == 0)
        {
            M = 1;
        }
    }
    M = 1;
    while (swaped)
        swaped = forward_step_M(a, 0, k - 1, M);
}

int main()
{
    int a[N] = {0};

    for (int k = 100; k < N; k = k + 100)
    {
        swap_counter = 0;
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
                comd_sort(a, k);
            }
            auto end = std::chrono::steady_clock::now();
            auto time_span = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
            av = av + time_span.count();
        }
        av = av / 100;
        swap_counter = swap_counter / 10000;
        std::cout << k << "," << av << "," << swap_counter << std::endl;
    }
    return 0;
}