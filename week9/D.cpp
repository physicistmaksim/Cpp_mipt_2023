#include <iostream>

using std::cin;
using std::cout;
using std::endl;


int main()
{
    int op = 0;
    bool cor = true;
    char ch = getchar();
    while (ch != '\n')
    {
        if(ch == '(')
            op++;
        else
        op--;
        if(op < 0)
        {
            cor = false;
            break;
        }
        ch = getchar();
    }
    if(op == 0)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}