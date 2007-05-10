// Planner.cpp: implementation of the Planner class.
//
//////////////////////////////////////////////////////////////////////

#include "Planner.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Planner::Planner(PredicateVector &pvStart, PredicateVector &pvGoal, OperatorVector &ovOpers)
{
	this->pvStart=pvStart;
	this->pvGoal=pvGoal;
	this->ovOpers=ovOpers;
}

Planner::~Planner()
{

}

Planner &Planner::operator=(Planner &pRight)
{
	if(this != &pRight)
	{
		this->pvStart=pRight.pvStart;
		this->pvGoal=pRight.pvGoal;
		this->ovOpers=pRight.ovOpers;
	}

	return *this;
}