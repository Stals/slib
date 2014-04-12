#include "FileUtils.h"

#ifndef __APPLE__

#include "cocos2d.h"

std::string FileUtils::getFullPath(const std::string& filename)
{
	string path("");
    
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	// In android, every programe has a director under /data/data.
	// The path is /data/data/ + start activity package name.
	// You can save application specific data here.
	path.append("/data/data/org.cocos2dx.application/");
#endif
    
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
	// You can save file in anywhere if you have the permision.
	path.append("C:/");
#endif
    
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WOPHONE)
	path = cocos2d::CCApplication::sharedApplication().getAppDataPath();
    
#ifdef _TRANZDA_VM_
	// If runs on WoPhone simulator, you should insert "D:/Work7" at the
	// begin. We will fix the bug in no far future.
	path = "D:/Work7" + path;
#endif
    
#endif
    
    path.append(filename);
    
	return path;
}

std::string FileUtils::getResoursePath(const std::string& filename){
    return cocos2d::CCFileUtils::sharedFileUtils()->fullPathForFilename(filename.c_str());
}

#endif