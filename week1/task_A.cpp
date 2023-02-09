#include <iostream>
#include <string>

bool pol_or_not(int a)
{
    bool b;
    string str = to_string(a);
    for (int i = 0; i < size(str)/2; i++)
    {
        if (str[i] == str[size(str) - 1 - i])
        {
            b = true;
        }
        else
        {
            b = false;
            break;
        }
    }
    return b;
}

using namespace std;

int main() 
{
    
    return 0;
}