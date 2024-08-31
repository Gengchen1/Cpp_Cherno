#include <iostream>
#include <string>

class Entity
{
private:
    std::string m_Name;
    mutable int m_DebugCount = 0; // 所以把类成员变量标记为mutable,意味着类中的const方法可以修改这个成员。
public:
    const std::string& GetName() const
    {
        m_DebugCount++;
        return m_Name;
    }
};

int main()
{
    const Entity e;
    e.GetName();

    int x = 0;
    auto f = [=]() mutable
    {
        x++;
        std::cout << "Hello" << std::endl;
    };

    f();

    std::cin.get();
};