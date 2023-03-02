#include <iostream>
#include <chrono>
#include <random>
#include <math.h>
const int N = 10;
int swap_counter = 0;

void swap(int &a, int &b)
{
    int c = a;
    a = b;
    b = c;
}

void insert_sort_gap(int (&a)[N], int const begin, int const end, int gap)
{
    for (int i = gap; i < end; i++)
    {
        int temp = a[i];
        int k = i;
        for (; (k >= gap) && (a[k - gap] > temp); k -= gap)
        {
            a[k] = a[k - gap];
            swap_counter++;
        }
        swap_counter++;
        a[k] = temp;
    }
}

void shell_sort(int (&a)[N], int k)
{
    int m = k / 2;
    while (m != 0)
    {
        insert_sort_gap(a, 0, k, m);
        m = m / 2;
    }
}

void hibbard_sort(int (&a)[N], int k)
{
    int i = 0;
    while (pow(2, (float)i) - 1 < (float)N)
        i++;
    i--;
    int m = (int)(pow(2, (float)i) - 1);
    while (m != 0)
    {
        insert_sort_gap(a, 0, k, m);
        i--;
        m = (int)(pow(2, (float)i) - 1);
    }
}

int fibonacci(int i)
{
    if (i > 1)
    {
        return fibonacci(i - 1) + fibonacci(i - 2);
    }
    else if (i == 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void fibonacci_sort(int (&a)[N], int k)
{
    int i = 0;
    while (fibonacci(i) < (float)N)
        i++;
    i--;
    int m = fibonacci(i);
    while (m != 0)
    {
        insert_sort_gap(a, 0, k, m);
        i--;
        m = fibonacci(i);
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
    int a[N] = {0};
    unsigned seed = 1;
    std::default_random_engine rng(seed);
    std::uniform_int_distribution<int> dstr(0, N);
    for (int j = 0; j < N; j++)
    {
        a[j] = dstr(rng);
    }
    printArray(a);
    // shell_sort(a, N);
    // hibbard_sort(a, N);
    fibonacci_sort(a, N);
    printArray(a);
    return 0;
}