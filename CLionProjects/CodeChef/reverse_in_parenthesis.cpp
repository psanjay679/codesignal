//
// Created by codechef on 2/15/19.
//


#include "reverse_in_parenthesis.h"

std::string reverseInParentheses(std::string inputString) {

    while(std::find(inputString.begin(), inputString.end(), ')') != inputString.end() && std::find(inputString.begin(), inputString.end(), ')') != inputString.end()) {
        int opening = inputString.find('(') + 1;
        int closing = inputString.find(')');
        std::reverse(inputString.begin() + opening, inputString.begin() + closing);
        inputString.erase(std::find(inputString.begin(), inputString.end(), '('));
        inputString.erase(std::find(inputString.begin(), inputString.end(), ')'));
    }

    return inputString;
}
