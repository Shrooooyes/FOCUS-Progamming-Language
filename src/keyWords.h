#ifndef KEYWORDS_H

#include <iostream>
#include <string>
#include <cstdlib>

const std::string keyWords[] = {"COm"};

void executeKeywordAction(const std::string &keyword, std::string command)
{
    std::string cmd = command.substr(keyword.length() - 1, command.length());

    if (keyword == "COm")
    {
        bool quotesFlag = false;
        std:: string statement = "echo ";
        for (int i = 0; i < cmd.length(); i++)
        {
            char c = cmd.at(i);
            if (c == '\"' || (c == '\"' && cmd.at(i - 1) == '\\'))
            {
                quotesFlag = !quotesFlag;
            }
            else if (quotesFlag)
            {
                statement += c;
            }
        }

        int val = system(statement.c_str());

        if (val == 0)
        {
            exit(EXIT_SUCCESS);
        }
        else
        {
            exit(EXIT_FAILURE);
        }
    }
}

void checkKeyword(const std::string &mainFok)
{
    int n = mainFok.length();
    for (int i = 0; i < n; i++)
    {
        char c = mainFok.at(i);
        for (const std::string &keyword : keyWords)
        {
            if (i >= n - keyword.length())
            {
                break;
            }
            else if (mainFok.substr(i, keyword.length()) == keyword)
            {
                std::string command;
                for (int j = i; j < n - keyword.length(); j++)
                {
                    char a = mainFok.at(j);
                    if (c == '.')
                    {
                        break;
                    }
                    command += a;
                }
                executeKeywordAction(keyword, command);
            }
        }
    }
}

#endif // !KEYWORDS_H