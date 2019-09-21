#include <iostream>

class Base
{
public:
    Base();
    virtual void f() {

    }
    ~Base();
};

class Detrive : public Base
{
public:
    Detrive();
    virtual ~Detrive() = default;
    
};

int main(int argc, char const *argv[])
{
    Detrive d;
    
    return 0;
}