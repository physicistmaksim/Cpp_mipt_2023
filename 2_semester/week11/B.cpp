#include <iostream>
#include <algorithm>

using namespace std;

int func(int n, int a[10], int* c)
{
    int max = 0;
    for(int i = 1; i < 11; ++i)
    {
        if(n - i > 0)
        {
            if(c[n - i] == 0)
                c[n - i] = func(n - i, a, c);
            if(max < (c[n - i] + a[i - 1]))
                max = c[n - i] + a[i - 1];
        }
        else if(n - i == 0)
        {
            if(max < a[i - 1])
                max = a[i - 1];
        }
    }
    return max;
}

int main()
{
    int arr[10] = {1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
    int N;
    cin >> N;
    int* c = new int[N];
    for(int i = 0; i < N; ++i)
    {
        c[i] = 0;
    }
    cout << func(N, arr, c) << endl;
    delete [] c;
    return 0;
}
