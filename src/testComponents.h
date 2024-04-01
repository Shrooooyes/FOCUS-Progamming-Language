#ifndef TESTCOMPONENT_H
#define TESTCOMPONENT_H

#include <iostream>
#include <string>
#include <cstdlib>

void checkBrackets(std::string brackets)
{
    int n = brackets.length();
    int start = 0, end = n - 1;

    while (start < n)
    {
        char c = brackets.at(start);
        if (c == '{')
        {
            break;
        }
        start++;
    }

    if (start >= end)
    {
        std::cout << "bruh!! Brackets...." << std::endl;
        exit(EXIT_FAILURE);
    }

    while (start <= end)
    {
        char startChar = brackets.at(start), endChar = brackets.at(end);
        if (startChar == '{' && endChar == '}')
        {
            start++;
            end--;
        }
        else if (startChar == '[' && endChar == ']')
        {
            start++;
            end--;
        }
        else if (startChar == '(' && endChar == ')')
        {
            start++;
            end--;
        }
        else
        {
            end--;
        }
    }

    if (end == n - 1)
    {
        std::cout << "bruh!! Brackets...." << std::endl;
        exit(EXIT_FAILURE);
    }
}

#endif // !TESTCOMPONENT_H