#include <iostream>

using std::cin;

void input_array(int *ptr, size_t N);
void reverse(int *ptr, size_t N);
void print(const int *ptr, size_t N);

void input_array(int *ptr, size_t N)
{
    for (int i = 0; i < N; ++i)
    {
        std::cin >> ptr[i];
    }
}

void reverse(int *ptr, size_t N)
{
    int tmp;
    int i = 0;
    if (N % 2 == 0)
    {
        for (int i = 0; i < ((N / 2) + 1); ++i)
        {
            tmp = ptr[N - i - 1];
            ptr[N - i - 1] = ptr[i];
            ptr[i] = tmp;
        }
    }
    else
    {
        for (int i = 0; i < (((N - 1) / 2) + 1); ++i)
        {
            tmp = ptr[N - i - 1];
            ptr[N - i - 1] = ptr[i];
            ptr[i] = tmp;
        }
    }
}

void print(const int *ptr, size_t N)
{
    for (int i = 0; i < N; ++i)
    {
        std::cout << ptr[i] << " ";
    }
    std::cout << std::endl;
}

int main()
{
    size_t N = 0;
    cin >> N;
    int *ptr = new int[N];
    input_array(ptr, N);
    reverse(ptr, N);
    print(ptr, N);
    delete[] ptr;
    return 0;
}