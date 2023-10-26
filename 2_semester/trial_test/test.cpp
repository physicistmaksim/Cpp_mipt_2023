#include <iostream>

using namespace std;

double* func(double *begin, double *end, double key) 
{
    auto distance = (end - begin);
    auto result = begin;
    while (distance > 0) 
    {
        if(distance == 1)
        {
            if(*begin >= key)
                result = begin;
            else
                result = end;
            distance = 0;
        }
        else if(*(begin + (distance/2)) < key)
        {
            begin = begin + (distance/2);
            distance = (end - begin);
        }
        else if(*(begin + (distance/2)) >= key)
        {
            end = begin + (distance/2);
            distance = (end - begin);
        }
    }
    return result;
}

int main()
{
    double* a = new double[4];
    a[0] = 1.1;
    a[1] = 2.1;
    a[2] = 3.1;
    a[3] = 4.1;
    cout << func(a, a + 4, 1.2) - a << endl;
    delete [] a;
    return 0;
}