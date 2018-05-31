#ifndef _ISCHEME_UTILS_HPP_
#define _ISCHEME_UTILS_HPP_

#include <string>

typedef std::string String;

String &ReplaceAll(String &str, const String &_old, const String &_new){
    while(true){
        String::size_type pos(0);
        if((pos = str.find(_old)) != String::npos){
            str.replace(pos, _old.length(), _new);
        }
        else{
            break;
        }
    }
    return str;
}

#endif
