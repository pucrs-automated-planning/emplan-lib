#if !defined(YYSTYPE_H)
#define YYSTYPE_H

#include "Predicate.h"
#include "Term.h"
#include "Operator.h"
#include "Debug.h"


typedef struct yystype{

	int iFlag;
	string symbol;
	Predicate *predicate;
	PredicateVector *pvPredicates;
	Operator *oper;
	OperatorVector *ovOpers;
	Term *dn;
	TermVector *dnv;
}yyvar;


#endif