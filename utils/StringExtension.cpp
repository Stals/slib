#include "StringExtension.h"

#include <strstream>

void StringExtension::split(const std::string &s, char delim, std::vector<std::string> &elems) {
    std::stringstream ss(s);
    std::string item;
    while(std::getline(ss, item, delim)) {
        elems.push_back(item);
    }
}

std::vector<std::string> StringExtension::split(const std::string &s, char delim) {
    std::vector<std::string> elems;
    split(s, delim, elems);
    return elems;
}

void StringExtension::toLower(std::string &str){
    for(size_t i = 0; i < str.length(); ++i){
        str[i] = tolower( str[i] );
    }
}


std::string StringExtension::toLower(const std::string str)
{
    StringExtension::toLower(str);
    return str;
}