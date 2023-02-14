#include <iostream>

using namespace std;

void func(int N)
{
    int l, c, r, min = 0, max = 0;
    cin >> l >> c >> r;
    if (c > l and c > r)
    {
        max++;
    }
    else if(c < l and c < r)
    {
        min++;
    }
    for(int i = 0; i < N - 3; i++)
    {
        l = c;
        c = r;
        cin >> r;
        if (c > l and c > r)
        {
            max++;
        }
        else if(c < l and c < r)
        {
            min++;
        } 
    }
    if(max > min)
    {
        cout << "MAX" << endl;
    }
    else if(min > max)
    {
        cout << "MIN" << endl;
    }
    else 
    {
        cout << "EQUAL" << endl;
    }
}

int main() 
{
    int N;
    cout << "N = ";
    cin >> N;
    func(N);
    return 0;
}