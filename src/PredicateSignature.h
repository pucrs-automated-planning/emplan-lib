// PredicateSignature.h: interface for the PredicateSignature class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PREDICATESIGNATURE_H__54B7622D_F986_4EAC_979B_42489E092C34__INCLUDED_)
#define AFX_PREDICATESIGNATURE_H__54B7622D_F986_4EAC_979B_42489E092C34__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Signature.h"
#include "Predicate.h"

#include <sstream>
using std::ostringstream;

class PredicateSignature : public Signature  
{
protected:
	Predicate *pSignature;

	Predicate *makeSignaturePredicate(string sName, int iArity);
public:
	PredicateSignature();
	PredicateSignature(Predicate *p);
	virtual ~PredicateSignature();

	Predicate *getPredicate();
	virtual string toString();

	static string getSignature(Predicate *p);

	PredicateSignature &operator=(PredicateSignature &pRight);
};

#endif // !defined(AFX_PREDICATESIGNATURE_H__54B7622D_F986_4EAC_979B_42489E092C34__INCLUDED_)
