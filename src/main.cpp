#include <iostream>


struct Entity{
    int x, y;
    int* GetPosition() {
        return &x;
    }
};

int main()
{
    Entity e = {5, 8};
    // int *position = (int*)&e;
    int *position = e.GetPosition();
    std::cout << position[0] << "," << position[1] << std::endl;
    int y = *(int*)((char*)&e + 4);
    std::cout << y << std::endl;
    int a = 50;
    // double value = a; // 隐式转换
    double value = *(double*)&a; 
    std::cout << value << std::endl;
    
    std::cin.get();
}