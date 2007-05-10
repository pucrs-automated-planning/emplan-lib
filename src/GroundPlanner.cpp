// GroundPlanner.cpp: implementation of the GroundPlanner class.
//
//////////////////////////////////////////////////////////////////////

#include "GroundPlanner.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

GroundPlanner::GroundPlanner(PredicateInstanceVector &pivStart, PredicateInstanceVector &pivGoal, OperatorInstanceVector &oivOperators)
{
	this->pivStart=pivStart;
	this->pivGoal=pivGoal;
	this->oivOperators=oivOperators;
}

GroundPlanner::~GroundPlanner()
{

}
