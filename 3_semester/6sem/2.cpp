#include <iostream>

template <typename Head>
void print(Head head)
{
    std::cout << head << std::endl;
}

template <typename Head, typename ...Tail> //you can add more than one tail
void print(Head head, Tail... tail) // there can be more than on tail arguments
{
    std::cout << head << ' ';
    print(tail...);
}

int main()
{
    print(2, 13, 14, 15, 16);
    return 0;
}