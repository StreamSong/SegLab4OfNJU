#include "User.hh"
#include <fstream>
#include <regex>
#include "stdlib.h"
#include "time.h"
#include <sys/types.h>
#include <dirent.h>
#include <iostream>
#include <string>

User::User()
{
    std::cout << "Please enter your UserID!\n";
    std::cin >> UserID;
    std::cout << "Please enter your UserName!\n";
    std::cin >> UserName;
    std::cout << "The system is getting your input, this may take a few seconds.\n";
    std::string path = "/home/cs144/SegLab4/input";
    DIR *pDir;
    struct dirent *ptr;
    if (!(pDir = opendir(path.c_str()))) // open the "input" folder
    {
        std::cout << "Can't open the input folder!";
        return;
    }
    while ((ptr = readdir(pDir)) != NULL)
    {
        std::string pathNext = path + "/" + ptr->d_name;

        // std::cout << pathNext.c_str() << "\n";

        // This "if-else" is necessary, because the ptr could start from ".."
        if (strcmp(ptr->d_name, ".") == 0 || strcmp(ptr->d_name, "..") == 0)
            continue;

        DIR *pDirNext = opendir(pathNext.c_str());
        // DIR *pDirNext;
        struct dirent *ptrNext;
        if (pDirNext == NULL) // open the next folder that contains files
        {
            std::cout << "Can't open the input folder!";
            return;
        }
        while ((ptrNext = readdir(pDirNext)) != NULL)
        { // get each file
            std::string Filename = ptrNext->d_name;
            // if ".txt" then generate input
            if (Filename.find(".txt") != std::string::npos)
            { // the format file
                std::string Filepath = pathNext + "/" + Filename;
                std::string FolderPath = pathNext;
                GenerateInput(Filepath, FolderPath);
            }
        }
    }
    closedir(pDir);
    std::cout << "Finish input. Welcome " << UserName << "!\n";
}

User::~User()
{
    std::cout << "Goodbye, " << UserName << "!";
}

void User::GenerateInput(std::string FilePath, std::string FolderPath)
{
    srand((unsigned)time(NULL));
    // number of random inputs, all this number of inputs will be written in Input.txt
    static const int NUMOFINPUT = 5;
    // std::string inputPath = FolderPath + "/Input.txt";
    // std::ofstream Input(inputPath);

    for (int i = 0; i < NUMOFINPUT; ++i)
    {
        std::string inputPath = FolderPath + "/Input" + std::to_string(i) + ".txt";
        std::ofstream Input(inputPath);
        // this loop can be optimized
        std::ifstream in(FilePath, std::ios::in);
        if (!in)
        {
            std::cout << "cannot open the file";
            return;
        }
        std::string format;
        while (in >> format)
        {
            char firstChar = format[0];

            std::regex e("([0-9]+)");
            std::sregex_iterator iter(format.begin(), format.end(), e);
            std::sregex_iterator end;
            if (iter == end)
            {
                // this must be char
                char letter = rand() % 26 + 65;
                if (rand() % 2)
                    letter += 32;
                Input << letter << " ";
                continue;
            }

            std::string str1 = ((std::string)((*iter)[0]));
            ++iter;
            std::string str2 = ((std::string)((*iter)[0]));
            int i1 = atoi(str1.c_str());
            int i2 = atoi(str2.c_str());
            int randInt = rand() % (i1 - i2 + 1) + i1;
            switch (firstChar)
            {
            case 'i':
                Input << randInt << " "; //暂定用空格分隔两个输入
                break;
            case 's':
            {
                int lenth = rand() % (i1 - i2 + 1) + i1;
                for (int i = 0; i < lenth; ++i)
                {
                    char letter = rand() % 26 + 65;
                    if (rand() % 2)
                        letter += 32;
                    Input << letter;
                }
                break;
            }
            default:
                std::cout << "Sth is wrong with the format!";
                return;
            }
            // std::cout << i1 << " " << i2 << "\n";

            /* std::regex reg("([0-9]+)");
            std::smatch result;
            std::regex_match(format, result, reg);
            if (result.empty())
            { // this must be char
                char letter = rand() % 26 + 65;
                if (rand() % 2)
                    letter += 32;
                Input << letter << " ";
                continue;
            }
            std::string str1 = ((std::string)result[0]);
            std::string str2 = ((std::string)result[1]);
            int i1 = atoi(str1.c_str());
            int i2 = atoi(str2.c_str());
            int randInt = rand() % (i1 - i2 + 1) + i1;
            switch (firstChar)
            {
            case 'i':
                Input << randInt << " "; //暂定用空格分隔两个输入
                break;
            case 's':
            {
                int lenth = rand() % (i1 - i2 + 1) + i1;
                for (int i = 0; i < lenth; ++i)
                {
                    char letter = rand() % 26 + 65;
                    if (rand() % 2)
                        letter += 32;
                    Input << letter;
                }
                break;
            }
            default:
                std::cerr << "Sth is wrong with the format!";
                return;
            }*/
        } // finish one random input, then change a row, begin another
        Input << "\n";
    }
}