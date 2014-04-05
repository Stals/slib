#pragma once

#include <string>

class FileUtils{
public:
    static std::string getFullPath(const std::string& filename);
    
private:
    FileUtils();
};