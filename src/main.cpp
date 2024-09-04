#include <iostream>
#include <string>

class Entity
{
private:
    std::string m_Name;
    int m_Age;
public:
    Entity(const std::string& name)
        : m_Name(name), m_Age(-1) {}
    // Entity(int age)
    //     : m_Name("Unknown"), m_Age(age) {}
    explicit Entity (int age)
        : m_Name("Unknown"), m_Age(age) {}

};

int main()
{
    // Entity a = 22; // ok
    Entity a = (Entity)22;
    Entity b = std::string("Cherno"); // error 
    Entity b = "Cherno"; // error "Cherno" 是一个const char*类型,不是string 
    Entity a(22); 
    Entity b("Cherno");


    std::cin.get();
}