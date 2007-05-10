// Planner.h: interface for the Planner class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PLANNER_H__915AADA1_B8B4_4AF1_88DC_A8E04728AEEE__INCLUDED_)
#define AFX_PLANNER_H__915AADA1_B8B4_4AF1_88DC_A8E04728AEEE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Predicate.h"
#include "Term.h"
#include "Operator.h"
#include "Plan.h"

class Planner  
{
protected:
	PredicateVector pvStart;
	PredicateVector pvGoal;
	OperatorVector ovOpers;
public:
	Planner(PredicateVector &pvStart, PredicateVector &pvGoal, OperatorVector &ovOpers);
	virtual ~Planner();
	virtual Plan *getPlan()=0;
	virtual bool plan()=0;
	virtual Planner &operator=(Planner &pRight);
};

#endif // !defined(AFX_PLANNER_H__915AADA1_B8B4_4AF1_88DC_A8E04728AEEE__INCLUDED_)
