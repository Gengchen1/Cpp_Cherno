#include <iostream>

struct Vector3
{
    float x, y, z;
};

class Entity
{
public:
    void Print() const { std::cout << "Hello!" << std::endl; }
};

class ScopedPtr
{
private:
    Entity* m_Obj;
public:
    ScopedPtr(Entity* entity)
        : m_Obj(entity)
    {

    }
    ~ScopedPtr()
    {
        delete m_Obj; 
    }
    Entity* operator->()
    {
        return m_Obj;
    }
    // const Entity* operator->() const
    // {
    //     return m_Obj;
    // }
}; 

int main()
{
    size_t offset = (size_t)&((Vector3*)0)->z;
    std::cout << offset << std::endl;
    
    // const ScopedPtr entity = new Entity();  
    // entity->Print();

    std::cin.get();
}