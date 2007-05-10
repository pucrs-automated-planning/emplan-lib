// OperatorFactory.h: interface for the OperatorFactory class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_OPERATORFACTORY_H__F969A0C6_1D37_41AA_9E7C_1DDE76336697__INCLUDED_)
#define AFX_OPERATORFACTORY_H__F969A0C6_1D37_41AA_9E7C_1DDE76336697__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <algorithm>
using std::find;

#include "Predicate.h"
#include "Term.h"
#include "Operator.h"

class OperatorFactory  
{
public:
	static Operator * newOperator(const string &sOperator, TermVector *dnvParams, PredicateVector *pvPreconds, PredicateVector *pvEffects);
	static bool checkOperator(const string &sOperator, TermVector *dnvParams, PredicateVector *pvPreconds, PredicateVector *pvEffects);
	OperatorFactory();
	virtual ~OperatorFactory();

};

#endif // !defined(AFX_OPERATORFACTORY_H__F969A0C6_1D37_41AA_9E7C_1DDE76336697__INCLUDED_)
