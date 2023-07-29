//
// Created by lee bin on 2023/7/29.
//

#include <iostream>
#include <string>
#include <vector>
#include <boost/algorithm/string.hpp>
#include <boost/regex.hpp>

int main() {
    // String splitting with Boost
    std::string input = "Hello,Boost,C++,Demo";
    std::vector<std::string> tokens;
    boost::split(tokens, input, boost::is_any_of(","));

    std::cout << "String Splitting Demo:" << std::endl;
    for (const auto &token: tokens) {
        std::cout << token << std::endl;
    }

    // Regular expression matching with Boost
    std::string text = "The phone number is 123-456-7890 and another number is 987-654-3210.";
    boost::regex phone_pattern("\\b\\d{3}-\\d{3}-\\d{4}\\b");
    boost::sregex_iterator it(text.begin(), text.end(), phone_pattern);
    boost::sregex_iterator end;

    std::cout << "\nPhone Numbers in the Text:" << std::endl;
    while (it != end) {
        std::cout << it->str() << std::endl;
        ++it;
    }

    return 0;
}
