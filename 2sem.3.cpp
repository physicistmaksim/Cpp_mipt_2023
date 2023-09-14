#include <iostream>
#include <cstring>

using namespace std;

template<typename T, typename U>
bool greater_than(T &lha, U &rha)
{
    cout << "template T&, U&" << endl;
    return lha > rha ? true : false;
}

//template<typename T, typename U>
//bool greater_than(T &lha, U &rha)
//{
//    cout << "template T&, U&" << endl;
//    return lha > rha ? true : false;
//}

int main()
{
    float left = 0;
    double right = 1;
    cout << greater_than(left, right) << endl;
    return 0;
}