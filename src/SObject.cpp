#include <string>
#include <vector>

#include "SObject.hpp"
#include "SScope.hpp"

typedef std::string String;
typedef std::vector<SObject *> ObjectVector;

String SFunction::ToString(){
    String str = "(func (";
    int i = 0;
    for(i = 0; i < this->Parameters.size(); i++){
        SObject *value = NULL;
        value = this->Scope->FindInTop(Parameters[i]);
        if(NULL != value){
            str = str + Parameters[i] + ":" + value->ToString() + " ";
            value = NULL;
        }
        else{
            str = Parameters[i] + " ";
        }
    }
    if(this->Parameters.size() >= 1){
        SObject *value = NULL;
        value = this->Scope->FindInTop(Parameters[Parameters.size() - 1]);
        if(NULL != value){
            str = str + Parameters[i] + ":" + value->ToString();
            value = NULL;
        }
        else{
            str = Parameters[i];
        }
    }
    str = str + ")" + this->Body->ToString() + ")";
    return str;
}

ObjectVector SFunction::ComputeFilledParameters(){
    ObjectVector temp;
    int i = 0;
    for(i = 0; i < Parameters.size(); i++){
        SObject *value = NULL;
        value = this->Scope->FindInTop(Parameters[i]);
        if(NULL != value){
            temp.push_back(value);
            value = NULL;
        }
    }
    return temp;
}
