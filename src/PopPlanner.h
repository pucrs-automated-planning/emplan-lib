// PopPlanner.h: interface for the PopPlanner class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_POPPLANNER_H__664FD061_9519_4CF5_8616_497931EAB9CD__INCLUDED_)
#define AFX_POPPLANNER_H__664FD061_9519_4CF5_8616_497931EAB9CD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Planner.h"

#include "UnificationAlgorithm.h"
#include "PartialOrderPlan.h"

#include "Predicate.h"
#include "Operator.h"

class PopPlanner : public Planner  
{
protected:
	UnificationAlgorithm *unification;
	PartialOrderPlan *popPlan;
public:
	PopPlanner(PredicateVector &pvStart, PredicateVector &pvGoal, OperatorVector &ovOpers);
	virtual ~PopPlanner();

	PartialOrderPlan *getPopPlan();
	virtual Plan *getPlan();
	virtual bool plan();
};

#endif // !defined(AFX_POPPLANNER_H__664FD061_9519_4CF5_8616_497931EAB9CD__INCLUDED_)
