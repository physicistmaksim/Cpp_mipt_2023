#include <iostream>
#include <chrono>
#include <random>
const int N = 500000;

int func(int (&a)[N], int s, int k)
{
    int l = 0, r = k - 1;
    while (l != r)
    {
        int cursum = a[l] + a[r];
        if (cursum < s)
            l++;
        else if (cursum > s)
            r--;
        else
            return l;
    }
    return -1;
}

void shell_sort(int (&arr)[N], unsigned real_size)
{
    int arGap[16] = {510774, 227011, 100894, 44842, 19930, 8858, 3937, 1750, 701, 301, 132, 57, 23, 10, 4, 1};

    for (int gap = arGap[0], iGap = 0; iGap < 16; gap = arGap[++iGap])
        for (int i = gap; i < real_size; ++i)
        {
            int tmp = arr[i];
            int j = i;
            for (; j >= gap && tmp < arr[j - gap]; j -= gap)
                arr[j] = arr[j - gap];
            arr[j] = tmp;
        }
}

int main()
{
    int arr[N];
    unsigned seed = 1001;
    int s = -1;
    std::default_random_engine rng(seed);
    std::uniform_int_distribution<int> dstr(0, N);
    for (int j = 0; j < N; j++)
    {
        arr[j] = dstr(rng);
    }
    shell_sort(arr, N);
    for (int i = 100; i < 1000; i = i + 100)
    {
        auto begin = std::chrono::steady_clock::now();
        for (unsigned cnt = 100; cnt != 0; --cnt)
            func(arr, s, i); // linear search bad case
        auto end = std::chrono::steady_clock::now();
        auto time_span = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);

        std::cout << i << "," << time_span.count() << std::endl;
    }
    for (int i = 1000; i < N; i = i + 1000)
    {
        auto begin = std::chrono::steady_clock::now();
        for (unsigned cnt = 100; cnt != 0; --cnt)
            func(arr, s, i); // linear search bad case
        auto end = std::chrono::steady_clock::now();
        auto time_span = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);

        std::cout << i << "," << time_span.count() << std::endl;
    }
    return 0;
}