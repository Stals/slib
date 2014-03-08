#pragma once

#include <string>
#include <sstream>
#include <vector>

class StringExtension{
public:
        template <class T>
        static std::string toString(const T& t){
                std::stringstream sstr;
                sstr << t;
                return sstr.str();
        }
    
    
    static void split(const std::string &s, char delim, std::vector<std::string> &v);
    static std::vector<std::string> split(const std::string &s, char delim);
    
    void toLower(std::string& str);
    std::string toLower(const std::string str);
};