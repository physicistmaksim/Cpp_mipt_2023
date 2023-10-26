#include <iostream>

class Base 
{
    public:
        int field = 1;
        Base() = default;
        virtual void print() const
        {
            std::cout << "base" << field << std::endl;
        }
};

class Derived : public Base 
{
    public:
        int field = 2;
        Derived() = default;
        void print() const override 
        {
            std::cout << "derived" << field << std::endl;
        }   
};

int main()
{
    Base base = Base();
    Derived derived = Derived();
    Base& ref_base = base, ref_derived = derived;
    ref_base.print();
    ref_derived.print();
    return 0;
}