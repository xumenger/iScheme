#ifndef _ISCHEME_SEXPRESSION_HPP_
#define _ISCHEME_SEXPRESSION_HPP_

#include <string>
#include <vector>

#include "Tokenize.hpp"

class SExpression;

typedef std::string String;
typedef std::vector<SExpression *> ExprVector;
typedef std::vector<std::string> StrVector;

class SExpression{
    public:
        String Value;
        ExprVector Children;
        SExpression *Parent;

    public:
        SExpression(const String &value, SExpression *parent){
            this->Value = value;
            this->Parent = parent;
        }

        String ToString(){
            if(this->Value == "("){
                String str = "(";
                int i = 0;
                for(i = 0; i < Children.size() - 1; i++){
                    str = str + Children[i]->ToString() + " ";
                }
                if(Children.size() >= 1){
                    str = str + Children[Children.size()]->ToString();
                }
                str = str + ")";
                return str;
            }
            else{
                return this->Value;
            }
        }
};

////////////////////////////////////////
//构建抽象语法树
SExpression *ParseAsIScheme(String code){
    SExpression *program = new SExpression("", NULL);
    SExpression *current = program;
    StrVector v = Tokenize(code);
    int i = 0;
    for(i = 0; i < v.size(); i++){
        if(v[i] == "("){
            SExpression *newNode = new SExpression("(", current);
            current->Children.push_back(newNode);
            current = newNode;
        }
        else if(v[i] == ")"){
            current = current->Parent;
        }
        else{
            SExpression *newNode = new SExpression(v[i], current);
            current->Children.push_back(newNode);
        }
    }
    return program->Children[0];
}

#endif
