#include <iostream>

struct Storage
{
    explicit Storage(size_t size) : size_(size), buffer_(new int[size]) 
    {
        std::cout << "Storage(size_t)" << std::endl;
    }
    Storage& operator=(Storage& other)
    {
        size_ = other.size_;
        delete [] buffer_;
        buffer_ = new int[size_];
        for(size_t idx = 0; idx != size_; ++idx)
        {
            buffer_[idx] = other.buffer_[idx];
        }
        std::cout << "Storage& operator=(Storage&)" << std::endl;
        return *this;
    }
    Storage& operator=(Storage&& other)
    {
        std::swap(other.size_, size_);
        std::swap(other.buffer_, buffer_);
        std::cout << "Storage& operator=(Storage&& other)" << std::endl;
        return *this;
    }
    Storage(Storage&& other)
    {
        std::swap(other.size_, size_);
        std::swap(other.buffer_, buffer_);
        std::cout << "Storage(Storage&& other)" << std::endl;
        return *this;
    }
    Storage operator+(Storage& const rha)
    {
        Storage result = Storage(this->size_ + rha.size_);
        for (size_t idx = 0; idx != this->size_; ++idx)
        {
            result.buffer_[idx] = this->buffer_[idx];
        }
        for (size_t idx = 0; idx != this->size_; ++idx)
        {
            result.buffer_[] = this->buffer_[idx];
        }
    }
    ~Storage()
    {
        delete[] buffer_;
    }
    private:
        size_t size_ = 0;
        int* buffer_ = nullptr;
};
int main()
{
    Storage storage0 = Storage(10);
    Storage storage1 = Storage(20);
    storage0 = storage1;
    Storage storage = std::move(Storage(12));
    return 0;
}
