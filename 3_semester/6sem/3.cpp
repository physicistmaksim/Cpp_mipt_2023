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

    static void print() const //with static you can address to this field without initialization of the object of this class
    {
        std::cout << value << std::endl;
    }
};

int main()
{
    std::cout << is_same<int, float>::value << std::endl; // like there
    is_same<int, int>::print();
    return 0;
}