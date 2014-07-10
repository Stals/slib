#pragma once

#include <string>

#include "../thirdparty/pugi/pugixml.hpp"

// allows storing key value data in XML formatted file
// Note: call save() after changing values to change it on disk
class SettingsXML{
public:
    SettingsXML(const std::string& filename);
    ~SettingsXML();
    
    bool getBool(const std::string& key, bool def = false);
    int getInt(const std::string& key, int def = 0);
    std::string getString(const std::string& key, const std::string& def = std::string());
	float getFloat(const std::string& key, float def = 0);
    
    void setValue(const std::string& key, bool value);
    void setValue(const std::string& key, int value);
    void setValue(const std::string& key, const char* value);
	void setValue(const std::string& key, float value);
    void save();
    
private:
    pugi::xml_document doc;
    std::string filepath;
    
    pugi::xml_attribute getAttribute(const std::string& key);
    // Note: returns existing attribute if was already created
    pugi::xml_attribute createAttribure(const std::string& key);
};