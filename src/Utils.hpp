#ifndef _ISCHEME_UTILS_HPP_
#define _ISCHEME_UTILS_HPP_

#include <string>
#include <vector>
#include <iostream>
#include <sstream>

typedef std::string String;
typedef std::vector<std::string> StrVector;

void Int2Str(const int _i, String &_s);

String &ReplaceAll(String &_str, const String &_old, const String &_new);

String &TrimString(String &_str, const String &_chars);

StrVector SplitString(const String &_str, const String &_separator);

#endif

