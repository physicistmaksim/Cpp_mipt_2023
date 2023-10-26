#include <iostream>

template <typename T, size_t const arr_size>
T sum_array(T* arr)
{
    T sum = *arr;
    for(int i = 1; i < arr_size; ++i)
    {
        sum += *(arr + i);
    }
    return sum;
}

int main() 
{
    int arr[12] = {1, 0, 2, -1, 3, -2, 4, -5, 6, -7, 8, -9};
    std::cout << sum_array<int, 12>(arr) << std::endl;
    return 0;
}