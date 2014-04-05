#include "FileUtils.h"

#ifdef __APPLE__

std::string FileUtils::getFullPath(const std::string& filename)
{
    NSArray *paths = NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES);
	NSString *documentsDirectory = [paths objectAtIndex:0];
    
    std::string path = [documentsDirectory UTF8String];
	path.append("/");
    path.append(filename.c_str());
    
	return path;
}

#endif