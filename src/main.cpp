#include <iostream>
#include <string>
#include <vector>
#include <functional>
#include <algorithm>

namespace apple { namespace function {

    void print(const std::string& text) {
        std::cout << text << std::endl;
    }
}
    void print_again() {}
}
namespace orange {
    void print(char* text) {
        std::string temp = text;
        std::reverse(temp.begin(), temp.end());
        std::cout << temp << std::endl;
    }
}

int main()
{
    namespace a = apple::function;
    using apple::print_again;
    a::print("Hello"); 
    print_again();
    orange::print("Hello"); 
    std::cin.get();
}