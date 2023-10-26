#include <iostream>

struct Base
{
    private:
        size_t age = 0;
    public:
        virtual void print() const { std::cout << "My age is: " << age << std::endl; } 
};

struct D1 : virtual Base
{
    public:
        //explicit D1(size_t age) : Base(age) { }
};

struct D2 : virtual Base
{
    public:
        //explicit D2(size_t age) : Base(age) { }
};

struct D3 : D1, D2
{

};

int main()
{
    D1 d1 = D1();
    D2 d2 = D2();
    D3 d3 = D3();
    D1* ptr1 = &d3;
    D2* ptr2 = &d3;
    D1* ptr = dynamic_cast<D1 *>(ptr2); //polymorphism
    return 0;
}