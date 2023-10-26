#include <iostream>
#include <cmath>
#include <cassert>

using namespace std;

void array_shift(int *begin, int *end, int shift)
{
    if(begin != end)
    {
        int temp;
        int l = (end - begin)/sizeof(int);
        for(int i = 0; i < shift; i++)
        {
            temp = *end;
            int *p = end;
            for(int j = 0; j < l; j++)
            {
                *p = *(p - 1);
                p = p - 1;
            }
            *begin = temp;
        }
    }
}

int main() 
{
    int *begin = new int[6];
    for(int i = 0; i < 6; i++)
    {
        *(begin + i) = i;
    }
    int *end = begin + 5;
    return 0;
}