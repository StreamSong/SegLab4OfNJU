#include <vector>
#include "SourceFile.hh"

class User
{
private:
    /* data */
    std::string UserID;
    std::string UserName;

public:
    // int FileNum{0};
    // std::vector<SourceFile> InputFiles;

    User(/* args */);
    ~User();
    void GenerateInput(std::string FilePath, std::string FolderPath);
};