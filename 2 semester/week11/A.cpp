#include <iostream>

using namespace std;

long long int func(int n, long long int* a)
{
    for(int i = 3; i < n + 1; ++i)
    {
        a[i] = 2 * a[i - 1] + 2 * a[i - 2] - a[i - 3];
    }
    return a[n];
}

int main()
{
    int N;
    cin >> N;
    long long int* a = new long long int[N + 1];
    if(N == 0 or N == 1)
        cout << "1" << endl;
    else if(N == 2)
        cout << "4" << endl;
    else
    {
        a[0] = 1;
        a[1] = 1;
        a[2] = 4;
        cout << func(N, a) << endl;
    }
    delete [] a;
    return 0;
}