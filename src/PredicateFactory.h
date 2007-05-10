// PredicateFactory.h: interface for the PredicateFactory class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PREDICATEFACTORY_H__5CCB3DEA_36FA_4572_B118_7FBB83E3A4EE__INCLUDED_)
#define AFX_PREDICATEFACTORY_H__5CCB3DEA_36FA_4572_B118_7FBB83E3A4EE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Predicate.h"
#include "Term.h"

class PredicateFactory  
{
public:
	static Predicate * newPredicate(const string &s, bool bNot=false);
	static Predicate * newPredicate(const string &s, TermVector *dnvTerms, bool bNot=false);
	static bool isFullyInstantiated(PredicateVector *pvPredicates);
	PredicateFactory();
	virtual ~PredicateFactory();

};

#endif // !defined(AFX_PREDICATEFACTORY_H__5CCB3DEA_36FA_4572_B118_7FBB83E3A4EE__INCLUDED_)
