#include <iostream>

int main()
{
    int N = 1;
    int tmp;
    int *ptr = new int[N];
    std::cin >> ptr[0];
    std::cin >> tmp;
    while (tmp != 0)
    {
        N++;
        int *temp = new int[N];
        for (int i = 0; i < N - 1; ++i)
        {
            temp[i] = ptr[i];
        }
        temp[N - 1] = tmp;
        delete[] ptr;
        ptr = new int[N];
        for (int i = 0; i < N; i++)
        {
            ptr[i] = temp[i];
        }
        delete[] temp;
        std::cin >> tmp;
    }
    int *a = new int[N - 1];
    for (int i = 0; i < N - 1; ++i)
    {
        a[i] = ptr[i] - ptr[i + 1];
    }
    for (int i = 0; i < N - 1; ++i)
    {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}