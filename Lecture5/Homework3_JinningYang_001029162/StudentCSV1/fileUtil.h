#ifndef FILEUTIL_H_INCLUDED
#define FILEUTIL_H_INCLUDED

#include <fstream>
#include <string>
#include <vector>
#include <iostream>
#include <utility>
#include <string>

class FileUtil {
public:
    FileUtil(std::string path);
    ~FileUtil();
    std::string nextLine();

private:
    std::ifstream ifs;
};


#endif // FILEUTIL_H_INCLUDED
