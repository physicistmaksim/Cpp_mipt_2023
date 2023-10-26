#include <iostream>

int main()
{
    double a = 10.1;
    double *aptr = &a;
    *aptr = 0;
    std::cout << aptr << " " << *aptr << std::endl;
    aptr = aptr - 3;
    std::cout << aptr << " " << *aptr << std::endl;
    aptr = aptr + 5;
    std::cout << aptr << " " << *aptr << std::endl;
    return 0;
}