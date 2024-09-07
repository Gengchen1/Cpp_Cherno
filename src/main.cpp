#include <iostream>

class Entity
{
public:
    Entity()
    {
        std::cout << "Created Entity" << std::endl;
    }
    ~Entity()
    {
        std::cout << "Destoryed Entity" << std::endl;
    }
};
// 作用域指针，是一个类，在该类的对象结束时，自动释放其传入的分配在堆上的指针。
class ScopedPtr
{
private:
    Entity* m_Ptr;
public:
    ScopedPtr(Entity* ptr)
        : m_Ptr(ptr)
        {

        }
    ~ScopedPtr()
    {
        delete m_Ptr;
    }
};
int main()
{ 
    {
        // Entity e;
        // Entity* e = new Entity();
        ScopedPtr e = new Entity(); // 将new创建的内存指针传入作用域指针 e中，当作用域结束时，自动释放new分配的内存。
    }

    std::cin.get();
}