#include <iostream>
#include <assert.h>
#include <string>
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
}

int main()
{
    testReplaceAll();
    testTrimString();
    return 0;
}
