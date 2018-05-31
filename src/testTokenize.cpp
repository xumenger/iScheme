#include <string>
#include<iostream>
#include <assert.h>
#include "Tokenize.hpp"

using namespace std;

void testTokenize(){
    StrVector v = Tokenize("(begin (def a 3) (* a a))");
    String str = "['(', 'begin', '(', 'def', 'a', '3', ')', '(', '*', 'a', 'a', ')', ')']";
    assert(str == PrettyPrint(v));
}

int main(){
    testTokenize();

    return 0;
}
