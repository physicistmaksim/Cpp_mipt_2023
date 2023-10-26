#include <iostream>
#include <string>

int main()
{
    std::string ex0 = "123";
    std::string ex1 = "132";
    std::string ex2 = ex0 + ex1; 
    std::string&& rref_ex = ex0 + ex1; 
    std::cout << ex0 << ' ' << ex1 << std::endl;
    std::cout << rref_ex << std::endl;
    std::cout << ex2 << std::endl;
    std::string ex2_moved = std::move(rref_ex);
    std::cout << ex2_moved << std::endl;
    ex2_moved = std::move(ex0);
    // ex2_moved = ex0;
    std::cout << rref_ex << std::endl;
}