#include <iostream>

template<typename T>
class Array 
{
    public:
        size_t size_;
        T* array;
    public:
        explicit Array(size_t size = 0, const T& value = T())
        {
            size_ = size;
            array = new T[size_];
            for(size_t i = 0; i < size_; ++i){
                array[i] = value;
            }
        }

        Array(const Array & old_arr)
        {
            size_ = old_arr.size_;
            array = new T[old_arr.size_];
            for(size_t i = 0; i < size_; ++i){
                array[i] = old_arr.array[i];
            }
        }

        ~Array()
        {
            delete[] array;
        }

        Array& operator=(Array* rha)
        {
            this->size_ = rha->size_;
            delete[] this->array;
            this->array = new T[this->size_];
            for(size_t i = 0; i < size_; ++i){
                this->array[i] = rha->array[i];
            }
            return *this;
        }

        size_t size() const
        {
            return size_;
        }
            
        T& operator[](size_t i)
        {
            return array[i];
        }
        const T& operator[](size_t i) const
        {
            return array[i];
        }

        template<typename U>
        friend std::ostream& operator<<(std::ostream &out, const Array &obj);

        template<typename U>
        friend std::istream& operator>>(std::istream &in, const Array &obj);
};

template<typename U>
std::ostream& operator<<(std::ostream &out, const Array<U> &obj)
{
    if(obj.size() > 0)
    {
        out << "[";
        out << obj.array[0];
        for(size_t i = 1; i < obj.size(); ++i)
        {
            out << ", " << obj.array[i];
        }
        out << "]" << std::endl;
    }
    return out;
}

template<typename U>
std::istream& operator>>(std::istream &in, const Array<U> &obj)
{
    for(size_t i = 0; i < obj.size(); ++i)
    {
        in >> obj.array[i];
    }
    return in;
}