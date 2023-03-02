#include <iostream>

#ifndef N
#define N 10 // actual size of the array
#endif

void swap(unsigned &a, unsigned &b)
{
    int c = a;
    a = b;
    b = c;
}

bool forward_step(unsigned (&a)[N], unsigned const begin_idx, unsigned const end_idx)
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
bool backward_step(unsigned (&a)[N], unsigned const begin_idx, unsigned const end_idx)
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
void shaker_sort(unsigned (&a)[N])
{
    unsigned begin_idx = 0;
    unsigned end_idx = N - 1;
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

void readArray(unsigned (&a)[N])
{
    for (int i = 0; i < N; i++)
    {
        std::cin >> a[i];
    }
}

void printArray(unsigned (&a)[N])
{
    for (int i = 0; i < N; i++)
    {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;
}

int main()
{
    unsigned a[N];
    readArray(a);
    forward_step(a, 0, N - 1);
    printArray(a);
    return 0;
}