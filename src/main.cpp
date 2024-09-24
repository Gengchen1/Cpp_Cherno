#include <iostream>
#include <array>

template<typename T, int size>
void Printarray(const std::array<T, size>& data) {
    for (int i = 0; i < size; i++) {
        std::cout << data[i] << std::endl;
    }
}


int main()
{
    std::array<int, 5> Data = {1, 2, 3, 4, 5};
    Printarray<int, 5>(Data); 
    std::cin.get();
}