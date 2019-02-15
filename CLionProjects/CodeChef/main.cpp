#include <iostream>
#include <vector>
#include <algorithm>
#include "reverse_in_parenthesis.cpp"
#include <string>

int main() {

    std::string s;
    std::cin >> s;

    s = reverseInParentheses(s);
    std::cout << s << std::endl;

    return 0;
}