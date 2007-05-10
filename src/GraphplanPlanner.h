// GraphplanPlanner.h: interface for the GraphplanPlanner class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_GRAPHPLANPLANNER_H__64E2E44B_A654_44A5_A2DE_2956A7D4A4C3__INCLUDED_)
#define AFX_GRAPHPLANPLANNER_H__64E2E44B_A654_44A5_A2DE_2956A7D4A4C3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <string>
using std::string;

#include <sstream>
using std::ostringstream;

#include <fstream>
using std::ofstream;

#include "Debug.h"
#include "Consoleout.h"

#include "PlanningGraph.h"
#include "FigPlanningGraphDrawer.h"

#include "GroundPlanner.h"

#include "ParallelPlan.h"

#include "OperatorInstance.h"
#include "PredicateInstance.h"

class GraphplanPlanner : public GroundPlanner  
{
protected:
	string sStats;
	ParallelPlan ppPlan;
	bool bUseMemoization;
	bool bWritePartial;
	string sWritePartial;
	PlanningGraph pg;

	bool bPlanPossible;
	bool extractSolution(PlanningGraph &pg);
	void gatherStats(PlanningGraph &pg);
public:
	GraphplanPlanner(PredicateInstanceVector &pivStart, PredicateInstanceVector &pivGoal, OperatorInstanceVector &oivOperators, bool bUseMemoization=true);
	virtual ~GraphplanPlanner();

	virtual bool plan();
	virtual OperatorInstanceVector getPlanVector();
	virtual GroundPlan *getPlan();
	ParallelPlan &getParallelPlan();

	void setMemoization(bool bUseMemoization);
	void setWritePartial(bool bWritePartial, string sWritePartial="graph");
	
	ostream &drawGraph(int iFormat, ostream &out);

	virtual string getStats();
	virtual string toString();
};

#endif // !defined(AFX_GRAPHPLANPLANNER_H__64E2E44B_A654_44A5_A2DE_2956A7D4A4C3__INCLUDED_)
