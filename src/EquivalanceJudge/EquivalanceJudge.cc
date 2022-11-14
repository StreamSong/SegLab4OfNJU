// the header can't be included repeated, need modify
#include <iostream>
#include <string>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>
#include <fstream>
#include <set>

int RunOneFile(std::string FilePath, std::string FileName, int InputFileIndex);

void WriteCsv(bool if_equal, std::string FileName1, std::string FileName2)
{
    std::ofstream p;
    if (if_equal)
    {
        p.open("equal.csv", std::ios::out | std::ios::app); //打开文件路径,没有就创建一个
        p << FileName1
          << ","
          << FileName2
          << ","
          << "\n";
        p.close();
    }
    else
    {
        p.open("inequal.csv", std::ios::out | std::ios::app); //打开文件路径,没有就创建一个
        p << FileName1
          << ","
          << FileName2
          << ","
          << "\n";
        p.close();
    }
}

int CompareTwoResult(std::string FilePath1, std::string FilePath2, std::string FileName1, std::string FileName2)
{
    // what if run error? Remain to modify
    for (int i = 0; i < 5; ++i)
    {
        int i1 = RunOneFile(FilePath1, FileName1, i);
        int i2 = RunOneFile(FilePath2, FileName2, i);

        if (i1 == 1 || i2 == 1)
            return -1;

        // move ".cpp" from filename
        std::string FileName1_noExtension = FileName1;
        std::string FileName2_noExtension = FileName2;
        for (int i = 0; i < 4; ++i)
        {
            FileName1_noExtension.pop_back();
            FileName2_noExtension.pop_back();
        }
        std::string FolderPath = FilePath1;
        while (FolderPath.back() != '/')
        {
            FolderPath.pop_back();
        }
        std::string ResultPath1 = FolderPath + FileName1_noExtension + "_output.txt";
        std::string ResultPath2 = FolderPath + FileName2_noExtension + "_output.txt";

        // std::cout << ResultPath1 << "\n"
        //           << ResultPath2 << "\n";

        std::ifstream resultFile1(ResultPath1), resultFile2(ResultPath2);

        if (!resultFile1.is_open() || !resultFile2.is_open())
        {
            std::cout << "Can't read the output txt!"
                      << "\n";
            return -1;
        }
        std::string content1, content2;
        getline(resultFile1, content1);
        getline(resultFile2, content2);
        resultFile1.close();
        resultFile2.close();

        // std::cout << content1 << "\n"
        //           << content2 << "\n";

        if (content1 != content2)
            return 0; // false
    }
    return 1; // true
}

void EquivalanceJudge()
{
    int test = 0; // used for debug

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
        if (strcmp(ptr->d_name, ".") == 0 || strcmp(ptr->d_name, "..") == 0)
            continue;

        std::string pathNext = path + "/" + ptr->d_name;

        // std::cout << pathNext << "\n";

        std::set<std::string> FilesHaveBeenCmped;

        DIR *pDirNext1 = opendir(pathNext.c_str());

        struct dirent *ptrNext1;
        if (pDirNext1 == NULL) // open the next folder that conains files
        {
            std::cout << "Can't open the input folder!";
            return;
        }
        while ((ptrNext1 = readdir(pDirNext1)) != NULL)
        {
            FilesHaveBeenCmped.insert(ptrNext1->d_name);
            // get each file
            if (strcmp(ptrNext1->d_name, ".") == 0 || strcmp(ptrNext1->d_name, "..") == 0)
                continue;
            std::string Filename1 = ptrNext1->d_name;
            if (Filename1.find(".cpp") == std::string::npos)
                continue;
            DIR *pDirNext2 = opendir(pathNext.c_str());
            struct dirent *ptrNext2;
            while ((ptrNext2 = readdir(pDirNext2)) != 0)
            {
                if (strcmp(ptrNext2->d_name, ".") == 0 || strcmp(ptrNext2->d_name, "..") == 0)
                    continue;
                std::string Filename2 = ptrNext2->d_name;
                if (Filename2.find(".cpp") == std::string::npos)
                    continue;
                if (FilesHaveBeenCmped.find(Filename2) == FilesHaveBeenCmped.end())
                {
                    std::string Path1 = pathNext + "/" + Filename1;
                    std::string Path2 = pathNext + "/" + Filename2;
                    int if_eq = CompareTwoResult(Path1, Path2, Filename1, Filename2);
                    if (if_eq == -1)
                        return; // need to be change to continue
                    // write the compare result
                    std::string folderName = ptr->d_name;
                    std::string out_Filename1 = "input/" + folderName + "/" + Filename1;
                    std::string out_Filename2 = "input/" + folderName + "/" + Filename2;

                    // std::cout << out_Filename1 << "\n"
                    //           << out_Filename2 << "\n";

                    WriteCsv(if_eq, out_Filename1, out_Filename2);

                    test++;
                }
            }
        }
    }
    std::cout << "test:" << test << "\n";
    closedir(pDir);
}
