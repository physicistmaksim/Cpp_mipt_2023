#include <iostream>

template <typename U, typename V>
struct is_same
{
    static const bool value = false;
};

template <typename U>
struct is_same<U, U>
{
    static const bool value = true;

    static const void print()
    {
        std::cout << value << std::endl;
    }
};

template<short int N> //if we don't call template function or class fuction it won't compile
struct Storage
{
    int storage[N];
};

template <typename T, int N>
struct Dummy
{
    void g()
    {
        Storage<-1>();
    }
};

int main()
{
    Dummy<int, 10> dummy = Dummy<int, 10>();
    dummy.g();
    std::cout << is_same<int, float>::value << std::endl; 
    is_same<int, int>::print();
    return 0;
}