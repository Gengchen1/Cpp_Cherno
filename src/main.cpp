#include <iostream>
#include <cstring>

class String
{
private:
    char* m_Buffer;
    unsigned int m_Size;
public:
    String(const char* string)
    {
        m_Size = strlen(string);
        m_Buffer = new char[m_Size + 1];
        memcpy(m_Buffer, string, m_Size);
        m_Buffer[m_Size] = 0;
    }
    friend std::ostream& operator<<(std::ostream& stream, const String& string);

    // String(const String& other) = delete;
    // 深度拷贝
    String(const String& other)
        : m_Size(other.m_Size)
        {
            std::cout << "Copied String!" << std::endl;
            m_Buffer = new char[m_Size + 1];
            memcpy(m_Buffer, other.m_Buffer, m_Size + 1);
        }
    // String(const String& other)
    // {
    //     memcpy(this, &other, sizeof(String));
    // }

    ~String()
    {
        delete[] m_Buffer;
    }
    char& operator[](unsigned int index)
    {
        return m_Buffer[index];
    }

};


std::ostream& operator<<(std::ostream& stream, const String& string)
{
    stream << string.m_Buffer;
    return stream;
}

void PrintString(const String& string)
{
    std::cout << string << std::endl;
}

int main()
{
    String string = "Cherno"; // 隐式转换 String string("Cherno")
    String second = string; // 当我们使用 = 赋值时，将string中的所有成员变量和函数都复制到了一个新的内存地址。
    // 所以，里面的指针，m_Buffer也会被复制，也就是这两个m_Buffer是同一个内存地址，当作用域结束时，析构函数就会释放两次这个内存，导致程序崩溃。
    string[2] = 'a';
    // std::cout << string << std::endl;
    // std::cout << second << std::endl;
    PrintString(string);
    PrintString(second);

    std::cin.get();
}