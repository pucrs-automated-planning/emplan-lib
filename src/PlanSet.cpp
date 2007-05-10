// PlanSet.cpp: implementation of the PlanSet class.
//
//////////////////////////////////////////////////////////////////////

#include "PlanSet.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

PlanSet::PlanSet()
{

}

PlanSet::~PlanSet()
{

}

ParallelPlan &PlanSet::operator[](int i)
{
	return pvPlans[i];
}

void PlanSet::addPlan(ParallelPlan &pp)
{
	pvPlans.push_back(pp);
}

int PlanSet::size()
{
	return pvPlans.size();
}