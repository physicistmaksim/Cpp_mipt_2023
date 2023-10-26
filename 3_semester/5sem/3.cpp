#include <iostream>
#include <ostream>

template <typename T, typename U> //template class
class Base
{
    public:
        Base() {std::cout << "Base<T, U>" << std::endl; }
        T field;
        U* ptr_field;
};

template <typename T> //different realisation for different arguments
class Base<T, T>
{
    public:
        Base() {std::cout << "Base<T>" << std::endl; }
        T field;
        T* ptr_field;
};

template <>
class Base<int, int>
{
    public:
        Base() {std::cout << "Base<>" << std::endl; }
        int field;
        int* ptr_field;
};

template <typename T>
class Array
{
    public:
        Array(size_t size) : size_(size), storage_(new T[size_]) { }
        size_t size() const { return size_; }
        ~Array() {delete [] storage_; }
    private:
        size_t size_;
        T* storage_;
        template <typename U>
        friend std::ostream& operator<<(std::ostream& os, Array<U>& obj);
        template <typename U>
        friend std::istream& operator>>(std::istream& is, Array<U>& obj);
};

template <typename U>
std::ostream& operator<<(std::ostream& os, Array<U>& obj)
{
    if(obj.size_ > 0)
    {
        for(size_t idx = 0; idx != obj.size_; ++idx)
        {
            os << obj.storage_[idx] << " ";
        }
        return os;
    }
}

template <typename U>
std::istream& operator>>(std::istream& is, Array<U>& obj)
{
    if(obj.size_ > 0)
    {
        for(size_t idx = 0; idx != obj.size_; ++idx)
        {
            is >> obj.storage_[idx];
        }
        return is;
    }
}

int main()
{
    Array arr = Array<int>(10);
    std::cin >> arr;
    std::cout << arr << std::endl;
    return 0;;
}