#include <iostream>

/* void quick_sort(int*, size_t);
    
void quick_sort(int* arr, size_t arr_size) {
    int left = 0;
    int right = arr_size - 1;
    int pivot = arr[arr_size / 2];
    while (left <= right) {
        while(arr[left] < pivot) {
            ++left;
        }
        while(arr[right] > pivot) {
            --right;
        }
        if (left <= right) {
            std::swap(arr[left], arr[right]);
            left++;
            right--;
        }
    }

    if(right > 0) {
        quick_sort(arr, right + 1);
    }
    if (left < arr_size) {
        quick_sort(arr + left, arr_size - left);
    }
} */

template<typename T>
void quick_sort(T* arr, size_t arr_size)
{
    int left = 0;
    int right = arr_size - 1;
    int pivot = arr[arr_size / 2];
    while (left <= right) {
        while(arr[left] < pivot) {
            ++left;
        }
        while(arr[right] > pivot) {
            --right;
        }
        if (left <= right) {
            std::swap(arr[left], arr[right]);
            left++;
            right--;
        }
    }

    if(right > 0) {
        quick_sort(arr, right + 1);
    }
    if (left < arr_size) {
        quick_sort(arr + left, arr_size - left);
    }
}

int main()
{
    int* arr = new int[10];
    arr[0] = 2;
    arr[1] = 1;
    arr[2] = 5;
    arr[3] = 8;
    arr[4] = 6;
    arr[5] = 10;
    arr[6] = 7;
    arr[7] = 9;
    arr[8] = 3;
    arr[9] = 4;
    //2, 1, 5, 8, 6, 7, 10, 9, 3, 4
    quick_sort(arr, 10);
    for(int i = 0; i < 10; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}