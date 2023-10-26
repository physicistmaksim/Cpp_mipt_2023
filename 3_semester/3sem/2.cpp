#include <iostream>

class String
{
    private:
        size_t size;
        char* storage = nullptr;
    
    public:
        String(char ch, size_t size): size(size), storage(new char[size])
            {
                storage = new char[size];
                for (size_t i = 0; i < size; ++i)
                {
                    storage[i] = ch;
                }
                std::cout << "Str_construct" << std::endl;
            }
        String(const String& other): size(other.size), storage(new char[size])
        {
            for(size_t i = 0; i < size; ++i)
            {
                storage[i] = other.storage[i];
            }
            std::cout << "Str_construct_copy" << std::endl;
        }
        String(): String(' ', 0) {}
        void changeElement(char ch, size_t idx)
        {
            storage[idx] = ch;
        }
        void print() const
        {
            for(size_t i = 0; i < size; ++i)
            {
                std::cout << storage[i] << " ";
            }
            std::cout << std::endl;
        }
        ~String()
        {
            delete[] storage;
        }
};

int main()
{
    String str0 = String('a', 5);
    String str1 = str0;
    str0.print();
    str1.print();
    return 0;
}