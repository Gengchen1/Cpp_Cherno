#include <iostream>

class Base {
public:
    Base() {}
    virtual ~Base() {}
};

class Derived : public Base {
public:
    Derived() {}
    ~Derived() {}
};

class AnotherClass : public Base {
public:
    AnotherClass() {}
    ~AnotherClass() {}
};

int main()
{
    int a = 5;
    double value = a; // 并不会出错，进行了隐式转换。 
    // 或者
    double value1 = 5.25;
    int b = value1; // 也会进行隐式转换
    double c = (int)value1 + 5.3;
    Derived * derived = new Derived();
    Base* base = derived;
    AnotherClass* ac = dynamic_cast<AnotherClass*>(ac);
    std::cout << c << std::endl;
    std::cin.get();
}