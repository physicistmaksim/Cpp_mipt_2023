#include <iostream>
#include <string>

int main()
{
    std::string ex0 = "123";
    std::string ex1 = "132";
    std::cout << ex0 << ' ' << ex1 << std::endl;
    std::string ex2 = ex0 + ex1; // ex0 + ex1 is temporary object, we can save it this way
    std::string& ref_ex2 = ex2;
    //std::string& ref_ex_temp = ex0 + ex1; // we can not make refference to temporary object (but we can not change it because of const)
    const std::string& ref_ex_temp = ex0 + ex1; //we can do this way 
    //or
    std::string&& rref_ex = ex0 + ex1; // this way; && is not link to link; it is just sintax when we want to save temporary object
    std::cout << ex0 + ex1 << std::endl;
    std::cout << ex2 << std::endl;
    std::cout << ref_ex_temp << std::endl;
}