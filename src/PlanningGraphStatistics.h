// PlanningGraphStatistics.h: interface for the PlanningGraphStatistics class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PLANNINGGRAPHSTATISTICS_H__767FFF9F_542A_413F_BCD9_F31CB0AA769D__INCLUDED_)
#define AFX_PLANNINGGRAPHSTATISTICS_H__767FFF9F_542A_413F_BCD9_F31CB0AA769D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <string>
using std::string;

#include <sstream>
using std::ostringstream;

#include <vector>
using std::vector;

typedef vector<int> IntVector;

class PlanningGraphStatistics  
{
protected:
	IntVector ivActionNodes;
	IntVector ivPredicateNodes;
	IntVector ivPreconditionEdges;
	IntVector ivEffectEdges;

	IntVector ivActionMutexes;
	IntVector ivPredicateMutexes;
public:
	PlanningGraphStatistics();
	virtual ~PlanningGraphStatistics();

	void setActionNodes(int iActionLevel, int iNodes);
	void setPredicateNodes(int iPredicateLevel, int iNodes);
	void setPreconditionEdges(int iActionLevel, int iEdges);
	void setEffectEdges(int iActionLevel, int iEdges);
	void setActionMutexes(int iActionLevel, int iMutexes);
	void setPredicateMutexes(int iPredicateLevel, int iMutexes);

	int getActionNodes(int iActionLevel);
	int getPredicateNodes(int iPredicateLevel);
	int getPreconditionEdges(int iActionLevel);
	int getEffectEdges(int iActionLevel);
	int getActionMutexes(int iActionLevel);
	int getPredicateMutexes(int iPredicateLevel);

	int totalActionNodes();
	int totalPredicateNodes();
	int totalPreconditionEdges();
	int totalEffectEdges();
	int totalActionMutexes();
	int totalPredicateMutexes();

	PlanningGraphStatistics &operator=(PlanningGraphStatistics &pgsRight);

	string toString();
};

#endif // !defined(AFX_PLANNINGGRAPHSTATISTICS_H__767FFF9F_542A_413F_BCD9_F31CB0AA769D__INCLUDED_)
