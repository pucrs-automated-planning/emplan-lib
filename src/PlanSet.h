// PlanSet.h: interface for the PlanSet class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PLANSET_H__B64647A1_6482_4F14_BC1C_52299F9CB23A__INCLUDED_)
#define AFX_PLANSET_H__B64647A1_6482_4F14_BC1C_52299F9CB23A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <vector>
using std::vector;

#include "OperatorInstance.h"
#include "ParallelPlan.h"

//////////////////////////////////////////////////////////////////////
// Server only as a holder for multiple plans
//////////////////////////////////////////////////////////////////////
class PlanSet  
{
	typedef vector<ParallelPlan> PlanVector;
protected:
	PlanVector pvPlans;
public:
	PlanSet();
	virtual ~PlanSet();

	ParallelPlan &operator[](int i);
	void addPlan(ParallelPlan &pp);
	int size();
};

#endif // !defined(AFX_PLANSET_H__B64647A1_6482_4F14_BC1C_52299F9CB23A__INCLUDED_)
