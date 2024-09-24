#include <iostream>
#include <string>

// template<typename T> // typename 代表后面的参数是一个待指定的类型变量。

template<typename T, int size>
class Array
{
private:
    T m_Array[size];
public:
    int Getsize() const {return size;};
};

// void Print(T value)
// {
//     std::cout << value << std::endl;
// } // 该函数其实不是一个真正的函数，只有当输入参数的类型确定时，在编译阶段该函数才会被创建。
//如果Print函数没有在main函数中调用，那么它其实就是没有真正存在过。
// 只有当我们调用这个函数时，这个函数才会被创建，使用我们给定的模板参数。
// 只有当它基于模板的使用情况，发送到编译器，进行编译后，才会具体化为真正的代码。

int main()
{
    // Print(5); // 这时其实也隐式地得到了输入参数的类型是int,相当于下面这种写法：
    // Print<int>(5); // 在尖括号中输入int,也就是说T = int, T被替换成了int.
    // Print("Hello");
    // Print<std::string>("Hello");
    // Print(5.5f);
    // Print<float>(5.5f);
    Array<int, 5> array;
    std::cout << array.Getsize() << std::endl;
    std::cin.get();
    
}   