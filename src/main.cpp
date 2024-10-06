#include <iostream>

struct Vector2 {
    float x, y;
};

struct Vector4 {
    union {
        // 第一个Union成员
        struct { // 如果 struct {}A;, 则需要vecotr.A.x来使用
            float x, y, z, w;
        };
        // 第二个Union成员
        struct {
            Vector2 a, b;
        };
    };
    // // 通过x获取一个指向Vector2的引用。
    // Vector2& GetA() {
    //     return *(Vector2*)&x;
    // }
};

void PrintVector(const Vector2& vector) {
    std::cout << vector.x << ", " << vector.y << std::endl;
}

int main()
{
    union {
        struct {
            int a, b;
        }A;
    };
    A.a = 2;
    A.b = 3;
    Vector4 vector = {1.0f, 2.0f, 3.0f, 4.0f};    
    PrintVector(vector.a);
    PrintVector(vector.b);
    vector.z = 500.0f;
    std::cout << "------------------" << std::endl;
    PrintVector(vector.a);
    PrintVector(vector.b);
    std::cout << A.a << ", " << A.b << std::endl;
    std::cin.get();
} 