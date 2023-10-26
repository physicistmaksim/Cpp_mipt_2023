#include <iostream>

struct StructBall //by default public
{
    int x, y, z, r;
};

class ClassBall //by default privite
{
    private:
        int x = 1, y = 2, z = 3;
    public:
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

        void move(int x, int y, int z)
        {
            this->x = x;
            this->y = y;
            this->z = z;
        }
        void print() const
        {
            std::cout << x << " " << y << " " << z << " " << r << std::endl;
            std::cout << "Volume of Ball: " << calcVoulume() << std::endl;
            std::cout << "Surface of Ball: " << calcSurface() << std::endl;
        }
        ~ClassBall()
        {
            std::cout << "~ClassBall(" << x << " " << y << " " << z << " " << r << ")" << std::endl;
        }
};

int main()
{
    //ClassBall ball0 = 2; // compiler will make from 2 ClassBall(2), but with explicit it can't do it
    ClassBall ball0 = ClassBall(2);
    ClassBall ball1 = ball1;
    ClassBall ball2 = ClassBall(1, 2, 3, 4);
    ball0.print();
    //ball0.move(0, 0, 0);
    //ball0.print();

    ball1.print();
    //ball1.move(0, 0, 0);
    //ball1.print();

    ball2.print();
    //ball2.move(0, 0, 0);
    //ball2.print();
    //ball0 + 2; //ball0 + ClassBall(2);
    //destructors called in reverse order
    ball0 = ball1;
    ball0.print();
    return 0;
}