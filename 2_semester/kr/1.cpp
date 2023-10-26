#include <iostream>

using namespace std;

int main()
{
    int N;
    cin >> N;
    int *a = new int[N];
    for(int i = 0; i < N; ++i)
    {
        int tmp;
        cin >> tmp;
        a[i] = tmp;
    }
    for(int i = 0; i < N; ++i)
    {
        int tmp = a[i];
        int step = 1;
        a[i] = 0;
        while(tmp != 0)
        {
            a[i] = a[i] + step*(tmp%10);
            step = step*7;
            tmp = tmp/10;
        }
    }
    int sum = 0;
    for(int i = 0; i < N; ++i)
    {
        sum = sum + a[i];
    }
    int step = 4;
    int step2 = 1;
    int ans = sum%step;
    sum = sum - (sum%step);
    step2 = step2*10;
    while(sum > 0)
    {
        ans = ans + step2*((sum/step)%4);
        sum = sum - ((sum/step)%4)*step;
        step = step*4;
        step2 = step2*10;
    }
    cout << ans << endl;
    delete [] a;
    return 0;
}