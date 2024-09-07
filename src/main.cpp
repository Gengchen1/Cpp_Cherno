#include <iostream>
#include <string>
#include <memory>

class Entity
{
public:
    Entity()
    {
        std::cout << "Created Entity!" << std::endl;
    }
    ~Entity()
    {
        std::cout << "Destoryed Entity!" << std::endl;
    }

    void Print() {}
};

int main()
{
    { 
        std::shared_ptr<Entity> e0; 
        std::weak_ptr<Entity> e2;
        {
            // std::unique_ptr<Entity> entity = new Entity(); // error! 因为unique_ptr是需要显式调用构造函数，它是 explicit的。
            // std::unique_ptr<Entity> entity(new Entity()); // 这样可以，但是不安全，一旦Entity的构造函数发生异常造成一个空指针；
            // std::unique_ptr<Entity> entity = std::make_unique<Entity>(); // 推荐! 这样更加安全. 
            std::shared_ptr<Entity> sharedEntity = std::make_shared<Entity>();  // 引用1次
            // std::shared_ptr<Entity> sharedEntity(new Entity()); // 也不建议, 因为shared_ptr会分配一块叫控制块的内存,用来存储计数,
            // new Entity() 也会分配一次内存, 造成效率降低

            // e0 = sharedEntity; // 共享指针可以复制;引用两次
            // std::unique_ptr<Entity> e1 = entity; // error!
            // entity->Print();
            e2 = sharedEntity; // 可以复制，但不会增加引用次数。
        } // 引用次数-1，sharedEntity死了
    }
    std::cin.get(); // 引用次数为0，调用delete,释放内存。
}