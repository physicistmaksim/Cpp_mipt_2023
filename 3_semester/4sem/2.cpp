#include <iostream>

class Base 
{
    public:
        int field = 1;
    public:
        int public_base_field = 0;
        Base() { std::cout << "Base" << std::endl; };
        Base(int base_value) : field(base_value) { };
    protected:
        int protected_base_field = 0;
};

class Derived final: public Base //with protected not working
{
    public:
        int field = 1;
    public:
        Derived() { std::cout << "Derived" << std::endl; };
        Derived(int derived_value) : field(derived_value) { };
        Derived(int derived_value, int base_value) : Base(base_value), field(derived_value) { };   
        void print() const 
        {
            std::cout << public_base_field << " " << protected_base_field << std::endl;
        }   
};

// class DerivedDerived : Derived { }; //final means that ther will no more drived classes

int main()
{
    Base base = Base();
    Derived derived = Derived();
    std::cout << base.field << std::endl;
    std::cout << derived.field << std::endl;
    std::cout << derived.Base::field << std::endl;
    //std::cout << base.protected_base_field << std::endl;
    derived.print();
    //std::cout << derived.protected_base_field << std::endl;
    return 0;
}

// virtual and override, when we have the same methods in base and in derived class, virtual and ovverride work
// with links and they call 