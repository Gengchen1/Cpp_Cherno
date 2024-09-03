#include <iostream>

using String = std::string;

class Entity
{
private:
    String m_Name;

public:
    Entity() : m_Name("Unknown") {}
    Entity(const String &name) : m_Name(name) {}

    const String &GetName() const { return m_Name; }
};

//如果想要类实例化的对象生存周期在函数之外
void Function()
{
    Entity entity("Cherno"); // 或者 Entity entity = Entity("Cherno");
}

int main()
{
    // 只要有花括号的，只要花括号之外，作用域就会失效。
    Entity *e;
    {
        // Entity entity("Cherno"); // 或者 Entity entity = Entity("Cherno");
        Entity *entity = new Entity("Cherno"); // 或者 Entity entity = Entity("Cherno");
        e = entity;
        std::cout << entity->GetName() << std::endl;
    }
    std::cin.get();
    delete e;
};