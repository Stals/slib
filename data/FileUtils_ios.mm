#include "FileUtils.h"

#ifdef __APPLE__

#include "../utils/StringExtension.h"
#include "cocos2d.h"

std::string FileUtils::getFullPath(const std::string& filename)
{
    NSArray *paths = NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES);
	NSString *documentsDirectory = [paths objectAtIndex:0];
    
    std::string path = [documentsDirectory UTF8String];
	path.append("/");
    path.append(filename.c_str());
    
	return path;
}

std::string FileUtils::getResoursePath(const std::string& filename)
{
    return cocos2d::CCFileUtils::sharedFileUtils()->fullPathForFilename(filename.c_str());
}

#endif