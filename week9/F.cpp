#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
    int N, k;
    cin >> N;
    char p[N];
    getchar();
    for(int i = 0; i < N; ++i)
    {
        p[i] = getchar();
        getchar();
    }
    cin >> k;
    getchar();
    char mp = getchar();
    int now = 0;
    int counter = 0;
    while(true)
    {
        int x = (now + k - 1) % N;
        if(x == N - 1)
            now = 0;
        else
            now = x;
        if(p[x] == mp)
        {
            counter++;
            break;
        }
        for(int i = x; i < N - 1; ++i)
        {
            p[i] = p[i + 1];
        }
        p[N - 1] = ' ';
        N--;
        counter++;
    }
    cout << counter << endl;
    return 0;
}