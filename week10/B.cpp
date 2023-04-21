#include <iostream>
#include <numeric>

struct Frac
{
    long long int num;
    long long int den;
};

long long int NOK(long long int a, long long int b)
{
    long long int r1;
    long long int r2;
    long long int r3;
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
    long long int nok = (a*b)/r2;
    return nok;
}

long long int NOD(long long int a, long long int b)
{
    long long int r1;
    long long int r2;
    long long int r3;
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

Frac subtrac(Frac a, Frac b)
{
    long long int den_main = NOK(a.den, b.den);
    long long int num_main = a.num*(den_main/a.den) - b.num*(den_main/b.den);
    Frac m;
    long long int nod;
    if(num_main > 0)
    {
        nod = NOD(num_main, den_main);
        num_main = num_main/nod;
        den_main = den_main/nod;
    }
    else if(num_main == 0)
    {
        m.num = 0;
        m.den = 2;
    }
    else
    {
        nod = NOD((-1)*num_main, den_main);
        num_main = num_main/nod;
        den_main = den_main/nod;
    }
    m.num = num_main;
    m.den = den_main;
    return m;
}

int main()
{
    long long int step = 2;
    Frac m;
    Frac tmp;
    tmp.num = 1;
    //std::cin >> m.num;
    //std::cin >> m.den;
    m.num = 999;
    m.den = 1001;
    while (m.num != 0)
    {
        tmp.den = step;
        Frac tmp_2 = subtrac(m, tmp);
        if(tmp_2.num < 0)
            step++;
        else
        {
            m = tmp_2;
            std::cout << step << " ";
            step++;
        }
    }
    std::cout << std::endl;
    return 0;
}
