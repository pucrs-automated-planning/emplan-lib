// CausalLink.h: interface for the CausalLink class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CAUSALLINK_H__F5C249CB_9B1B_4EE6_90D3_F6DF043309B0__INCLUDED_)
#define AFX_CAUSALLINK_H__F5C249CB_9B1B_4EE6_90D3_F6DF043309B0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <vector>
using std::vector;

#include <string>
using std::string;

#include "Debug.h"

#include "Operator.h"
#include "Predicate.h"

class CausalLink  
{
protected:
	Operator *oFulfills;
	Predicate *pCauses;
public:
	CausalLink();
	CausalLink(Operator *oFulfills, Predicate *pCauses);
	virtual ~CausalLink();

	bool fulfills(Operator *o);
	bool fulfilled(Predicate *p);

	CausalLink &operator=(CausalLink &clRight);
	string toString();
};

typedef vector<CausalLink> CausalLinkVector;

#endif // !defined(AFX_CAUSALLINK_H__F5C249CB_9B1B_4EE6_90D3_F6DF043309B0__INCLUDED_)
