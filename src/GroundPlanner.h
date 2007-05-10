// GroundPlanner.h: interface for the GroundPlanner class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_GROUNDPLANNER_H__6ED77106_F4AD_448F_9536_744048333F98__INCLUDED_)
#define AFX_GROUNDPLANNER_H__6ED77106_F4AD_448F_9536_744048333F98__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <vector>
using std::vector;

#include "GroundPlan.h"

#include "OperatorInstance.h"
#include "PredicateInstance.h"

//////////////////////////////////////////////////////////////////////
// Abstracts a planner that works only with ground instances
//////////////////////////////////////////////////////////////////////
class GroundPlanner  
{
protected:
	PredicateInstanceVector pivStart;
	PredicateInstanceVector pivGoal;
	OperatorInstanceVector oivOperators;
public:
	//Creates the planner given the start conditions, the goals and the operators
	GroundPlanner(PredicateInstanceVector &pivStart, PredicateInstanceVector &pivGoal, OperatorInstanceVector &oivOperators);
	virtual ~GroundPlanner();

	virtual bool plan()=0;
	virtual OperatorInstanceVector getPlanVector()=0;
	virtual GroundPlan *getPlan()=0;
	virtual string getStats()=0;

	virtual string toString()=0;
};

#endif // !defined(AFX_GROUNDPLANNER_H__6ED77106_F4AD_448F_9536_744048333F98__INCLUDED_)
