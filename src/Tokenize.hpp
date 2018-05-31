#ifndef _ISCHEME_TOKENIZE_HPP_
#define _ISCHEME_TOKENIZE_HPP_

#include <string>
#include <vector>
#include "Utils.hpp"

typedef std::string String;
typedef std::vector<std::string> StrVector;

StrVector Tokenize(String text){
    text = ReplaceAll(text, "(", "( ");
    text = ReplaceAll(text, ")", " )");
    StrVector v = SplitString(text, " \t\r\n");
    return v;
}


String PrettyPrint(StrVector &lexes){
    String str = "[";
    int i = 0;
    for(i = 0; i < lexes.size() - 1; i++){
        str = str + "'" + lexes[i] + "', ";
    }
    if(lexes.size() >= 1){
        str = str + "'" + lexes[lexes.size() - 1];
    }
    str = str + "']";
    return str;
}

#endif
