#include <iostream>

using namespace std;

int recursive_power(int base, int power)
{
    if(power > 0)
    {
        return base * recursive_power(base, power - 1);
    }
    else
    {
        return 1;
    }
}

int main() 
{
    int base, power;
    cin >> base >> power;
    int result = recursive_power(base, power);
    cout << result << endl;
    return 0;
}