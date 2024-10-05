#include <iostream>
#include <thread>

static bool s_Finished = false;

void DoWork() {   
    // 这个线程的ID
    std::cout << "Started thread id = " << std::this_thread::get_id() << std::endl;
    using namespace std::literals::chrono_literals; // 引入了时间字面量
    while (!s_Finished) {
        std::cout << "working...\n";
        std::this_thread::sleep_for(1s);
    }
}
int main()
{
    std::thread worker(DoWork); // worker子线程执行DoWork

    std::cin.get(); // cin.get()函数，等待用户输入
    s_Finished = true; // 用户输入之后子线程结束

    worker.join(); // 等待子线程加入，子线程结束后就会加入
    std::cout << "Finished." << std::endl;
    // 这是主线程的ID 
    std::cout << "Started thread id = " << std::this_thread::get_id() << std::endl;

    std::cin.get();
}