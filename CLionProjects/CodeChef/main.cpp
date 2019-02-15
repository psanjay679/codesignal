#include <iostream>
#include <vector>
#include <algorithm>
#include "reverse_in_parenthesis.h"
#include <string>

int main() {

    std::string s;
    std::cin >> s;
    std::cout << "Going to reverse substring in parenthesis" << std::endl;
    s = reverseInParentheses(s);
    std::cout << s << std::endl;

    return 0;
}