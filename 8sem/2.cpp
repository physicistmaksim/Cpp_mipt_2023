#include <iostream>

class SomeClass
{
    public:
    SomeClass() = default;
};

void process(int x)
{
    if(x == 1)
        throw x;
    else if(x == 2)
        throw "problem";
    else if(x == 3)
    {
        SomeClass someclass = SomeClass();
        throw someclass;
    }
}

int main()
{
    for(int i = 1; i < 5; ++i)
    {
        std::cout << "x = " << i << std::endl;
        try
        {
            process(i);
        }
        catch(int e)
        {
            std::cerr << "Error type: int" << '\n';
        }
        catch(const char* e)
        {
            std::cerr << "Error type: string" << '\n';
        }
        catch(SomeClass e)
        {
            std::cerr << "Error type: SomeClass" << '\n';
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        std::cout << "okay" << std::endl;
    }
    return 0;
}