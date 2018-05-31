#include "Utils.hpp"

void Int2Str(const int _i, String &_s){
    std::stringstream stream;
    stream << _i;
    _s = stream.str();
}

void Str2Int(const std::string &_s, int &_i, int dft){
    _i = dft;
    std::stringstream stream(_s);
    stream >> _i;
}

/*******************************************************************************
* Function   : ReplaceAll
* Description: 用_new替换_str中所有的_old子串
* Input      :
    * _str: 要处理的字符串
    * _old: 老的子串
    * _new: 新的子串
* Output     :
* Return     : _str替换子串后的结果
* Others     :
*******************************************************************************/
String &ReplaceAll(String &_str, const String &_old, const String &_new){
    //std::cout << _str << std::endl;
    //std::cout << _old << std::endl;
    //std::cout << _new << std::endl;
    String::size_type pos(0);
    while(true){
        if((pos = _str.find(_old, pos)) != String::npos){
            _str.replace(pos, _old.length(), _new);
            pos = pos + _new.length();
        }
        else{
            break;
        }
    }
    //std::cout << _str << std::endl;
    return _str;
}


/*******************************************************************************
* Function   : TrimString
* Description: 把字符串开头、末尾的_chars中的字符去除
* Input      :
    * _str: 
    * _chars: 
* Output     :
* Return     :
* Others     : 边界情况的考虑？
*******************************************************************************/
String &TrimString(String &_str, const String &_chars){
    int i(0);
    String::size_type begin(0), end(0);
    bool flag = false;
    for(i = 0; i < _str.size(); i++){
        String::size_type j(0);
        for(j = 0; j < _chars.size(); j++){
            if(_str[i] == _chars[j]){
                flag = true;
                break;
            }
        }
        if(flag == false){
            break;
        }
        flag = false;
    }
    begin = i;
    if(begin >= _str.size()){
        _str = "";
        return _str;
    }

    flag = false;
    for(i = _str.size()-1; i >= 0; i--){
        String::size_type j(0);
        for(j = 0; j < _chars.size(); j++){
            if(_str[i] == _chars[j]){
                flag = true;
                break;
            }
            end = i;
        }
        if(flag == false){
            break;
        }
        flag = false;
    }
    if(end < begin){
        _str = "";
        return _str;
    }

    _str = _str.substr(begin, end - begin + 1);
    return _str;
}


/*******************************************************************************
* Function   : SplitString
* Description: 按照分隔符将字符串分割为多个子串
* Input      :
    * _str: 要处理的字符串
    * _separator: 所有的分割字符
* Output     :
* Return     : 分割得到的子串放到Vector中返回
* Others     : 时间复杂度是O(N * M)，N是字符串长度，N是分隔符字符串长度
               是不是有更好的算法
*******************************************************************************/
StrVector SplitString(const String &_str, const String &_separator){
    String new_str = _str;
    new_str = TrimString(new_str, _separator);
    StrVector result;
    String::size_type i(0);
    String temp("");
    bool flag = false;
    for(i = 0; i < new_str.size(); i++){
        String::size_type j(0);
        for(j = 0; j < _separator.size(); j++){
            if (new_str[i] == _separator[j]){
                if("" != temp){
                    result.push_back(temp);
                    temp = "";
                }
                flag = true;
                break;
            }
        }
        if(not flag){
            temp += new_str[i];
        }
        flag = false;
    }
    if(temp != ""){
        result.push_back(temp);
    }

    return result;
}
