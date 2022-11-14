#include <iostream>
#include <string>

int RunOneFile(std::string FilePath, std::string FileName, int InputFileIndex)
{
    FILE *fp;
    for (int i = 0; i < 4; ++i)
        FileName.pop_back();

    std::string FolderPath = FilePath;
    while (FolderPath.back() != '/')
    {
        FolderPath.pop_back();
    }

    // std::cout << FileName << "\n";

    // maybe we need to add some label to the output.txt
    // std::string cmd = "gcc " + FilePath + " " + FileName + ".out <Input.txt>" + FileName + "_ouput.txt";
    // std::string cmd = "gcc " + FilePath + " -Istdc++ -g" + " -o " + FileName + "\n" + FileName + ".out <" + FolderPath + "Input.txt>" + FileName + "_ouput.txt";
    std::string cmd = "g++ " + FilePath + " -o " + FolderPath + FileName + "\n" + FolderPath + FileName + " <" + FolderPath + "Input" + std::to_string(InputFileIndex) + ".txt>" + FolderPath + FileName + "_output.txt" + " 2>&1";

    // std::cout << cmd << "\n";

    fp = popen(cmd.c_str(), "r");
    if (fp == NULL)
    {
        std::cout << "Sth is wrong while opening the source file!\n";
    }
    int ret = pclose(fp);

    if (WIFEXITED(ret) != 1) // Sth is wrong.
    {
        return 1;
    }

    return 0;
}