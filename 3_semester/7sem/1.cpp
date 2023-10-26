fstream
-> ifstream
-> ofstream

//-------------------

//example operator of assigment and constructor of copying
MaClass func();

int main()
{
    auto a = func(); //constructor
    a = func(); //operator of assigment
}
//------------------------

//cppreference

std::unique_ptr; 

std::make_unique;

//-------------------------

std::shared_ptr;

std::make_shared; //it unites counter and ptr and makes form therm control block

//-------------------------

std::weak_ptr; //behaves like shared_ptr, but 