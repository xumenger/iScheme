#include <string>

#include "SObject.hpp"
#include "SScope.hpp"

typedef std::string String;

String SFunction::ToString(){
    String str = "(func (";
    int i = 0;
    for(i = 0; i < this->Parameters.size(); i++){
        SObject *value = NULL;
        value = this->Scope->FindInTop(Parameters[i]);
        if(NULL != value){
            str = str + Parameters[i] + ":" + value->ToString() + " ";
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
        }
        else{
            str = Parameters[i];
        }
    }
    str = str + ")" + this->Body->ToString() + ")";
    return str;
}