// ParallelPlan.h: interface for the ParallelPlan class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PARALLELPLAN_H__76B7B1EC_DF7F_4175_B4CE_54C676593DC9__INCLUDED_)
#define AFX_PARALLELPLAN_H__76B7B1EC_DF7F_4175_B4CE_54C676593DC9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <string>
using std::string;

#include <sstream>
using std::ostringstream;

#include <vector>
using std::vector;

#include <algorithm>
using std::find;

#include "GroundPlan.h"
#include "OperatorInstance.h"

typedef vector<OperatorInstance *> ParallelPlanLevel;
typedef vector<ParallelPlanLevel> ParallelPlanLevelVector;

class ParallelPlan: public GroundPlan
{
protected:
	ParallelPlanLevelVector pplv;
public:
	ParallelPlan();
	ParallelPlan(int iSize);
	virtual ~ParallelPlan();

	void addAction(int iLevel, OperatorInstance *oiAction);
	ParallelPlanLevel &operator[](int iLevel);

	virtual OperatorInstanceVector toVector();

	virtual string toString(OperatorInstanceVector &oiv);
	virtual string toString();
};

#endif // !defined(AFX_PARALLELPLAN_H__76B7B1EC_DF7F_4175_B4CE_54C676593DC9__INCLUDED_)
