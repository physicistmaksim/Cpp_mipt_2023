#include <iostream>

using namespace std;

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

int main()
{
    Frac main_frac;
    //cin >> main_frac.num;
    //cin >> main_frac.den;
    main_frac.num = 14;
    main_frac.den = 15;
    Frac step;
    step.num = 1;
    step.den = 2;
    while (main_frac.num != 0)
    {
        int den = NOK(step.den, main_frac.den);
        int num = main_frac.num * (den/main_frac.den) - step.num * (den/step.den);
        if(num < 0)
            step.den++;
        else
        {
            int nod = NOD(num, den);
            main_frac.num = num/nod;
            main_frac.den = den/nod;
            cout << step.den << " ";
        }
    }
    cout << endl;
    return 0;
}