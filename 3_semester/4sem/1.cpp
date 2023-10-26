#include <iostream>
#include <ostream>

class MyClass 
{
    int i = 0;
    public:
        MyClass() = default;
        MyClass(int)= delete;

        MyClass& operator+=(MyCLass& other)
        {
            this->i += other.i;
            return *this;
        }

        MyClass& operator++() //prefix
        {
            *this += 1;
            return *this;
        }
        MyClass operator++(int) //postfix
        {
            MyClass res = *this;
            ++(*this);
            return res;
        }
    private:
        int field = 0;
        friend void myBestFriendFunction (MyClass& other, int value);
        friend std::ostream operator<<(std::ostream os, MyClass& other);
};

void myBestFriendFunction (MyClass& other, int value)
{
    other.field += value;
}

int main()
{
    MyClass example = MyClass();
    myBestFriendFunction(example, 10);
    // example += 10;
    // example.operator+=(10);
    std::cout << example.field << "New line" <<  std::endl;
    return 0;
}