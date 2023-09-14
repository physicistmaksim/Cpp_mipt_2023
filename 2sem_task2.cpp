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

void swap(int* rha, int* lha, size_t type_size)
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

int partition(int data[], int l_index, int r_index, int pivot){
    while(true){
        while(data[l_index] < pivot){ //сдвигаем левый индекс впрвао
            l_index += 1;
        }
        while(data[r_index] > pivot){ //так же сдвигаем правый индекс
            r_index -= 1;
        }
        if(r_index <= l_index){  //если индексы перешли через друг друга
            return r_index;
        }
        swap(data[r_index--], data[l_index++]);
    }
    return 0; //затычка для компилятора
}  //сложность O(n)

void quick_sort(int data[], int l_index, int r_index){
    if(!(l_index < r_index)){ //база рекурсии (если индексы не задают промежуток в массиве)
        return;
    }
    int split_index = partition(data, l_index, r_index, data[(l_index + r_index) / 2]);  //проводим разбиение в качестве опорного берем средний элемент 
    quick_sort(data, l_index, split_index);  //сортируем левую и правую части массива
    quick_sort(data, split_index + 1, r_index);
} //сложность O(n logn) тк всего будет примерно logn разбиений (массив делится примерно на две равные части)

template <typename T>
void quik_sort(T* arr, size_t arr_size)
{
    
}

int main()
{
    
    return 0;
}