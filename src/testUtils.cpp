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

int main()
{
    testReplaceAll();
    return 0;
}
