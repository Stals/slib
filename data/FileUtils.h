#pragma once

#include <string>

class FileUtils{
public:
    // http://www.cocos2d-x.org/wiki/How_to_read_and_write_file_on_different_platforms
    static std::string getFullPath(const std::string& filename);
    
private:
    FileUtils();
};