#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base* generate()
{
    int random = rand() % 3;
    if (random == 0) {
        std::cout << "creating A" << std::endl;
        return new A;
    }
    if (random == 1) {
        std::cout << "creating B" << std::endl;
        return new B;
    }
    return new C;
}

void identify(Base* p)
{
    if (dynamic_cast<A*>(p) != 0)
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p) != 0)
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p) != 0)
        std::cout << "C" << std::endl;
}

void identify(Base& p)
{
    try
    {
        (void)dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        return;
    } catch(...) {}
    try
    {
        (void)dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
        return;
    } catch(...) {}
    try
    {
        (void)dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
        return;
    } catch(...) {}
}


int main() {
    srand(time(NULL));

    Base* obj1 = generate();
    std::cout << "identify(Base*): ";
    identify(obj1);
    std::cout << "identify(Base&): ";
    identify(*obj1);
    delete obj1;

    Base* obj2 = generate();
    std::cout << "identify(Base*): ";
    identify(obj2);
    std::cout << "identify(Base&): ";
    identify(*obj2);
    delete obj2;

    return 0;
}
