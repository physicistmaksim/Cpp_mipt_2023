#include <iostream>

using namespace std;

int recursive_power(int base, int power)
{
    int res = 1;
    while(power > 0)
    {
        res = res * base;
        power--;
    }
    return res;
}

int main() 
{
    int base, power;
    cin >> base >> power;
    cout << recursive_power(base, power) << endl;
    return 0;
}