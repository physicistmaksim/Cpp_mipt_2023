#include <iostream>

struct Street
{
    int x1, y1, x2, y2;
};

struct Vec
{
    int x, y;
};

int mult(Vec a, Vec b)
{
    return (a.x) * (b.y) - (b.x) * (a.y);
}

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

bool cross(Street a, Street b)
{
    Vec l1, l2;
    l1.x = a.x1 - a.x2;
    l1.y = a.y1 - a.y2;
    l2.x = b.x1 - b.x2;
    l2.y = b.y1 - b.y2;
    Vec a1, a2, b1, b2;
    a1.x = b.x1 - a.x2;
    a1.y = b.y1 - a.y2;
    a2.x = b.x2 - a.x2;
    a2.y = b.y2 - a.y2;
    //-----------------
    b1.x = a.x1 - b.x2;
    b1.y = a.y1 - b.y2;
    b2.x = a.x2 - b.x2;
    b2.y = a.y2 - b.y2;
    if (
        ((mult(l1, a1) >= 0 and mult(l1, a2) < 0) or
         (mult(l1, a1) > 0 and mult(l1, a2) <= 0) or
         (mult(l1, a1) < 0 and mult(l1, a2) >= 0) or
         (mult(l1, a1) <= 0 and mult(l1, a2) > 0)) and
        ((mult(l2, b1) >= 0 and mult(l2, b2) < 0) or
         (mult(l2, b1) > 0 and mult(l2, b2) <= 0) or
         (mult(l2, b1) < 0 and mult(l2, b2) >= 0) or
         (mult(l2, b1) <= 0 and mult(l2, b2) > 0)))
    {
        return true;
    }
    else if (
        mult(l1, a1) == 0 and mult(l1, a2) == 0)
    {
        if (a.x1 != a.x2)
        {
            if (a.x1 > a.x2)
            {
                swap(a.x1, a.x2);
                swap(a.y1, a.y2);
            }
            if (b.x1 > b.x2)
            {
                swap(b.x1, b.x2);
                swap(b.y1, b.y2);
            }
            if (
                ((a.x1 <= b.x1) and (b.x1 <= a.x2)) or
                ((a.x1 <= b.x2) and (b.x2 <= a.x2)) or
                ((b.x1 <= a.x1) and (a.x2 <= b.x2)))
            {
                return true;
            }
        }
        else
        {
            if (a.y1 > a.y2)
            {
                swap(a.x1, a.x2);
                swap(a.y1, a.y2);
            }
            if (b.y1 > b.y2)
            {
                swap(b.x1, b.x2);
                swap(b.y1, b.y2);
            }
            if (
                ((a.y1 <= b.y1) and (b.y1 <= a.y2)) or
                ((a.y1 <= b.y2) and (b.y2 <= a.y2)) or
                (b.y1 <= a.y1 and a.y2 <= b.y2))
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    Street s1, s2;
    std::cin >> s1.x1 >> s1.y1 >> s1.x2 >> s1.y2;
    std::cin >> s2.x1 >> s2.y1 >> s2.x2 >> s2.y2;
    if (cross(s1, s2))
    {
        std::cout << "YES" << std::endl;
    }
    else
    {
        std::cout << "NO" << std::endl;
    }
    return 0;
}