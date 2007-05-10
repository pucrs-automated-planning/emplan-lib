// PlanningGraphDrawer.h: interface for the PlanningGraphDrawer class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PLANNINGGRAPHDRAWER_H__2B3D5419_9F2B_49EA_B0ED_431146E06386__INCLUDED_)
#define AFX_PLANNINGGRAPHDRAWER_H__2B3D5419_9F2B_49EA_B0ED_431146E06386__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <ostream>
using std::ostream;

#include "ActionNode.h"
#include "ActionLevel.h"

#include "PredicateNode.h"
#include "PredicateLevel.h"

class PlanningGraphDrawer
{
public:
	PlanningGraphDrawer();
	virtual ~PlanningGraphDrawer();

	virtual ostream &drawGraph(PredicateLevelVector &plvPredicates, ActionLevelVector &alvActions, ostream &out)=0;
};

#endif // !defined(AFX_PLANNINGGRAPHDRAWER_H__2B3D5419_9F2B_49EA_B0ED_431146E06386__INCLUDED_)
