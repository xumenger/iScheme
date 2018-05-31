#ifndef _ISCHEME_SSCOPE_HPP_
#define _ISCHEME_SSCOPE_HPP_

#include <string>
#include <map>
#include <vector>

#include "SObject.hpp"

typedef std::string String;
typedef std::map<std::string, SObject *> ObjectMap;
typedef std::map<std::string, SObject *>::iterator ObjectMapIt;
typedef std::pair<std::string, SObject *> ObjectPair;

class SExpression;
typedef std::vector<SExpression *> ExprVector;

typedef SObject *(*BuiltInFuncion)(ExprVector &, SScope *);

class SScope{
    public:
        SScope *Parent;
        ObjectMap VariableMap;

    public:
        SScope(SScope *parent){
            this->Parent = parent;
        }

        SObject *Find(String name){
            SScope *current = this;
            while(current != NULL){
                ObjectMapIt it = current->VariableMap.find(name);
                if(it != VariableMap.end()){
                    return it->second;
                }
                current = current->Parent;
            }
            return NULL;
        }

        SObject *Define(String name, SObject *value){
            this->VariableMap.insert(ObjectPair(name, value));
            return value;
        }

        SObject *FindInTop(String name){
            ObjectMapIt it = this->VariableMap.find(name);
            if(it != VariableMap.end()){
                return it->second;
            }
            return NULL;
        }
};

#endif

