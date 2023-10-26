#include <iostream>
#include <cstring>

using namespace std;

int compare_int(void* a, void* b)
{
    int c = * reinterpret_cast<int *>(a);
    int d = * reinterpret_cast<int *>(b); 
    return c > d ? 1 : 0;
}
int compare_double(void* a, void* b)
{
    double c = * reinterpret_cast<double *>(a);
    double d = * reinterpret_cast<double *>(b); 
    return c > d ? 1 : 0;
}

void swap(void* rha, void* lha, size_t type_size)
{
    void* tmp = malloc(type_size);
    memcpy(tmp, lha, type_size);
    memcpy(lha, rha, type_size);
    memcpy(rha, tmp, type_size);
    free(tmp);
}

//сортировка Хоара
//разбиваем массив на две части так что в левой все элементы меньше опорного, а в правой все больше опорного
//сортируем эти части по отдельносьти (рекурсия)

int partition(void* arr, int l_index, int r_index, void* pivot, int (*compare)(void*, void*), size_t type_size)
{
    while(true)
    {
        while(!compare(arr + (type_size * l_index), pivot)) //сдвигаем левый индекс впрвао (data[l_index] < pivot)
        { 
            l_index += 1;
        }
        while(compare(arr + (type_size * r_index), pivot)) //так же сдвигаем правый индекс (data[r_index] > pivot)
        { 
            r_index -= 1;
        }
        if(r_index <= l_index) //если индексы перешли через друг друга
        {  
            return r_index;
        }
        swap(arr + (type_size * (r_index - 1)), arr + (type_size * (l_index + 1)), type_size);
    }
    return 0; //затычка для компилятора
}  //сложность O(n)

void quick_sort_rec(void* arr, int l_index, int r_index, int (*compare)(void*, void*), size_t type_size)
    {
        if(!(l_index < r_index)) //база рекурсии (если индексы не задают промежуток в массиве)
        { 
            return;
        }
        int split_index = partition(arr, l_index, r_index, arr + (type_size * ((l_index + r_index)/2)), compare, type_size);  //проводим разбиение в качестве опорного берем средний элемент 
        quick_sort_rec(arr, l_index, split_index, compare, type_size);  //сортируем левую и правую части массива
        quick_sort_rec(arr, split_index + 1, r_index, compare, type_size);
    } //сложность O(n logn) тк всего будет примерно logn разбиений (массив делится примерно на две равные части)

void quik_sort(void* arr, size_t arr_size, size_t type_size, int (*compare)(void*, void*))
{
    int size = arr_size / type_size;
    quick_sort_rec(arr, 0, size - 1, compare, type_size);
}

int main()
{
    int arr[] = {1, 5, 10, 7, 4, 6, 3, 2, 8, 9};
    quik_sort(&arr, sizeof(arr), sizeof(int), compare_int);
    return 0;
}