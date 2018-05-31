#include <iostream>
#include <assert.h>
#include <string>
#include <vector>
#include "Utils.hpp"

using namespace std;

void testReplaceAll(){
    string str = "abc";
    assert("123" == ReplaceAll(str, "abc", "123"));
    str = "abc_22";
    assert("11_22" == ReplaceAll(str, "abc", "11"));
}

void testTrimString(){
    string str = "111abcdefg111";
    assert("abcdefg" == TrimString(str, "1"));
    str = "123abc123";
    assert("abc" == TrimString(str, "123"));
    str = "123";
    assert("" == TrimString(str, "123"));
    str = " ( * (+  1  3) ) ";
    assert("( * (+  1  3) )" == TrimString(str, " "));
}

void tetSplitString(){
    string str = " ( * (+  1  3) ) ";
    vector<string> v = SplitString(str, " \t\r\n");
    assert(v.size() == 6);
    assert(v[0] == "(");
    assert(v[2] == "(+");
}

int main()
{
    testReplaceAll();
    testTrimString();
    tetSplitString();
    return 0;
}
