// PlanLevelSet.h: interface for the PlanLevelSet class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PLANLEVELSET_H__6A47B83F_5A49_4671_9DA9_708A0FE6C360__INCLUDED_)
#define AFX_PLANLEVELSET_H__6A47B83F_5A49_4671_9DA9_708A0FE6C360__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <string>
using std::string;

#include <sstream>
using std::ostringstream;

#include "PlanLevel.h"

class PlanLevelSet  
{
protected:
	PlanLevelVector plvLevels;
public:
	PlanLevelSet();
	PlanLevelSet(int iSize);
	virtual ~PlanLevelSet();

	//Returns the plan level at the specified index
	PlanLevel &operator[](int iIndex);
	//Clears the planlevel specified by the index
	void clearLevel(int iLevel);
	//Returns the number of levels a plan contains
	int size();
	//Returns a string representation of the plan
	string toString();

};

#endif // !defined(AFX_PLANLEVELSET_H__6A47B83F_5A49_4671_9DA9_708A0FE6C360__INCLUDED_)
