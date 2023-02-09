#include <iostream>

using namespace std;

bool what_year(int year)
{
    bool b = false;
    int a = year % 100;
    if (a == 0)
    {
        int c = year/100;
        if(c % 4)
        {
            b = false;
        }
        else
        {
            b = true;
        }
    }
    else
    {
        for(int i = 4; i < 100; i = i + 4)
        {
            if(a == i)
            {
                b = true;
                break;
            }
        }
    }
    return b;
}

int main() 
{
    int year;
    cin >> year;
    if (year < 0)
    {
        cout << "Year shold be positive" << endl;
    }
    else
    {
        cout << (what_year(year)?"YES":"NO") << endl;
    }
    return 0;
}