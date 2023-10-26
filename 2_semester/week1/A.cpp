#include <iostream>

bool pol_or_not(int a)
{
    int a_const = a;
    bool b = false;
    int f, l;
    int dev = 1;
    int prod = a/dev;
    if (a < 10)
    {
        return true;
    }
    while (prod > 9)
    {
        dev = dev*10;
        prod = a/dev;
    }
    while (a > 10)
    {
        f = a/dev;
        l = a%10;
        if (f==l)
        {
            b = true;
        }
        else
        {
            b = false;
            break;
        }
        a = a - f*dev;
        a = a%10;
        dev = dev/10;
    }
    return b;
}

using namespace std;

int main() 
{
    int a;
    cin >> a;
    if (a < 0)
    {
        cout << "Number should be positive" << endl;
    }
    else
    {
        if(pol_or_not(a))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}