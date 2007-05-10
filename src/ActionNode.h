// ActionNode.h: interface for the ActionNode class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ACTIONNODE_H__80786CC8_8706_471D_9F75_8DEA2B8F1C81__INCLUDED_)
#define AFX_ACTIONNODE_H__80786CC8_8706_471D_9F75_8DEA2B8F1C81__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <sstream>
using std::ostringstream;

#include <algorithm>
using std::find;

#include "Debug.h"

#include "OperatorInstance.h"

typedef vector<int> IntVector;

class ActionNode  
{
protected:
	OperatorInstance *oiAction;
	IntVector ivMutexes;
	IntVector ivCondMutexes;

	IntVector ivPreconditionLinks;
	IntVector ivEffectLinks;
public:
	ActionNode();
	ActionNode(OperatorInstance *oiAction);
	virtual ~ActionNode();

	void addMutex(int iMutex);
	void addCondMutex(int iMutex);
	bool isMutex(int iMutex);
	int countMutexes();
	IntVector &getMutexes();
	OperatorInstance *getAction();

	void linkPrecondition(int iPreconditionIndex);
	IntVector &getPreconditionLinks();
	void linkEffect(int iEffectIndex);
	IntVector &getEffectLinks();
	
	ActionNode &operator=(const ActionNode &anRight);
	bool operator==(ActionNode &anRight);

	string toString();
};

typedef vector<ActionNode> ActionNodeVector;

#endif // !defined(AFX_ACTIONNODE_H__80786CC8_8706_471D_9F75_8DEA2B8F1C81__INCLUDED_)
