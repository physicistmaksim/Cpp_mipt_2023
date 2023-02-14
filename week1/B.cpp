#include <iostream>

using namespace std;

int counter(int a, int b)
{
    int count = 0;
    int prod = a%b;
    while (prod == 0)
    {
        count++;
        a = a/b;
        prod = a%b;
    }
    return count;
}

int count_zeros(int a)
{
    int num_two = 0, num_five = 0;
    for(int i = 1; i < a + 1; i++)
    {
        num_five = num_five + counter(i, 5);
        num_two = num_two + counter(i, 2);
    }
    if(num_five >= num_two)
    {
        return num_two;
    }
    else
    {
        return num_five;
    }
}

int main() 
{
    int N;
    cin >> N;
    if (N == 0)
    {
        cout << 0 << endl;
    }
    else
    {
        cout << count_zeros(N) << endl;
    }
    return 0;
}