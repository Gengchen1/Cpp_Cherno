#include <iostream>
#include <string>
#include <vector>

struct Vertex
{
    float x, y, z;
};

std::ostream& operator<<(std::ostream& stream, const Vertex& vertex)
{
    stream << vertex.x << ", " << vertex.y << ", " << vertex.z;
    return stream;
}

int main()
{
    std::vector<Vertex> vertices;
    vertices.push_back({1, 2, 3});
    vertices.push_back({4, 6, 7});

    // for (int i = 0; i < vertices.size(); i++)
    //     std::cout << vertices[i] << std::endl;
    vertices.erase(vertices.begin() + 1);
    // vertices.clear();
    for (Vertex& v : vertices) // 对于vertices中的每一个元素，将其值被Vertex类型的变量v所引用.
        std::cout << v << std::endl;

    std::cin.get();
}