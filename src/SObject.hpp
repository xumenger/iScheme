#ifndef _ISCHEME_SOBJECT_HPP_
#define _ISCHEME_SOBJECT_HPP_

#include <string>
#include <vector>

#include "Utils.hpp"
#include "SExpression.hpp"

class SScope;
class SObject;

typedef std::string String;
typedef std::vector<SObject *> ObjectVector;
typedef std::vector<std::string> StrVector;

/********
 * 类型系统
 ********/

class SObject{
    public:
        SObject(){
        
        }
        virtual ~SObject(){
        
        }
    public:
        virtual String ToString() = 0;
};


//数值类型
class SNumber: public SObject{
    public:
        int Value;
    
    public:
        SNumber(int value){
            this->Value = value;
        }

        String ToString(){
            String s;
            Int2Str(this->Value, s);
            return s;
        }
};


//布尔类型
class SBool: public SObject{
    public:
        SBool(){
        
        }

        String ToString(){
            return "";    
        }
};


//列表类型
class SList: public SObject{
    public:
        ObjectVector Values;
    
    public:
        SList(ObjectVector &values){
            this->Values = values;
        }

        String ToString(){
            String str;
            str = "(list ";
            int i = 0;
            for(i = 0; i < Values.size() - 1; i++){
                str = str + Values[i]->ToString() + " ";
            }
            if(Values.size() >= 1){
                str = str + Values[Values.size()]->ToString();
            }
            str = str + ")";
            return str;
        }
};


//函数类型
class SFunction: public SObject{
    public:
        SExpression *Body;     //函数体
        StrVector Parameters;  //参数列表
        SScope *Scope;         //函数拥有自己的作用域
    public:
        SFunction(SExpression *body, StrVector &parameters, SScope *scope){
            this->Body = body;
            this->Parameters = parameters;
            this->Scope = scope;
        }

        String ToString();

        ObjectVector ComputeFilledParameters();

        SObject *Evaluate(){
            ObjectVector v = ComputeFilledParameters();
            //如果不是所有的参数都有对应的值，那么部分求值
            if(v.size() < Parameters.size()){
                return this;
            }
            //如果所有参数都有值，那么直接根据函数体得到结果
            else{
                return this->Body->Evaluate(this->Scope);
            }
        }
};

#endif
