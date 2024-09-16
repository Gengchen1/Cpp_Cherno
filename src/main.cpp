#include <iostream>
#include <tuple>
#include <array>

struct result
{
    std::string str;
    int val;
};
result Function()
{
    return {"1", 1};
}

struct Result
{
    int add;
    int sub;
};

Result operation(int a, int b)
{
    Result ret;
    ret.add = a + b;
    ret.sub = a - b;
    return ret;
}


// void GetUserAge(const std::string &user_name, bool &work_status, int &age)
// {
//     if (user_name.compare("xiaoli") == 0)
//     {
//         work_status = true;
//         age = 18;
//     }
//     else
//     {
//         work_status = false;
//         age = -1;
//     }
// }

std::array<std::string, 2> ChangeString()
{
    std::string a = "1";
    std::string b = "2";

    std::array<std::string, 2> result;
    result[0] = a;
    result[1] = b;
    return result;
}

std::pair<bool, int> GetUserAge(const std::string& user_name)
{
    std::pair<bool, int> result;
    if(!user_name.compare("xiaoli"))
    {
        result = std::make_pair(true, 18);
    }
    else
    {
        result = std::make_pair(false, -1);
    }
    return result;
}

std::tuple<bool, int, int> GetUserAge1(const std::string& user_name)
{
    std::tuple<bool, int, int> result;
    if (!user_name.compare("xiaoli"))
    {
        result = std::make_tuple(true, 18, 0);
    }
    else
    {
        result = std::make_tuple(false, -1, -1);
    }
    return result;
}
int main()
{
    // bool work_status = false;
    // int age = -1;
    std::tuple<bool, int, int> result = GetUserAge1("xiaolili");
    bool work_status;
    int age;
    int user_id;
    std::tie(work_status,age, user_id) = result;
    // std::pair<bool, int> result = GetUserAge("xiaoli");
    std::cout << "查询结果：" << work_status << "  "
              << "年龄： " << age << "  " << "用户ID: " << user_id << std::endl;
    auto temp = Function();
    std::cout << temp.str << ' ' << temp.val << std::endl;
    Result res;
    res = operation(5, 3);
    std::cout << "5 + 3 = " << res.add << std::endl;
    std::cout << "5 - 3 = " << res.sub << std::endl;
    std::cin.get();
}