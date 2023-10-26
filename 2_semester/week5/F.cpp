#include <cstring>
#include <iostream>

char *resize(char *buf, size_t size, size_t new_size)
{
    if (new_size < size)
    {
        char *tmp = new char[new_size];
        for (int i = 0; i < new_size; ++i)
        {
            tmp[i] = buf[i];
        }
        delete[] buf;
        return tmp;
    }
    else if (new_size > size)
    {
        char *tmp = new char[new_size];
        for (int i = 0; i < size; ++i)
        {
            tmp[i] = buf[i];
        }
        delete[] buf;
        return tmp;
    }
    return buf;
}

int main()
{
    int n_old = 5;
    int n_new = 10;
    char *a = new char[n_old];
    for (int i = 0; i < n_old; ++i)
    {
        a[i] = 'a';
    }
    for (int i = 0; i < n_old; ++i)
    {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;
    a = resize(a, n_old, n_new);
    for (int i = n_old; i < n_new; ++i)
    {
        a[i] = a[n_old - 1];
    }
    for (int i = 0; i < n_new; ++i)
    {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;
    delete[] a;
}