#include <iostream>
#include <cstring>

using namespace std;

template<typename T, typename U>
bool greater_then(T lha, U rha)
{
    cout << "template T, U" << endl;
    return lha > rha ? true : false;
}

template<typename T>
bool greater_then(T lha, T rha)
{
    cout << "template T" << endl;
    return lha > rha ? true : false;
}

bool greater_then(double lha, double rha)
{
    cout << "double" << endl;
    return lha > rha ? true : false;
}

int main()
{
    float left = 0;
    double right = 1;
    cout << greater_then(left, right) << endl;
    cout << greater_then<>(left, right) << endl;
    return 0;
}