#include <iostream>
#include <vector>
#include <algorithm>
#include "codesignal.h"
#include <string>

int main() {


    std::string s;

    std::cin >> s;

    bool is_correct = isIPv4Address(s);
    if (is_correct){
        std::cout << "true" << std::endl;
    } else{
        std::cout << "false" << std::endl;
    }

    return 0;
}