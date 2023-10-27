#include <iostream>
#include <cassert>

template <typename T, int N>
class Grid
{
    public:
        using value_type = T;
        using size_type = unsigned;

    private:
        size_type size;
        Grid<T, N - 1>* data;
        void swap(Grid<T, N> &other)
        {
            Grid<T, N -1> *tmp = new Grid<T, N - 1>[other.size];
            for(size_type idx = 0; idx != other.size; ++idx)
            {
                tmp[idx] = other.data[idx];
            }
            delete [] other.data;
            other.data = new Grid<T, N - 1>[size];
            for(size_type idx = 0; idx != size; ++idx)
            {
                other.data[idx] = data[idx];
            }
            delete [] data;
            data = new Grid<T, N - 1>[other.size];
            for(size_type idx = 0; idx != other.size; ++idx)
            {
                data[idx] = tmp[idx];
            }
            delete [] tmp;
            std::swap(size, other.size);
        }
    public:
        Grid()
        {
            size = 0;
            data = nullptr;
        }
        Grid(const Grid<T, N> &other) : size(other.size), data(new Grid<T, N - 1>[size])
        {
            for(size_t idx = 0; idx != other.size; ++idx)
            {
                    data[idx] = other.data[idx];
            }
        }
        Grid(Grid<T, N> &&other)
        {
            this->swap(other);
        }
        Grid<T, N>& operator=(Grid<T, N> &other)
        {
            size = other.size;
            data = new Grid<T, N>[size];
            for(size_t idx = 0; idx != other.size; ++idx)
            {
                    data[idx] = other.data[idx];
            }
            return *this;
        }
        template <typename Head, typename ...Tail>
        Grid(Head s,  Tail... tail) : size(s), data(new Grid<T, N - 1>[size]) 
        {
            for(size_t idx = 0; idx != size; ++idx)
            {
                data[idx] = Grid<T, N - 1>(tail...);
            }
        }
        template <typename Head, typename ...Tail>
        Grid(T const &t, Head s, Tail... tail) : size(s), data(new Grid<T, N - 1>[size])
        {
            for(size_t idx = 0; idx != size; ++idx)
            {
                data[idx] = Grid<T, N - 1>(t, tail...);
            }
        }
        Grid<T, N>& operator=(Grid<T, N> &&other)
        {
            this->swap(other);
            return *this;
        }
        ~Grid()
        {
            delete[] data;
        }
        template <typename Head, typename ...Tail>
        T operator()(Head idx, Tail... tail) const // <- здесь такая же ошибка
        {
            return data[idx](tail...);
        }
        Grid<T, N>& operator=(T const& t) 
        {
            for(size_t idx = 0; idx != size; ++idx)
            {
                data[idx] = t;
            }
            return *this;
        }
        Grid<T, N - 1> operator[](size_type idx) // <- здесь такая же ошибка как и в операторе скобок для одномерного grid
        {
            return data[idx];
        }
        size_type get_size() const { return size; }
};

template <typename T>
class Grid<T, 1>
{
    public:
        using value_type = T;
        using size_type = unsigned;

    private:
        size_type size;
        T* data;
        void swap(Grid<T, 1> &other)
        {
            T *tmp = new T[other.size];
            for(size_type idx = 0; idx != other.size; ++idx)
            {
                tmp[idx] = other.data[idx];
            }
            delete [] other.data;
            other.data = new T[size];
            for(size_type idx = 0; idx != size; ++idx)
            {
                other.data[idx] = data[idx];
            }
            delete [] data;
            data = new T[other.size];
            for(size_type idx = 0; idx != other.size; ++idx)
            {
                data[idx] = tmp[idx];
            }
            delete [] tmp;
            std::swap(size, other.size);
        }
    public:
        Grid()
        {
            size = 0;
            data = nullptr;
        }
        Grid(T* data, size_type s) : size(s), data(data) {}
        Grid(const Grid<T, 1> &other) : size(other.size), data(new T[other.size])
        {
            for(size_t idx = 0; idx != other.size; ++idx)
            {
                data[idx] = other.data[idx];
            }
        }
        Grid(Grid<T, 1> &&other)
        {
            this->swap(other);
        }
        Grid<T, 1>& operator=(Grid<T, 1> &other)
        {
            size = other.size;
            data = new T[size];
            for(size_t idx = 0; idx != other.size; ++idx)
            {
                data[idx] = other.data[idx];
            }
            return *this;
        }
        Grid(T const &t)
        {
            size = 1;
            data = new T[1];
            data[0] = t;
        }
        operator T() {return data[0];}
        Grid(size_type s) : size(s), data(new T[size]) {} 
        Grid(size_type s, T const &t) : size(s), data(new T[s])
        {
            for(size_t idx = 0; idx != size; ++idx)
            {
                data[idx] = t;
            }
        }
        Grid<T, 1>& operator=(Grid<T, 1> &&other)
        {
            this->swap(other);
            return *this;
        }
        ~Grid()
        {
            delete[] data;
        }
        T operator()(size_type idx) //<- здесь такая же ошибка
        {
            return data[idx];
        }
        Grid<T, 1>& operator=(T const& t) 
        {
            for (auto it = data, end = data + size; it != end; ++it) 
            {
                *it = t;
            }
            return *this;
        }
        Grid<T, 1> operator[](size_type idx) // <- мне надо здесь постовить & чтобы правильно
        {                                    //  работало копирование, но я не могу это сделать 
            return (Grid<T,1>)data[idx];     // потому что тогда мне нужно <- в этой строчке тоже поствить *
        }                                    // но у меня в этом случае выдает какую-то ошибку 
        size_type get_size() const { return size; } // типа невозможности преобразования L-value в R-value
};

int main() 
{
    Grid<float, 2> g(0.0f, 3, 2);
    assert(0.0f == g[0][0]);
    g[0][0] = 1.0f; // не получается реализовать правильно присваивание без &
    //assert (1.0f == g[0][0]); // поэтому не проходит эту проверку

    // III (проходит проверку, но потому что здесь нет присваивания, а как только попробовать 
    // написать = то присваивания не происходит, что связано с этой ошибкой, ктоторая не раз вылазит в коде, которую я не смог решить)
    Grid<float,3> g3(2, 3, 4, 1.0f);
    assert(1.0f == g3(1, 1, 1));
    Grid<float,2> g2(2, 5, 2.0f); 
    assert(2.0f == g2(1, 1));
    g2 = g3[1];
    assert(1.0f == g2(1, 1));
    return 0;
}