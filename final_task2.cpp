#include <iostream>
#include <string>
#include <algorithm>

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

int dop_func_2(int N, string out, int counter, int tmp)
{
    int counter_1 = 0;
    int counter_2 = 0;
    int counter_3 = 0;
    if(tmp + 1 == N)
        return counter + 1;
    else if(tmp + 5 == N)
        return counter + 1;
    else if(tmp - 1 == N)
        return counter + 1;
    if(tmp + 1 < N)
        counter_1 = counter + dop_func_2(N, out, counter + 1, tmp + 1);
    if(tmp + 5 < 10)
        counter_2 = counter + dop_func_2(N, out, counter + 1, tmp + 5);
    if(tmp - 1 > N)
        counter_3 = counter + dop_func_2(N, out, counter + 1, tmp - 1);
    return min(min(counter_1, counter_2), counter_3);
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
    cout << dop_func_2(2, " ", 0, 0) << endl;
    return 0;
}