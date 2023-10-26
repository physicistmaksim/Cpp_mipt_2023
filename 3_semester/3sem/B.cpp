#include <iostream>

int gcd(int a, int b)
{
    if(a < 0)
        a = -a;
    if(b < 0)
        b= -b;
    int result;
    if(a < b)
        result = a;
    else
        result = b;
    while (result > 0) {
        if (a % result == 0 && b % result == 0) {
            break;
        }
        result--;
    }
    return result;
}

class Rational final {
public:
    Rational(int numerator = 0, int denominator = 1): m_numerator(numerator/a), m_denominator(denominator/a) 
    {
        int a;
        if(gcd(numerator, denominator) != 0)
            a = gcd(numerator, denominator);
        else
            a = 1;
    }
    Rational(const Rational& other) = default;

    void print() const
    {
        std::cout << m_numerator << "/" << m_denominator << std::endl;
    }

    Rational& operator=(const Rational& other)
    {
        this->m_numerator = other.m_numerator;
        this->m_denominator = other.m_denominator;
        return (*this);
    }

    Rational& operator+=(const Rational &rha)
    {
        int new_denominator = (this->m_denominator * rha.m_denominator)/gcd(this->m_denominator, rha.m_denominator);
        this->m_numerator = (this->m_numerator * (new_denominator/this->m_denominator)) + (rha.m_numerator * (new_denominator/rha.m_denominator));
        this->m_denominator = new_denominator;
        new_denominator = gcd(this->m_numerator, this->m_denominator);
        this->m_numerator = this->m_numerator/new_denominator;
        this->m_denominator = this->m_denominator/new_denominator;
        if(this->m_denominator < 0)
        {
            this->m_denominator = - this->m_denominator;
            this->m_numerator = - this->m_numerator;
        }
        return *this;
    }

    Rational operator+() const {
        return *this;
    }

    Rational operator-() const {
        return Rational(-m_numerator, m_denominator);
    }

    Rational operator+(const Rational &other) const
    {
        Rational res = (*this);
        res += other;
        return res;
    }

    Rational& operator-=(const Rational &rha)
    {
        int new_denominator = (this->m_denominator * rha.m_denominator)/gcd(this->m_denominator, rha.m_denominator);
        this->m_numerator = (this->m_numerator * (new_denominator/this->m_denominator)) - (rha.m_numerator * (new_denominator/rha.m_denominator));
        this->m_denominator = new_denominator;
        new_denominator = gcd(this->m_numerator, this->m_denominator);
        this->m_numerator = this->m_numerator/new_denominator;
        this->m_denominator = this->m_denominator/new_denominator;
        if(this->m_denominator < 0)
        {
            this->m_denominator = - this->m_denominator;
            this->m_numerator = - this->m_numerator;
        }
        return *this;
    }

    Rational operator-(const Rational &other) const
    {
        Rational res = (*this);
        res += other;
        return res;
    }

    Rational& operator*=(const Rational &rha)
    {
        this->m_numerator = this->m_numerator * rha.m_numerator;
        this->m_denominator = this->m_denominator * rha.m_denominator;
        int new_denominator = gcd(this->m_numerator, this->m_denominator);
        this->m_numerator = this->m_numerator/new_denominator;
        this->m_denominator = this->m_denominator/new_denominator;
        if(this->m_denominator < 0)
        {
            this->m_denominator = - this->m_denominator;
            this->m_numerator = - this->m_numerator;
        }
        return (*this);
    }

    Rational operator*(const Rational &other) const
    {
        Rational res = (*this);
        res *= other;
        return res;
    }

    Rational& operator/=(const Rational &rha)
    {
        this->m_numerator = this->m_numerator * rha.m_denominator;
        this->m_denominator = this->m_denominator * rha.m_numerator;
        int new_denominator = gcd(this->m_numerator, this->m_denominator);
        this->m_numerator = this->m_numerator/new_denominator;
        this->m_denominator = this->m_denominator/new_denominator;
        if(this->m_denominator < 0)
        {
            this->m_denominator = - this->m_denominator;
            this->m_numerator = - this->m_numerator;
        }
        return (*this);
    }

    Rational operator/(const Rational &other) const
    {
        Rational res = (*this);
        res /= other;
        return res;
    }

    explicit operator double() const
    {
        double numerator = double(this->m_numerator);
        double denominator = double(this->m_denominator);
        return numerator/denominator;
    }

    double toDouble() const
    {
        double numerator = double(this->m_numerator);
        double denominator = double(this->m_denominator);
        return numerator/denominator;
    }

private:
    friend bool operator>(const Rational &lha, const Rational &rha);
    friend bool operator<(const Rational &lha, const Rational &rha);
    friend bool operator>=(const Rational &lha, const Rational &rha);
    friend bool operator<=(const Rational &lha, const Rational &rha);
    friend bool operator==(const Rational &lha, const Rational &rha);
    friend bool operator!=(const Rational &lha, const Rational &rha);

