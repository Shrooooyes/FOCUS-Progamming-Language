#include "iostream"
#include "fstream"

// files
 #include "testComponents.h"
 #include "keyWords.h"

void checkValidFile(std::string fileName)
{
    int n = fileName.length();
    char c = fileName.at(0);

    std::string ext;
    int i = n - 1;

    while (c != '.')
    {
        c = fileName.at(i);
        ext = c + ext;
        i--;
    }

    if (ext != ".foc")
    {
        std::cout << "Not Valid File.." << std::endl;
        std::cout << "Correct file type <file_name>.foc" << std::endl;
        std::cout << "Do you want to \"Rename\" the file? (y/n): " << std::endl;
        std::cin >> c;
        if (tolower(c) == 'n')
        {
            exit(EXIT_FAILURE);
        }
        else if (tolower(c) == 'y')
        {
            std::string newFileName = "../code/" + fileName.substr(0, i + 1) + ".foc";
            fileName = "../code/" + fileName;
            std::rename(fileName.c_str(), newFileName.c_str());
        }
    }
}

void getBrackets(std::string mainFok)
{
    std::string brackets;
    bool quotesFlag = false;

    // find first bracket - {
    int count = 0;
    while (true)
    {
        char c = mainFok.at(count);
        if (c == '{')
        {
            break;
        }
        count++;
    }

    for (int i = count; i < mainFok.length(); i++)
    {
        char c = mainFok.at(i);
        if (c == '\"')
        {
            quotesFlag = !quotesFlag;
        }
        else if (c == ';' && !quotesFlag)
        {
            break;
        }
        else if (c == '{' || c == '[' || c == '(' || c == '}' || c == ']' || c == ')')
        {
            brackets += c;
        }
    }
    checkBrackets(brackets);
}

void findMain(std::string filePath)
{
    std::fstream file;
    std::string line;
    file.open(filePath);

    int i = 1;
    std::string mainFok;
    while (getline(file, line))
    {
        if (line.substr(0, 7) == "mainFOk")
        {
            while (true)
            {
                if (line.substr(line.length() - 1, 1) == ";")
                {
                    break;
                }
                mainFok += line;
                getline(file, line);
            }
            mainFok += line;
            // std::cout << mainFok << std::endl;
        }
        i++;
    }
    getBrackets(mainFok);
    checkKeyword(mainFok);
}

int main(int argc, char const *argv[])
{
    std::fstream file;
    std::string fileName = std::string(argv[1]);

    std::string filePath = "../code/" + fileName;

    file.open(filePath);

    checkValidFile(fileName);
    findMain(filePath);

    std::cout << "code complete" << std::endl;

    return 0;
}
