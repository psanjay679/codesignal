//
// Created by codechef on 2/21/19.
//

#include "codesignal.h"


bool isIPv4Address(std::string inputString)
{
    int int_count = 0;
    int i = 0;

    std::string number = "";

    int i_number = 0;

    while (i < inputString.length())
    {
        while (inputString[i] != '.' && inputString[i] != '\0')
        {
            if (isdigit(inputString[i]))
            {
                number += inputString[i];
                i++;
                continue;
            }
            else
            {
                return false;
            }
        }


        if (number.length() == 0)
        {
            return false;
        }

        i_number = stoi(number);

        if (i_number > 255)
        {
            return false;
        }
        int_count += 1;
        i++;
        number.clear();
    }

    if (int_count == 4)
    {
        return true;
    }
    else
    {
        return false;
    }
}
