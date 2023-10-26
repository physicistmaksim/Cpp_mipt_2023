#include <iostream>

struct Time
{
    int h, m, s;
};

int main()
{
    Time begin, duration, end;
    end.h = 0;
    end.m = 0;
    end.s = 0;
    std::cin >> begin.h >> begin.m >> begin.s;
    std::cin >> duration.h >> duration.m >> duration.s;
    int s = begin.s + duration.s;
    end.s = s % 60;
    end.m += s / 60;
    int m = begin.m + duration.m;
    end.m += m % 60;
    int tmp_m = end.m;
    end.m = tmp_m % 60;
    end.h += tmp_m / 60;
    end.h += m / 60;
    end.h += begin.h + duration.h;
    end.h = end.h % 24;
    std::cout << end.h << ":" << end.m << ":" << end.s << std::endl;
    return 0;
}