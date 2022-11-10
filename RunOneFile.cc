#include <iostream>

void RunOneFile(std::string FilePath, std::string FileName)
{
    FILE *fp;
    // maybe we need to add some label to the output.txt
    std::string cmd = "gcc " + FilePath + "\n" + FileName + ".out <Input.txt>ouput.txt";
    fp = popen(cmd.c_str(), "r");
    if (fp == NULL)
    {
        std::cerr << "Sth is wrong while opening the source file!\n";
    }
    pclose(fp);
    return;
}