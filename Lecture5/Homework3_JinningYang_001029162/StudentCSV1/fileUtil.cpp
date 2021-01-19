#include "fileUtil.h"
#include <string>
#include <cassert>
using namespace std;

FileUtil::FileUtil(std::string path) : ifs(path) {}

FileUtil::~FileUtil() {
    ifs.close();
}

string FileUtil::nextLine() {
    string s;
    if (!getline(ifs, s)) {
        return s;
    }
}
