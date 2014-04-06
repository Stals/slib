#pragma once

#include <string>

#include "../thirdparty/pugi/pugixml.hpp"

// allows storing key value data in XML formatted file

class SettingsXML{
public:
    SettingsXML(const std::string& filename);
    ~SettingsXML();
    
    bool getBool(const std::string& key, bool def = false);
    bool getInt(const std::string& key, int def = 0);
    bool getString(const std::string& key, const std::string& def = std::string());
    
    void setValue(const std::string& key, bool value);
    void setValue(const std::string& key, int value);
    void setValue(const std::string& key, const char* value);
    
    void save();
    
private:
    pugi::xml_document doc;
    std::string filepath;
    
    pugi::xml_attribute getAttribute(const std::string& key);
    // Note: returns existing attribute if was already created
    pugi::xml_attribute createAttribure(const std::string& key);
};