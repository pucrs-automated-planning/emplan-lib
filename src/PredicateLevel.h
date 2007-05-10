// PredicateLevel.h: interface for the PredicateLevel class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PREDICATELEVEL_H__8CA05E38_22D4_4A75_8FF1_8868DDA80A92__INCLUDED_)
#define AFX_PREDICATELEVEL_H__8CA05E38_22D4_4A75_8FF1_8868DDA80A92__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <vector>
using std::vector;

#include <string>
using std::string;

#include <sstream>
using std::ostringstream;

#include "Debug.h"

#include "PredicateNode.h"

class PredicateLevel  
{
protected:
	PredicateNodeVector pnvPredicates;
public:
	PredicateLevel();
	virtual ~PredicateLevel();
	
	void addPredicates(PredicateInstanceVector &piv);
	int addPredicate(PredicateInstance *pi);
	PredicateNode &operator[](int iRef);
	int size();
	bool isMutex(int i1, int i2);
	void addMutex(int i1, int i2);
	int countMutexes();

	bool operator==(PredicateLevel &plRight);

	string toString();
};

typedef vector<PredicateLevel> PredicateLevelVector;

#endif // !defined(AFX_PREDICATELEVEL_H__8CA05E38_22D4_4A75_8FF1_8868DDA80A92__INCLUDED_)
