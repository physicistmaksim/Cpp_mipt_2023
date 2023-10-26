#include <iostream>
#ifndef N
#define N 3
#endif

using namespace std;

void print_array(int *(&a)[N]);

void shiftRight(int *a, int k)
{
    int *a1 = new int[k];
    int *a2 = new int[N - k];
    int t_1 = 0;
    int t_2 = 0;
    for (int i = 0; i < k; i++)
    {
        a1[i] = a[N - k + i];
    }
    for (int i = 0; i < N - k; i++)
    {
        a2[t_1] = a[i];
        t_1++;
    }
    for (int i = 0; i < k; i++)
    {
        a[i] = a1[i];
    }
    for (int i = k; i < N; i++)
    {
        a[i] = a2[t_2];
        t_2++;
    }
    delete[] a1;
    delete[] a2;
}

void read_array(int *a)
{
    for (int i = 0; i < N; i++)
    {
        cin >> a[i];
    }
}

void print_array(int *a)
{
    for (int i = 0; i < N; i++)
    {
        cout << a[i] << " ";
    }
}

int main()
{
    int *a = new int[N];
    int k;
    cin >> k;
    k = k % N;
    read_array(a);
    shiftRight(a, k);
    print_array(a);
    delete[] a;
}