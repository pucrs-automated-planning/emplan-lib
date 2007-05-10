// MemoizationTable.h: interface for the MemoizationTable class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MEMOIZATIONTABLE_H__ADFBD32D_15D7_4369_9312_47ADCAE0FF1E__INCLUDED_)
#define AFX_MEMOIZATIONTABLE_H__ADFBD32D_15D7_4369_9312_47ADCAE0FF1E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <string>
using std::string;

#include <sstream>
using std::ostringstream;

#include <vector>
using std::vector;

#include <map>
using std::map;
using std::less;

#include "Debug.h"

#include "MemoizationLevel.h"

typedef vector<MemoizationLevel> MemoizationLevels;

class MemoizationTable
{
protected:
	MemoizationLevels mlNoGoods;
public:
	MemoizationTable();
	virtual ~MemoizationTable();

	bool isNoGood(int iPredicateLevel, IntVector &ivGoals);
	void addNoGood(int iPredicateLevel, IntVector &ivGoals);

	MemoizationLevel &operator[](int iPredicateLevel);

	bool planPossible(int iPredicateLevel);

	string toString();
};

#endif // !defined(AFX_MEMOIZATIONTABLE_H__ADFBD32D_15D7_4369_9312_47ADCAE0FF1E__INCLUDED_)
