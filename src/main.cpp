#include <iostream>

class Base {
public:
    Base() { std::cout << "Base Constructor\n"; }
    virtual ~Base() { std::cout << "Base Destructor\n"; }
};

class Derived : public Base {
public:
    Derived() { std::cout << "Derived Constructor\n"; }
    ~Derived() { std::cout << "Derived Destructor\n"; }
};
class Derived1 : public Derived {
public:
    Derived1() { std::cout << "Derived1 Constructor\n"; }
    ~Derived1() { std::cout << "Derived1 Destructor\n"; }
};

int main()
{
    Base* base = new Base();    
    delete base;
    std::cout << "-----------------\n";
    Derived* derived = new Derived();
    delete derived;
    std::cout << "-----------------\n";
    Base* poly = new Derived(); // 如果基类加了虚析构，就从被调用的一级开始析构
    delete poly;
    std::cout << "-----------------\n";
    Derived* poly1 = new Derived1(); // 验证从哪一级开始调用析构
    delete poly1;
    std::cout << "-----------------\n";


    std::cin.get();
}