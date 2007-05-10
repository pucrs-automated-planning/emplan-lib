// OperatorInstance.h: interface for the OperatorInstance class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_OPERATORINSTANCE_H__2A19C883_7D57_4D53_8E87_93BFDF2F3AA0__INCLUDED_)
#define AFX_OPERATORINSTANCE_H__2A19C883_7D57_4D53_8E87_93BFDF2F3AA0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <string>
using std::string;

#include <vector>
using std::vector;

#include "Operator.h"
#include "TermInstance.h"
#include "PredicateInstance.h"

class OperatorInstance  
{
protected:
	bool bNoop;
	string sName;
	string sKey;
	
	TermInstanceVector tivParameters;
	PredicateInstanceVector pivPreconditions;
	PredicateInstanceVector pivEffects;

	string makeKey();
public:
	OperatorInstance();
	OperatorInstance(string sName, 
					TermInstanceVector &tivParameters, 
					PredicateInstanceVector &pivPreconditions, 
					PredicateInstanceVector &pivEffects,
					bool bNoop=false);

	virtual ~OperatorInstance();
	
	bool operator==(OperatorInstance &oiRight);
	OperatorInstance & operator=(OperatorInstance &oiRight);
	bool isMutex(OperatorInstance *oi);

	PredicateInstanceVector getPreconditions();
	PredicateInstanceVector getEffects();

	bool fulfills(PredicateInstance *piEffect);
	bool requires(PredicateInstance *piPrecondition);
	bool requiresNothing();
	bool selfConsistent();

	bool isNoop();

	string getKey();
	string toString();

	static string getKey(Operator *o);
};

typedef vector<OperatorInstance *> OperatorInstanceVector;

#endif // !defined(AFX_OPERATORINSTANCE_H__2A19C883_7D57_4D53_8E87_93BFDF2F3AA0__INCLUDED_)
