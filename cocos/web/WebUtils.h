#pragma once

#include <string>

// TODO implementations for other platforms
// http://2lx.ru/2012/05/otkrytie-brauzera-iz-igry-na-cocos2d-x/
// https://github.com/cocos2d/cocos2d-x/pull/1940/commits
// mb add cocos2dx to this repo if will need to change java code

class WebUtils{
public:
    // WebUtils::openURL("http://www.google.com");
    static void openURL(const std::string& url);
    
private:
    WebUtils();
};