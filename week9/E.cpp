#include <iostream>

using std::cin;
using std::cout;
using std::endl;


int main()
{
    int t1 = 0;
    int t2 = 0;
    int t3 = 0;
    int t4 = 0;
    int t = 0;
    char ch = getchar();
    while (ch != '\n')
    {
        if(ch == '(')
        {
            t1++;
            t = 1;
        }
        else if(ch == ')')
        {
            if(t == 1)
            {
                t1--;
            }
            else
            {
                t1 = -1;
                break;
            }
        }
        else if(ch == '[')
        {
            t2++;
            t = 2;
        }
        else if(ch == ']')
        {
            if(t == 2)
            {
                t2--;
            }
            else
            {
                t2 = -1;
                break;
            }
        }
        else if(ch == '{')
        {
            t3++;
            t = 3;
        }
        else if(ch == '}')
        {
            if(t == 3)
            {
                t3--;
            }
            else
            {
                t3 = -1;
                break;
            }
        }
        else if(ch == '<')
        {
            t4++;
            t = 4;
        }
        else
        {
            if(t == 4)
            {
                t4--;
            }
            else
            {
                t4 = -1;
                break;
            }
        }
        if(t1 < 0 or t2 < 0 or t3 < 0 or t4 < 0)
        {
            break;
        }
        ch = getchar();
    }
    if(t1 == 0 and t2 == 0 and t3 == 0 and t4 == 0)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}