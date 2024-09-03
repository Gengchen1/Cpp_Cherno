#include <iostream>

static int s_Level = 8;
static int s_Speed = 2;


int main()
{
    // if (s_Level > 5)
    //     s_Speed = 10;
    // else
    //     s_Speed = 5;
    // s_Speed = s_Level > 5 ? 10 : 5; // 在根据一种特定条件给变量赋值时使用
    s_Speed = s_Level > 5 && s_Level < 10 ? s_Level > 10 ? 15 : 10 : 5; // 三元算符的嵌套
    // 尽量不要向上面这样做嵌套。
    // std::string rank = s_Level > 10 ? "Master" : "Beginner";

    std::cout << s_Speed << std::endl;

    std::cin.get();
};