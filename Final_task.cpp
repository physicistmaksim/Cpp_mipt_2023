#include <iostream>
#include <string>

using namespace std;

string dop_func(int N, string a, string b, string c)
{
    string ans = "";
    if(N == 9)
        ans = ans + a + c;
    else if(N >= 5)
    {
        ans = ans + b;
        int tmp = N - 5;
        for(int i = 0; i < tmp; ++i)
            ans = ans + a;
    }
    else if(N == 4)
        ans = ans + a + b;
    else
    {
        for(int i = 0; i < N; ++i)
            ans = ans + a;
    }
    return ans;
}

string solution(int N)
{
    int counter = 0;
    string ans = "";
    int tmp = N/1000;
    if(tmp != 0)
    {
        for(int i = 0; i < tmp; ++i)
        {
            ans = ans + "M";
        }
    }
    N = N%1000;
    ans = ans + dop_func(N/100, "C", "D", "M");
    N = N%100;
    ans = ans + dop_func(N/10, "X", "L", "C");
    N = N%10;
    ans = ans + dop_func(N, "I", "V", "X");
    return ans;
}

int main()
{
    cout << solution(1875) << endl;
    return 0;
}