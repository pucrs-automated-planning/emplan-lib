// Plan.h: interface for the Plan class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PLAN_H__D00E23DC_49FB_487B_AB21_886A1BDB9C36__INCLUDED_)
#define AFX_PLAN_H__D00E23DC_49FB_487B_AB21_886A1BDB9C36__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <string>
using std::string;

#include "Operator.h"

class Plan  
{
public:
	Plan();
	virtual ~Plan();

	virtual OperatorVector toVector();

	virtual string toString();
};

#endif // !defined(AFX_PLAN_H__D00E23DC_49FB_487B_AB21_886A1BDB9C36__INCLUDED_)
