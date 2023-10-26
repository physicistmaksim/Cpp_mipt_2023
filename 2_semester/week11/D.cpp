#include <iostream>

using namespace std;

long long int func(int start, int end, long long int &counter, long long int (&a)[61])
{
    long long int c_1 = 0;
    long long int c_2 = 0;
    long long int c_3 = 0;
    if(start + 1 < end)
    {
        if(a[start + 1] == 0)
            a[start + 1] = func(start + 1, end, counter, a);
        c_1 = a[start + 1];
    }
    if(start + 2 < end)
    {
        if(a[start + 2] == 0)
            a[start + 2] = func(start + 2, end, counter, a);
        c_2 = a[start + 2];
    } 
    if(start + 3 < end)
    {
        if(a[start + 3] == 0)
            a[start + 3] = func(start + 3, end, counter, a);
        c_3 = a[start + 3];
    }
    if(start + 1 == end)
        c_1 = 1;
    if(start + 2 == end)
        c_2 = 1;
    if(start + 3 == end)
        c_3 = 1;
    counter = c_1 + c_2 + c_3;
    return counter;
}

int main()
{
    int X1;
    //cin >> X1;
    X1 = 38;
    long long int a[61] = {0};
    long long int counter = 0;
    counter = func(0, X1, counter, a);
    cout << counter << endl;
    return 0;
}
