#include <iostream>
#include <algorithm>

int NOD(int a, int b)
{
    int nod = std::min(a, b);
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

int main()
{
    std::cout << NOD(11, 74511834) << std::endl;
    return 0;
}