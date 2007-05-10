// PredicateNode.h: interface for the PredicateNode class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PREDICATENODE_H__C897CD6A_D6D3_420F_A310_AD9E0E19398D__INCLUDED_)
#define AFX_PREDICATENODE_H__C897CD6A_D6D3_420F_A310_AD9E0E19398D__INCLUDED_

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

#include "PredicateInstance.h"

typedef vector<int> IntVector;

class PredicateNode  
{
protected:
	PredicateInstance *piPredicate;
	IntVector ivMutexes;
	IntVector ivCondMutexes;

	IntVector ivPreconditionLinks;
	IntVector ivEffectLinks;
public:
	PredicateNode();
	PredicateNode(PredicateInstance *piPredicate);
	virtual ~PredicateNode();

	void addMutex(int iMutex);
	void addCondMutex(int iMutex);
	bool isMutex(int iMutex);
	int countMutexes();
	IntVector &getMutexes();
	PredicateInstance *getPredicate();

	void linkPrecondition(int iPreconditionIndex);
	IntVector &getPreconditionLinks();
	void linkEffect(int iEffectIndex);
	IntVector &getEffectLinks();
	
	PredicateNode &operator=(const PredicateNode &pnRight);
	bool operator==(PredicateNode &pnRight);

	string toString();

};

typedef vector<PredicateNode> PredicateNodeVector;

#endif // !defined(AFX_PREDICATENODE_H__C897CD6A_D6D3_420F_A310_AD9E0E19398D__INCLUDED_)
