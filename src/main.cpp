#include <iostream>
#include <string>
#include <stdlib.h>
#include <cstring>

int main()
{
    using namespace std::string_literals;

    std::u32string name0 = U"Cherno"s + U" hello";

    const char* example = R"(line1
    line2
    line3
    line4)";

    
    const char *name = u8"Cherno";
    const wchar_t* name2 = L"Cherno";


    const char16_t* name3 = u"Cherno"; // wchar 和 char16_t 有什么区别？
    // 看起来都是2字节，但是wchar每个字符实际上是由编译器决定的。可能是1字节，2字节，或者4字节。
    // 在windows上是2字节，linux上是4字节，mac上也是4字节。
    const char32_t* name4 = U"Cherno";
    
    
    std::cout << strlen(name) << std::endl;
    std::cout << "size of name3: " << sizeof(name3) << std::endl;
    std::cout << "size of name2: " << sizeof(name2) << std::endl;
    std::cin.get();
};