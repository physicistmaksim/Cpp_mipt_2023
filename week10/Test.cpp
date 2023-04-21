#include <iostream>

struct Frac
{
    int num;
    int den;
};

int NOK(int a, int b)
{
    int r1;
    int r2;
    int r3;
    if(a < b)
    {
        r1 = a;
        r2 = a%b;
        if(r2 == 0)
        {
            return a;
        }
        r3 = b%r2;
    }
    else
    {
        r1 = b;
        r2 = b%a;
        if(r2 == 0)
        {
            return b;
        }
        r3 = a%r2;
    }
    while(r3 != 0)
    {
        r1 = r2;
        r2 = r3;
        r3 = r1%r2;
    }
    int nok = (a*b)/r2;
    return nok;
}

int NOD(int a, int b)
{
    int r1;
    int r2;
    int r3;
    if(a < b)
    {
        r1 = a;
        r2 = a%b;
        if(r2 == 0)
        {
            return b;
        }
        r3 = b%r2;
    }
    else
    {
        r1 = b;
        r2 = b%a;
        if(r2 == 0)
        {
            return a;
        }
        r3 = a%r2;
    }
    while(r3 != 0)
    {
        r1 = r2;
        r2 = r3;
        r3 = r1%r2;
    }
    return r2;
}

int main()
{
    int a, b;
    std::cout << NOD(100, 900) << std::endl;
    return 0;
}