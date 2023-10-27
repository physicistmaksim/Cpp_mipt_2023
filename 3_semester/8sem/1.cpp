#include <iostream>

int* GetArray(const uint n, int element)
{
    auto arr = new int[n];
    try 
    {
        for(int i = 0; i < n; ++i)
        {
            arr[i] = element;
        }
    } catch (const std::exception& e)
    {
        delete [] arr;
        throw;
    }
    return arr;
}

int f(int* a, int* b, const uint n)
{
    int* c = new int[2 * n];
    int result;
    try 
    {
        //some work

    } catch (const std::exception& e)
    {
        delete[] a;
        delete[] b;
        delete[] c;
        throw;
    }
    delete[] a;
    delete[] b;
    delete[] c;
    return result;
}

int main()
{
    int n = 10;
    
    try
    {
        int a = f(GetArray(n, 1), GetArray(n, 2), n);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    

}