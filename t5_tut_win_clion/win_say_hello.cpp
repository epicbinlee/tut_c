//
// Created by lee bin on 2023/7/29.
//

#include <iostream>
#include <string>

int main() {
    // 打印输出到标准输出流
    std::cout << "Hello, World!" << std::endl;
    // 使用stl模板
    std::string greeting = "Hello, World!";
    auto length = greeting.length();
    std::cout << "Length of the string: " << length << std::endl;

    return 0;
}