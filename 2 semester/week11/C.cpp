#include <iostream>

using namespace std;

struct Node
{
    int max;
    int len;
};

void func(int n, int a[10], Node* &c)
{
    int max = 0;
    int len = 0;
    for(int i = 1; i < 11; ++i)
    {
        if(n - i > 0)
        {
            if(c[n - i].max == 0)
                func(n - i, a, c);
            if(max < (c[n - i].max + a[i - 1]))
            {
                max = c[n - i].max + a[i - 1];
                len = i;
            }
        }
        else if(n - i == 0)
        {
            if(max < a[i - 1])
            {
                max = a[i - 1];
                len = i;
            }
        }
    }
    c[n].max = max;
    c[n].len = len;
}

int main()
{
    int arr[10] = {1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
    int N;
    cin >> N;
    Node* c = new Node[N + 1];
    for(int i = 0; i < N; ++i)
    {
        c[i].max = 0;
    }
    func(N, arr, c);
    int k = c[N].len;
    int* d = new int[N];
    for(int i = 0; i < N; ++i)
    {
        d[i] = 0;
    }
    int i = 0;
    while (N - k >= 0 and N != 0)
    {
        d[i] = k;
        N = N - k;
        if(N != 0)
            k = c[N].len;
        i = i + 1;
    }
    i = 0;
    while (d[i] != 0)
    {
        cout << d[i] << " ";
        i = i + 1;
    }
    delete [] d;
    cout << endl;
    delete [] c;
    return 0;
}
