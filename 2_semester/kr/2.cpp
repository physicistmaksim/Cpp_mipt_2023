#include <iostream>

using namespace std;

int main()
{
    int L;
    cin >> L;
    int n = 0;
    if(L < 10)
    {
        n = 19;
        n = n * L;
    }
    else if(L < 20)
    {
        n = (19 * 9) + (19 * ((L%10) + 1)) - (2 * ((L%10)));
    }
    else if(L < 30)
    {
        n = (19 * 9) + (19 * 10) - (2 * 9) + (19 * ((L%10) + 1)) - (2 * (L%10)) - 2;
    }
    else
    {
        n = (19 * 9) + (19 * 10 * ((L/10) - 1)) - (2 * 9 * ((L/10) - 1)) - (2 * 10 * ((L/10) - 2)) + (19 * ((L%10) + 1)) - (2 * (L%10)) - 2;
    }
    cout << n << endl;
    return 0;
}