#include <iostream>

using namespace std;

int main()
{
    int N;
    cin >> N;
    int *a = new int[N];
    for(int i = 0; i < N; ++i)
    {
        cin >> a[i];
    }
    int step = 0;
    int max = a[step];
    while(step < N)
    {
        int sum = a[step];
        step++;
        while(step < N and sum + a[step] >= sum)
        {
            sum = sum + a[step];
            step++;
        }
        if(sum > max)
            max = sum;
    }
    cout << max << endl;
    delete [] a;
    return 0;
}