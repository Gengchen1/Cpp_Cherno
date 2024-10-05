#include <iostream>
#include <chrono>

struct Timer{
    std::chrono::_V2::system_clock::time_point start;
    std::chrono::_V2::system_clock::time_point end;
    std::chrono::duration<float> duration;
    Timer()
         : start(std::chrono::high_resolution_clock::now()) {}
    ~Timer() {
        end = std::chrono::high_resolution_clock::now();
        duration = end - start;
        float ms = duration.count() * 1000.0f;
        std::cout << "Time took " << ms << "ms " << std::endl;
    }
};

void draw1() {
    Timer timer;
    int** a2d = new int*[5]; 

    for (int i = 0; i < 5; i++) {
        a2d[i] = new int[5];
    }
    for (int x = 0; x < 5; x++) {
        for (int y = 0; y < 5; y++) {
            a2d[x][y] = 2;
        }
    }
    for (int i = 0; i< 5; i++) {
        delete[] a2d[i];
    }
    delete[] a2d;
}
void draw2() {
    Timer timer;
    int *array = new int[5 * 5];
    for (int x = 0; x < 5; x++) {
        for (int y = 0; y < 5; y++) {
            array[x * 5 + y] = 2;
        }
    }
    delete[] array;
}

int main()
{
    draw1();
    draw2();
    std::cin.get();
}