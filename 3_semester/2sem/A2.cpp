template<typename T>
void qsort(T* arr, size_t arr_size) {
    int left = 0;
    int right = arr_size - 1;
    T pivot = arr[arr_size / 2];
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
        qsort(arr, right + 1);
    }
    if (left < arr_size) {
        qsort(arr + left, arr_size - left);
    }
}