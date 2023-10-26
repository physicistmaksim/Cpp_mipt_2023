#include <iostream>

struct StructBall //by default public
{
    int x, y, z, r;
};

class ClassBall //by default privite
{
    private:
        int x = 1, y = 2, z = 3;
        int r;
    private:
        int r_squared = 0;
        double calcVoulume() const
        {
            return 4. * 3.141592 /3. * r * r_squared;
        }
        double calcSurface() const
        {
            return 4. * 3.141592 * r_squared;
        }


    public:
        /* ClassBall(int x, int y, int z, int r)
        {
            this->x = x;
            this->y = y;
            this->z = z;
            this->r = r;
        }*/ // constructor of class (bad variant of initialization)

        ClassBall():
            ClassBall(0) { }
        ClassBall(int x, int y, int z, int r): 
            x(x), y(y), z(z), r(r),
            r_squared(r*r) { }
        /* ClassBall(int r):
            x(0), y(0), z(0), r(r), r_squared(r*r) { } */
        explicit ClassBall(int r): ClassBall(0, 0, 0, r) { }
        ClassBall(const ClassBall& other):
            x(other.x), y(other.y), z(other.z), r(other.r), r_squared(other.r_squared) { }
        void print() const
        {
            std::cout << x << " " << y << " " << z << " " << r << std::endl;
            std::cout << "Volume of Ball: " << calcVoulume() << std::endl;
            std::cout << "Surface of Ball: " << calcSurface() << std::endl;
        }
        ClassBall operator+(const ClassBall& other)
        {
            ClassBall res = (*this);
            res += other;
            return res;
        }
        ClassBall operator+=(const ClassBall& other)
        {
            this->x += other.x;
            this->y += other.y;
            this->z += other.z;
            return *this;
        }
        friend bool operator<(const ClassBall& lha, const ClassBall& rha);
};

bool operator<(const ClassBall& lha, const ClassBall& rha)
{
    return (lha.r < rha.r);
}


int main()
{
    ClassBall ball0 = ClassBall(1, 1, 1, 2);
    ClassBall ball1;
    ClassBall ball2 = ClassBall(1, 2, 3, 6);
    ball1.print();
    ball1 = ball0 + ball0; 
    ball1.print();
    ball1 += ball2;
    ball1.print();
    std::cout << (ball1 < ball2) << std::endl;
    return 0;
}