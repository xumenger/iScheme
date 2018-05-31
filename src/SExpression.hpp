#ifndef _ISCHEME_SEXPRESSION_HPP_
#define _ISCHEME_SEXPRESSION_HPP_

#include <string>
#include <vector>

class SExpression;

typedef std::string String;
typedef std::vector<SExpression *> ExprVector;

class SExpression{
    public:
        String Value;
        ExprVector Children;
        SExpression *Parent;

    public:
        SExpression(String &value, SExpression *parent){
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

#endif
