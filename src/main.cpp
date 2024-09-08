#include <iostream>
#include <string>
#include <vector>


struct Vertex
{
    float x, y, z;
    Vertex(float x, float y, float z)
        : x(x), y(y), z(z)
        {

        }
    Vertex(const Vertex& other)
        : x(other.x), y(other.y), z(other.z)
    {
        std::cout << "Copied!" << std::endl;   
    }
};

int main()
{
    // std::vector<Vertex> vectices;
    // vectices.push_back(Vertex(1, 2, 3)); // 当创建了一个Vertex类对象，然后将其放入vector时，产生了一个复制
    // vectices.push_back(Vertex(4, 5, 6)); // 这时直接产生了两个复制，因为会把之前的第一个Vertex对象也复制一次. 再加上自己传入一次
    // vectices.push_back(Vertex(7, 8 ,9)); // 到这里时，会复制前面的两个，然后自己传入一次。
    
    std::vector<Vertex> vectices;
    vectices.reserve(3); // 解决了每次内存不够，分配新内存，而把前面的都复制一遍再重新放入新内存的问题。
    vectices.emplace_back(1, 2, 3); //
    vectices.emplace_back(4, 5 ,6); // 
    vectices.emplace_back(7, 8 ,9); // 使用emplace_back 加只传入构造函数参数列表的方法，解决了先在mian栈中创建，然后复制一次的问题。
    
    std::cin.get();
}