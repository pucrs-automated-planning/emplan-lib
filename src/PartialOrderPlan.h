// PartialOrderPlan.h: interface for the PartialOrderPlan class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PARTIALORDERPLAN_H__9319F349_BCB3_4792_B802_2AF44C65C2C2__INCLUDED_)
#define AFX_PARTIALORDERPLAN_H__9319F349_BCB3_4792_B802_2AF44C65C2C2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <algorithm>
using std::sort;

#include <string>
using std::string;

#include "Plan.h"

#include "Debug.h"

#include "UnificationAlgorithm.h"
#include "RobinsonUnify.h"

#include "Term.h"
#include "Predicate.h"
#include "Operator.h"

#include "CausalLinkList.h"
#include "OrderLinkList.h"

typedef map<Predicate*, Operator*, less<Predicate*> > OperatorMap;

class PartialOrderPlan : public Plan  
{
protected:
	UnificationAlgorithm *unification;

	//The operators that are currently used in the plan
	OperatorVector ovSteps;
	//The "Pseudo-Operator" corresponding to the start state
	Operator *oStart;
	//The "Pseudo-Operator" corresponding to the goal state
	Operator *oGoal;
	//The causal links between plan steps denoting the linking predicates
	CausalLinkList cllCauses;

	//The order links between plan steps
	OrderLinkList ollOrder;

	//The precondition-predicates that have not been dealt
	//with by the steps currently in the plan along with their associated operators
	OperatorMap omUnfulfilled;

	void sortSteps();
public:
	PartialOrderPlan();
	PartialOrderPlan(PredicateVector &pvStart, PredicateVector &pvGoal);
	virtual ~PartialOrderPlan();

	bool isSolution();
	Predicate *selectSubgoal();
	Operator *getOperatorFromGoal(Predicate *p);
	bool chooseOperator(Predicate *pCause, Operator *oCause, OperatorVector ovOperators);
	bool resolveThreats();

	PartialOrderPlan &operator=(PartialOrderPlan &popRight);

	virtual OperatorVector toVector();
	virtual string toString();
};

#endif // !defined(AFX_PARTIALORDERPLAN_H__9319F349_BCB3_4792_B802_2AF44C65C2C2__INCLUDED_)
