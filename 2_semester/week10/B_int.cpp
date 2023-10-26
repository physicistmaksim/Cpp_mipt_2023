#include <iostream>
#include <numeric>

struct Frac
{
    int num;
    int den;
};

int NOD(int a, int b)
{
    int nod;
    if(a < b)
        nod = a;
    else 
        nod = b;
    while (nod > 0) 
    {
        if (a % nod == 0 && b % nod == 0) 
            break;
        nod--;
    }
    return nod;
}

int NOK(int a, int b)
{
    int nok = (a*b)/(NOD(a, b));
    return nok;
}

Frac subtrac(Frac a, Frac b)
{
    int den_main = NOK(a.den, b.den);
    int num_main = a.num*(den_main/a.den) - b.num*(den_main/b.den);
    Frac m;
    int nod;
    if(num_main == 0)
    {
        m.num = 0;
        m.den = 2;
    }
    else if(num_main > 0)
    {
        nod = NOD(num_main, den_main);
        num_main = num_main/nod;
        den_main = den_main/nod;
    }
    else
    {
        num_main = -1;
        den_main = 2;
    }
    m.num = num_main;
    m.den = den_main;
    return m;
}

int main()
{
    int step = 2;
    Frac m;
    Frac tmp;
    tmp.num = 1;
    //std::cin >> m.num;
    //std::cin >> m.den;
    m.num = 1;
    m.den = 7;
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