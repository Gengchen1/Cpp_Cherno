#include <iostream>
#include <string>

class Entity
{
    int m_X, m_Y;
    mutable int var; // mutable就是允许const方法可以改变这个变量。
    // int* m_X, m_Y; // 这种情况只有m_X是指针，而m_Y还是int型。
    // int* m_X, *m_Y; // 这样才都是指针。
public:
    // const int* const  GetX() const // 用在方法参数列表后面，这意味这个方法不会修改任何实际的类。
    // {
    //     return m_X;
    // }

    int GetX() const // 用在方法参数列表后面，这意味这个方法不会修改任何实际的类。
    {
        var = 2;
        return m_X;
    }

    void SetX(int x)
    {
        m_X = x;
    }
};

void PrintEntity(const Entity& e) //引用没有指针那样有指针本身和指针指向内容的区别，因为引用就是内容。
{
 
    std::cout << e.GetX() << std::endl;
}

int main()
{
    Entity e;
    const int MAX_AGE = 90;

    int *a = new int; // 在堆上创建了一个指针。
    // const int* a = new int; // 创建一个常量指针。可以改变指针指向的内存地址，但是不能改变内存中的内容。
    // int* const a = new int; // 指针常量，可以改变指针指向内存中的内容，但是不能改变指针指向的内存地址。
    // const int* const a = new int; // 意味着即不能改变指针的内容也不能改变指针本身。

    *a = 2;              // 可以改变指针指向的内存内容
    a = (int *)&MAX_AGE; // 也可以改变指针指向的内存地址。
    a = nullptr;
    std::cout << *a << std::endl;

    std::cin.get();
};
// const在*号右边，就是指针常量，指针所指向的内存地址无法改变。
// const在*号左边，就是常量指针，指针所指向的内存中的内容无法改变。