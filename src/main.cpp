#include <iostream>
#include <string>
#include <vector>
#include <functional>
#include <algorithm>

void forEach(const std::vector<int> & values, const std::function<void(int)>& func) {
    for (int value : values) {
        func(value);
    }
}
void print(int value) {
    std::cout << "Value: " << value << std::endl;
}
namespace apple {
    void print(const std::string& text) {
        std::cout << text << std::endl;
    }
}
namespace orange {
    void print(const char* text) {
        std::string temp = text;
        std::reverse(temp.begin(), temp.end());
        std::cout << temp << std::endl;
    }
}


using namespace apple;
using namespace orange; // 这会导致运行时的错

int main()
{
    // 会偷偷地调用来自 orange 的函数，而且不会报错，因为传入的是 “Hello” 是const char*类型
    print("Hello"); // 0 error, 0 warning 的错误
    
#if 0
    std::vector<int> values = {1, 3, 5, 4, 2};
    auto it = std::find_if(values.begin(), values.end(), [](int value) { return value > 3;});
    std::cout << *it << std::endl;
    int a = 5;
    auto lambda  = [=](int value) { std::cout << "Value: " << a << std::endl; };
    forEach(values, lambda);
#endif
    std::cin.get();
}