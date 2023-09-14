#include <iostream>

int main()
{
    int nominal[6] = {98, 63, 49, 28, 7, 1};
    int M;
    std::cin >> M;
    int i = 0;
    int counter = 0;
    while(M != 0)
    {
        int temp = M/nominal[i];
        counter = counter + temp;
        M = M - nominal[i]*temp;
        i++;
    }
    std::cout << counter << std::endl;
    return 0;
}