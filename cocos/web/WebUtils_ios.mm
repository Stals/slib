#include "WebUtils.h"
#ifdef __APPLE__

void WebUtils::openURL(const std::string& link)
{
    NSURL * url = [NSURL URLWithString: [NSString stringWithUTF8String:link.c_str()]];
    [[UIApplication sharedApplication] openURL: url];
}

#endif