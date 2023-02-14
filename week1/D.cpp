#include <iostream>

using namespace std;

void func(int N)
{
    int pr, mn, max = 0, min = 0;
    cin >> pr;
    for(int i = 1; i < N; i++)
    {
        cin >> mn;
        if (mn > pr)
        {
            max++;
        }
        else if(pr > mn)
        {
            min++;
        }
        pr = mn;
    }
    if (max > min)
    {
        cout << "MAX" << endl;
    }
    else if(min > max)
    {
        cout << "MIN" << endl;
    }
    else
    {
        cout << "MAX = MIN" << endl;
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