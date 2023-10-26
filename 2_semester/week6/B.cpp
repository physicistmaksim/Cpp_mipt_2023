#include <iostream>

struct Student
{
    std::string name;
    int sr_bal;
};

int main()
{
    int N;
    std::cin >> N;
    Student t[N];
    for (int i = 0; i < N; ++i)
    {
        std::cin >> t[i].name;
        std::cin >> t[i].sr_bal;
    }
    int s = t[0].sr_bal;
    for (int i = 1; i < N; ++i)
    {
        s = s + t[i].sr_bal;
    }
    s = s / N;
    std::cout << s << std::endl;
    return 0;
}