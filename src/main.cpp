#include <iostream>

using String = std::string;

class Entity
{
private:
    String m_Name;
public:
    Entity() : m_Name("Unknown") {}
    Entity(const String& name) : m_Name(name) {}

    const String& GetName() const { return m_Name; }
};

int main()
{
    int a =2;
    int* b = new int[50]; // 200 bytes

    Entity* entity = new Entity();
    Entity* e1 = new(b) Entity();
    Entity* e = (Entity*)malloc(sizeof(Entity));

    std::cin.get();
    delete entity; // 调用了C函数free；
};