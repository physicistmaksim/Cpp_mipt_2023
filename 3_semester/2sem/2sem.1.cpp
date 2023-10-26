#include <iostream>
#include <cstring>

using namespace std;

void qsort(void* arr, size_t arr_size, size_t type_size,
    int (* compare)(void* , void* ));

void swap(int* rha, int* lha, size_t type_size)
{
    void* tmp = malloc(type_size);
    memcpy(tmp, lha, type_size);
    memcpy(lha, rha, type_size);
    memcpy(rha, tmp, type_size);
    free(tmp);
}

void swap(int &rha, int &lha)
{
    int tmp = lha;
    lha = rha;
    rha = tmp;
}

void dummy_func (void * arr)
{
    cout << (* reinterpret_cast<int *>(arr))  << endl;
    return;
}

int main()
{
    int arr[] = {1, 2 , 3};
    dummy_func(arr);
    cout << arr[0] << ' ' << arr[1] << endl;
    swap(&arr[0], &arr[1], sizeof(int));
    cout << arr[0] << ' ' << arr[1] << endl;
    return 0;
}