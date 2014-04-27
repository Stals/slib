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

int SettingsXML::getInt(const std::string& key, int def)
{
    return getAttribute(key).as_int(def);
}

std::string SettingsXML::getString(const std::string& key, const std::string& def)
{
    return getAttribute(key).as_string(def.c_str());
}

float SettingsXML::getFloat(const std::string& key, float def)
{
	return getAttribute(key).as_float(def);
}

void SettingsXML::setValue(const std::string& key, bool value)
{
    createAttribure(key) = value;
}

void SettingsXML::setValue(const std::string& key, int value)
{
    createAttribure(key) = value;
}

void SettingsXML::setValue(const std::string& key, const char* value)
{
    createAttribure(key) = value;
}

void SettingsXML::setValue(const std::string& key, float value)
{
	createAttribure(key) = value;
}


pugi::xml_attribute SettingsXML::getAttribute(const std::string& key)
{
    pugi::xml_node node = doc.child(key.c_str());
    return node.attribute(VALUE);
}

pugi::xml_attribute SettingsXML::createAttribure(const std::string& key)
{
    pugi::xml_node node =  doc.child(key.c_str());
    if(!node){
        node = doc.append_child(key.c_str());
    }
    pugi::xml_attribute attr = node.attribute(VALUE);
    if(!attr){
        attr = node.append_attribute(VALUE);
    }
    return attr;
}