    friend Rational operator+(int lha, const Rational rha);
    friend Rational operator-(int lha, const Rational rha);
    friend Rational operator*(int lha, const Rational rha);
    friend Rational operator/(int lha, const Rational rha);

    int m_numerator;
    int m_denominator;
};

Rational operator+(int lha, const Rational rha)
{
    Rational res = Rational(lha, 1);
    res += rha;
    res.m_numerator = res.m_numerator/gcd(res.m_numerator, res.m_denominator);
    res.m_denominator = res.m_denominator/gcd(res.m_numerator, res.m_denominator);
    if(res.m_denominator < 0)
    {
        res.m_denominator = - res.m_denominator;
        res.m_numerator = - res.m_numerator;
    }
    return res;
}

Rational operator-(int lha, const Rational rha)
{
    Rational res = Rational(lha, 1);
    res -= rha;
    res.m_numerator = res.m_numerator/gcd(res.m_numerator, res.m_denominator);
    res.m_denominator = res.m_denominator/gcd(res.m_numerator, res.m_denominator);
    if(res.m_denominator < 0)
    {
        res.m_denominator = - res.m_denominator;
        res.m_numerator = - res.m_numerator;
    }
    return res;
}

Rational operator*(int lha, const Rational rha)
{
    Rational res = Rational(lha, 1);
    res *= rha;
    res.m_numerator = res.m_numerator/gcd(res.m_numerator, res.m_denominator);
    res.m_denominator = res.m_denominator/gcd(res.m_numerator, res.m_denominator);
    if(res.m_denominator < 0)
    {
        res.m_denominator = - res.m_denominator;
        res.m_numerator = - res.m_numerator;
    }
    return res;
}

Rational operator/(int lha, const Rational rha)
{
    Rational res = Rational(lha, 1);
    res /= rha;
    res.m_numerator = res.m_numerator/gcd(res.m_numerator, res.m_denominator);
    res.m_denominator = res.m_denominator/gcd(res.m_numerator, res.m_denominator);
    if(res.m_denominator < 0)
    {
        res.m_denominator = - res.m_denominator;
        res.m_numerator = - res.m_numerator;
    }
    return res;
}

bool operator>(const Rational &lha, const Rational &rha)
{
    int new_denominator = (lha.m_denominator * rha.m_denominator)/gcd(lha.m_denominator, rha.m_denominator);
    if(lha.m_numerator * (new_denominator/lha.m_denominator) > rha.m_numerator * (new_denominator/rha.m_denominator))
        return true;
    return false;
}

bool operator<(const Rational &lha, const Rational &rha)
{
    int new_denominator = (lha.m_denominator * rha.m_denominator)/gcd(lha.m_denominator, rha.m_denominator);
    if(lha.m_numerator * (new_denominator/lha.m_denominator) < rha.m_numerator * (new_denominator/rha.m_denominator))
        return true;
    return false;
}

bool operator>=(const Rational &lha, const Rational &rha)
{
    int new_denominator = (lha.m_denominator * rha.m_denominator)/gcd(lha.m_denominator, rha.m_denominator);
    if(lha.m_numerator * (new_denominator/lha.m_denominator) >= rha.m_numerator * (new_denominator/rha.m_denominator))
        return true;
    return false;
}

bool operator<=(const Rational &lha, const Rational &rha)
{
    int new_denominator = (lha.m_denominator * rha.m_denominator)/gcd(lha.m_denominator, rha.m_denominator);
    if(lha.m_numerator * (new_denominator/lha.m_denominator) <= rha.m_numerator * (new_denominator/rha.m_denominator))
        return true;
    return false;
}

bool operator==(const Rational &lha, const Rational &rha)
{
    int new_denominator = (lha.m_denominator * rha.m_denominator)/gcd(lha.m_denominator, rha.m_denominator);
    if(lha.m_numerator * (new_denominator/lha.m_denominator) == rha.m_numerator * (new_denominator/rha.m_denominator))
        return true;
    return false;
}

bool operator!=(const Rational &lha, const Rational &rha)
{
    int new_denominator = (lha.m_denominator * rha.m_denominator)/gcd(lha.m_denominator, rha.m_denominator);
    if(lha.m_numerator * (new_denominator/lha.m_denominator) != rha.m_numerator * (new_denominator/rha.m_denominator))
        return true;
    return false;
}

int main()
{
    Rational A = Rational(1, 3);
    A.print();
    Rational B = Rational(-2, 4);
    std::cout << "B = "; B.print();
    Rational C;
    A += B;
    A.print();
    A /= B;
    std::cout << "A = "; A.print();
    Rational D = A - B;
    D.print();
    double d = D.toDouble();
    std::cout << d << std::endl;
    bool res = A != B;
    std::cout << res << std::endl;
    Rational E = 3 - Rational(9, 5); 
    E.print();
}