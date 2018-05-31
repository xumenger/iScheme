#ifndef _ISCHEME_TOKENIZE_HPP_
#define _ISCHEME_TOKENIZE_HPP_

#include <string>
#include <vector>
#include "Utils.hpp"

typedef std::string String;
typedef std::vector<std::string> StrVector;

StrVector Tokenize(String text);

String PrettyPrint(StrVector &lexes);

#endif
