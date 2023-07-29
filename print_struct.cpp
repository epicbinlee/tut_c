#include <iostream>
#include <utility>

struct Person {
    std::string name;
    int age;
    std::string occupation;

    // 构造函数，使用成员初始化列表对所有成员变量进行初始化
    // 当你使用std::move时，通常是为了在某些情况下将资源的所有权从一个对象转移到另一个对象，而不进行深拷贝，从而提高性能。
    Person(std::string n, int a, std::string o) : name(std::move(n)), age(a), occupation(std::move(o)) {
    }
};

int main() {
    // 使用构造函数创建结构体对象
    Person person1("John", 30, "Engineer");
    Person person2("Alice", 25, "Teacher");

    // 打印结构体的内容
    std::cout << "Person 1:" << std::endl;
    std::cout << "Name: " << person1.name << std::endl;
    std::cout << "Age: " << person1.age << std::endl;
    std::cout << "Occupation: " << person1.occupation << std::endl;

    std::cout << "\nPerson 2:" << std::endl;
    std::cout << "Name: " << person2.name << std::endl;
    std::cout << "Age: " << person2.age << std::endl;
    std::cout << "Occupation: " << person2.occupation << std::endl;

    return 0;
}
