#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>


int main()
{
    std::vector<int> values = {1, 4, 2, 5, 3}; 
    std::sort(values.begin(), values.end(),[](int a, int b) {
        if (a == 1) 
            return false;
        if (b == 1)
            return true;
        return a < b; 
    }); // 不给第三个参数，对于整数默认是升序


    for (int value : values) 
        std::cout << value << std::endl;

    std::cin.get();
}