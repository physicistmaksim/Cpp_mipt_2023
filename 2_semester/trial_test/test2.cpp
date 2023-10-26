#include <iostream>

using namespace std;

double* max_in_array_rec(double *begin, double *end, double *max) 
{
    if(begin == end)
    {
        return nullptr;
    }
    else if(end - begin == 1)
    {
        return *begin > *max ? begin : max;   
    }
    return max_in_array_rec(begin + 1, end, *begin > *max ? begin : max);
}

int main()
{
    double* a = new double[1];
    a[0] = 0;
    cout << *max_in_array_rec(a, a + 1, a) << endl;;
    return 0;
}