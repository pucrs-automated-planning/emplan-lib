// ActionLevel.h: interface for the ActionLevel class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ACTIONLEVEL_H__D3D6BA2B_9D45_4E79_958B_95943B7B34D1__INCLUDED_)
#define AFX_ACTIONLEVEL_H__D3D6BA2B_9D45_4E79_958B_95943B7B34D1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <vector>
using std::vector;

#include <string>
using std::string;

#include <sstream>
using std::stringstream;
using std::ostringstream;

#include "Debug.h"

#include "ActionNode.h"

class ActionLevel  
{
protected:
	ActionNodeVector anvActions;

public:
	ActionLevel();
	virtual ~ActionLevel();

	void addActions(OperatorInstanceVector &oiv);
	int addAction(OperatorInstance *oi);
	ActionNode &operator[](int iRef);
	int size();
	bool isMutex(int i1, int i2);
	void addMutex(int i1, int i2);
	int countMutexes();
	int countPreconditionEdges();
	int countEffectEdges();

	bool operator==(ActionLevel &alRight);

	string toString();
};

typedef vector<ActionLevel> ActionLevelVector;

#endif // !defined(AFX_ACTIONLEVEL_H__D3D6BA2B_9D45_4E79_958B_95943B7B34D1__INCLUDED_)
