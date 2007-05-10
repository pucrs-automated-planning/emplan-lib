// PlanLevel.h: interface for the PlanLevel class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PLANLEVEL_H__D196D242_17DC_4BA7_9F9A_92F80E5C2096__INCLUDED_)
#define AFX_PLANLEVEL_H__D196D242_17DC_4BA7_9F9A_92F80E5C2096__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <vector>
using std::vector;

#include <algorithm>
using std::find;
using std::remove;

#include <string>
using std::string;

#include <sstream>
using std::ostringstream;

class PlanLevel  
{
	typedef vector<int> IntVector;
protected:
	IntVector ivActions;
public:
	PlanLevel();
	virtual ~PlanLevel();

	//Adds an action to the plan level, return true if the action was new to the level
	bool addAction(int iAction);
	//Removes an action from the plan
	void removeAction(int iAction);
	//Checks if the referred action is not already in the plan
	bool hasAction(int iAction);

	//Returns the action stored in the referred action level
	int operator[](int iIndex);
	//Returns the size (i.e. the number of actions chosen for the current level)
	int size();
	//Clears all the actions in the current level
	void clearLevel();
	//Returns a string representation of the current level
	string toString();

};

typedef vector<PlanLevel> PlanLevelVector;

#endif // !defined(AFX_PLANLEVEL_H__D196D242_17DC_4BA7_9F9A_92F80E5C2096__INCLUDED_)
