#include <iostream>

class Example
{
public:
    Example()
    {
        std::cout << "Created Entity !"<< std::endl; 
    }

    Example(int x)
    {
        std::cout << "Created Entity with" << x << "!" << std::endl;
    }
};

class Entity
{
private:
    std::string m_Name;
    int m_Score;
    Example m_Example;
public:
    // Entity()// 创建两次Example对象
    // {
    //     m_Name = "Unknown";
    //     m_Example = Example(8);
    // }
    // Entity(const std::string &name)
    // {
    //     m_Name = name;
    // }
    Entity()
        : m_Name("Unknown"), m_Score(0), m_Example(Example(8))
    {
    }
    Entity(const std::string &name)
        : m_Name(name), m_Score(0)
    {
    }

    const std::string &GetName() const { return m_Name; }
};

int main()
{
    Entity e0;
    // std::cout << e0.GetName() << std::endl;

    // Entity e1("Cherno");
    // std::cout << e1.GetName() << std::endl;

    std::cin.get();
};