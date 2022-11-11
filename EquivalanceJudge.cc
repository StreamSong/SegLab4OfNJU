// the header can't be included repeated, need modify
#include <iostream>
#include <sys/types.h>
#include <dirent.h>
#include <fstream>

void RunOneFile(std::string FilePath, std::string FileName);

void EquivalanceJudge()
{
    std::string path = "/home/cs144/SegLab4/input";
    DIR *pDir;
    struct dirent *ptr;
    if (!(pDir = opendir(path.c_str()))) // open the "input" folder
    {
        std::cerr << "Can't open the input folder!";
        return;
    }
    while ((ptr = readdir(pDir)) != 0)
    {
        std::string pathNext = path + "/" + ptr->d_name;
        DIR *pDirNext = opendir(pathNext.c_str());
        struct dirent *ptrNext1, *ptrNext2;
        if (!(pDirNext = opendir(path.c_str()))) // open the next folder that conains files
        {
            std::cerr << "Can't open the input folder!";
            return;
        }
        while ((ptrNext1 = readdir(pDirNext)) != 0)
        { // get each file
            std::string Filename1 = ptrNext1->d_name;
            if (Filename1.find(".cpp") == std::string::npos)
                continue;
            while ((ptrNext2 = readdir(pDirNext)) != 0)
            {
                std::string Filename2 = ptrNext2->d_name;
                if (Filename2.find(".cpp") == std::string::npos)
                    continue;
                if (ptrNext1 != ptrNext2)
                {
                    std::string Path1 = pathNext + "/" + Filename1;
                    std::string Path2 = pathNext + "/" + Filename2;
                    bool if_eq = CompareTwoResult(Path1, Path2, Filename1, Filename2);
                    // write the compare result
                    std::string folderName = ptr->d_name;
                    std::string out_Filename1 = "input/" + folderName + "/" + Filename1;
                    std::string out_Filename2 = "input/" + folderName + "/" + Filename2;
                    WriteCsv(if_eq, out_Filename1, out_Filename2);
                }
            }
        }
    }
    closedir(pDir);
}

void WriteCsv(bool if_equal, std::string FileName1, std::string FileName2)
{
    std::ofstream p;
    if (if_equal)
    {
        p.open("equal.csv", std::ios::out); //打开文件路径,没有就创建一个
        p << FileName1
          << ","
          << FileName2
          << ","
          << "\n";
        p.close();
    }
    else
    {
        p.open("inequal.csv", std::ios::out); //打开文件路径,没有就创建一个
        p << FileName1
          << ","
          << FileName2
          << ","
          << "\n";
        p.close();
    }
}

bool CompareTwoResult(std::string FilePath1, std::string FilePath2, std::string FileName1, std::string FileName2)
{
    // what if run error? Remain to modify
    RunOneFile(FilePath1, FileName1);
    RunOneFile(FilePath2, FileName2);

    std::string ResultPath1 = FileName1 + "_output.txt";
    std::string ResultPath2 = FileName2 + "_output.txt";

    std::string content1, content2;
    char cache;
    freopen(ResultPath1.c_str(), "r", stdin); //打开文件a
    while (scanf("%c", &cache) != EOF)
        content1 += cache;                    //保存
    fclose(stdin);                            //关闭文件a
    freopen(ResultPath2.c_str(), "r", stdin); //打开文件b
    while (scanf("%c", &cache) != EOF)
        content2 += cache; //保存
    fclose(stdin);         //关闭文件b
    if (content1 == content2)
        return true;
    return false;
}