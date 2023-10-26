#include <iostream>

struct Base 
{
    private:
        size_t field = 0;
    public:
        virtual void hello() = 0;
        virtual ~Base() { }
};

struct Derived : Base
{
    private:
        int* storage = nullptr;
    public:
    Derived() : storage(new int[10]) { }
    void hello() override
    {
        std::cout << "Hello!" << std::endl;
    }
    ~Derived()
    {
        delete [] storage;
    }
};


int main()
{
    Derived d = Derived();
    Base* ptr = new Derived();
    ptr->hello();
    d.hello();
    delete ptr;
    return 0;
}