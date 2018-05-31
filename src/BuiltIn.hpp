#ifndef _ISCHEME_BUILTIN_HPP_
#define _ISCHEME_BUILTIN_HPP_

#include <string>
#include <vector>

class SExpression;
class SScope;
class SObject;

typedef std::string String;
typedef std::vector<SExpression *> ExprVector;

//typedef SObject *(*BuiltInFuncion)(ExprVector &, SScope *);

SObject *AddMethod(ExprVector &ev, SScope *scope);
SObject *SubMethod(ExprVector &ev, SScope *scope);
SObject *MulMethod(ExprVector &ev, SScope *scope);
SObject *DivMethod(ExprVector &ev, SScope *scope);
SObject *ModMethod(ExprVector &ev, SScope *scope);

SObject *AndMethod(ExprVector &ev, SScope *scope);
SObject *OrMethod(ExprVector &ev, SScope *scope);
SObject *NotMethod(ExprVector &ev, SScope *scope);

SObject *EqMethod(ExprVector &ev, SScope *scope);
SObject *LtMethod(ExprVector &ev, SScope *scope);
SObject *GtMethod(ExprVector &ev, SScope *scope);
SObject *LeMethod(ExprVector &ev, SScope *scope);
SObject *GeMethod(ExprVector &ev, SScope *scope);

#endif
