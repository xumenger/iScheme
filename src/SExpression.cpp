#include "SExpression.hpp"
#include "SObject.hpp"
#include "SScope.hpp"

SObject *SExpression::Evaluate(SScope *scope){
    if(this->Children.size() == 0){
        int number;
        Str2Int(this->Value, number, 0);
        return new SNumber(number);
    }
    // 递归求表达式内的所有子表达式
    else{
        SExpression *first = this->Children[0];
        BuiltInFunctionMapIt it;
        it = SScope::BuiltInFunctions.find(first->Value);
        if(it != SScope::BuiltInFunctions.end()){
            return it->second(this->Children, scope);
        }
    }
    return NULL;
}

SExpression *ParseAsIScheme(String code){
    SExpression *program = new SExpression("", NULL);
    SExpression *current = program;
    StrVector v = Tokenize(code);
    int i = 0;
    for(i = 0; i < v.size(); i++){
        // 碰到左括号，创建一个新的节点为当前节点，然后重设当前节点
        if(v[i] == "("){
            SExpression *newNode = new SExpression("(", current);
            current->Children.push_back(newNode);
            current = newNode;
        }
        // 碰到右括号，回退到当前节点的父节点
        else if(v[i] == ")"){
            current = current->Parent;
        }
        // 否则为当前词素创建节点，并添加到当前节点的Children中
        else{
            SExpression *newNode = new SExpression(v[i], current);
            current->Children.push_back(newNode);
        }
    }
    return program->Children[0];
}
