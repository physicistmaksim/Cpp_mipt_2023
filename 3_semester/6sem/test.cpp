#include <iostream>
#include <cassert>

template <typename T>
void array_copy(T* const ds_begin, T const * src_begin, T const * src_end)
{
    int i = 0;
    while((src_begin + i) != src_end)
    {
        *(ds_begin + i) = * (src_begin + i);
        i++;
    }
}

int main() {
	int arr_src[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int arr_dst[10];
  array_copy(arr_dst, arr_src, arr_src + 10);
  for (unsigned idx = 0; idx != 10; ++idx)
  	assert(arr_src[idx] == arr_dst[idx]);
	return 0;
}