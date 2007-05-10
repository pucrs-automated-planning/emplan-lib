// PopPlanner.cpp: implementation of the PopPlanner class.
//
//////////////////////////////////////////////////////////////////////

#include "PopPlanner.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

PopPlanner::PopPlanner(PredicateVector &pvStart, PredicateVector &pvGoal, OperatorVector &ovOpers):Planner(pvStart, pvGoal, ovOpers)
{

}

PopPlanner::~PopPlanner()
{

}

bool PopPlanner::plan()
{
	bool bRes=true;

	this->popPlan=new PartialOrderPlan(this->pvStart, this->pvGoal);;
	
	while(!popPlan->isSolution())
	{
		//(S-need, c) = select-subgoal(plan) ; // choose an unsolved goal
		Predicate *pCause=popPlan->selectSubgoal();
		Operator *oCause=popPlan->getOperatorFromGoal(pCause);

		//choose-operator(plan, operators, S-need, c);
		if(!popPlan->chooseOperator(pCause, oCause, ovOpers))
			return false;
		// select an operator to solve that goal and revise plan
		//resolve-threats(plan);  // fix any threats created

		if(!popPlan->resolveThreats())
			return false;

		//PRINTL(pPlan->toString())
	}
	
	return bRes;
}

PartialOrderPlan *PopPlanner::getPopPlan()
{
	popPlan->toVector();
	return popPlan;
}

Plan *PopPlanner::getPlan()
{
	return popPlan;
}