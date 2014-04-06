#include "SettingsXML.h"
#include "FileUtils.h"
#include "../utils/StringExtension.h"

#define VALUE "Value"

SettingsXML::SettingsXML(const std::string& filepath)
{
    this->filepath = FileUtils::getFullPath(filepath);
    
    doc.load_file(this->filepath.c_str());
}

SettingsXML::~SettingsXML()
{
    save();
}

void SettingsXML::save()
{
    doc.save_file(filepath.c_str());
}

bool SettingsXML::getBool(const std::string& key, bool def)
{
    return getAttribute(key).as_bool(def);
}

bool SettingsXML::getInt(const std::string& key, int def)
{
    return getAttribute(key).as_int(def);
}

bool SettingsXML::getString(const std::string& key, const std::string& def)
{
    return getAttribute(key).as_string(def.c_str());
}


void SettingsXML::setValue(const std::string& key, bool value)
{
    pugi::xml_node node =  doc.child(key.c_str());//
    if(!node){
        node = doc.append_child(key.c_str());
    }
    node.append_attribute(VALUE) = value;
}

void SettingsXML::setValue(const std::string& key, int value)
{
    pugi::xml_node node =  doc.child(key.c_str());//
    if(!node){
        node = doc.append_child(key.c_str());
    }
    
    node.append_attribute(VALUE) = value;
}

void SettingsXML::setValue(const std::string& key, const char* value)
{
    pugi::xml_node node =  doc.child(key.c_str());//
    if(!node){
        node = doc.append_child(key.c_str());
    }
    node.append_attribute(VALUE) = value;
}

pugi::xml_attribute SettingsXML::getAttribute(const std::string& key)
{
    pugi::xml_node node = doc.child(key.c_str());
    return node.attribute(VALUE);
}
