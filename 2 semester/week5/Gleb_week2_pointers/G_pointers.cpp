#include <iostream>
#ifndef N
#define N 7
#endif

using namespace std;

int findUnique(int *a)
{
    int t = 1;
    int c_0 = 0;
    for (int i = 0; i < N; i++)
    {
        if (a[i] == 0)
        {
            c_0++;
        }

        else if (t % a[i] == 0)
        {
            t /= a[i];
        }
        else
        {
            t *= a[i];
        }
    }
    if (c_0 % 2 == 0)
    {
        return t;
    }
    else
    {
        return 0;
    }
}

void read_array(int *a)
{
    for (int i = 0; i < N; i++)
    {
        cin >> a[i];
    }
}

int main()
{
    int *a = new int[N];
    read_array(a);
    cout << findUnique(a) << endl;
}