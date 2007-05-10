// PredicateInstance.h: interface for the PredicateInstance class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PREDICATEINSTANCE_H__A89BC83E_C458_4503_A44D_45BB31F1F5DE__INCLUDED_)
#define AFX_PREDICATEINSTANCE_H__A89BC83E_C458_4503_A44D_45BB31F1F5DE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <string>
using std::string;

#include <vector>
using std::vector;

#include "TermInstance.h"
#include "Predicate.h"

class PredicateInstance  
{
protected:
	string sName;//Holds the name of the Predicate
	string sKey;//Holds the unique id key for the predicate instance
	string sPredicate;//Holds the Non-negated name of the predicate instance
	bool bNot;
	TermInstanceVector tivTerms;

	string makePredicate();
public:
	PredicateInstance();
	PredicateInstance(string sName, TermInstanceVector &tivTerms, bool bNot=false);
	virtual ~PredicateInstance();

	bool operator==(PredicateInstance &piRight);
	PredicateInstance &operator=(PredicateInstance &piRight);
	bool isMutex(PredicateInstance *pi);

	string getKey();
	string toString();

	static string getKey(Predicate *p);
};

typedef vector<PredicateInstance *> PredicateInstanceVector;

#endif // !defined(AFX_PREDICATEINSTANCE_H__A89BC83E_C458_4503_A44D_45BB31F1F5DE__INCLUDED_)
