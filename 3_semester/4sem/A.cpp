#include <iostream>

struct Character
{
    protected:
        std::string const & name() const;
        unsigned health() const;
};

struct LongRange : public Character
{
    protected:
        unsigned range() const;
};

struct SwordsMan : public Character
{
    unsigned strength() const;    
};

struct Wizard : public LongRange
{
    unsigned mana() const;
};

struct Archer : public LongRange
{
    unsigned accuracy() const;
};
