// MemoizationLevel.h: interface for the MemoizationLevel class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MEMOIZATIONLEVEL_H__AFD51A47_01BE_45EC_8F6E_81ACA5F26C33__INCLUDED_)
#define AFX_MEMOIZATIONLEVEL_H__AFD51A47_01BE_45EC_8F6E_81ACA5F26C33__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <map>
using std::map;
using std::less;

#include <vector>
using std::vector;

#include <string>
using std::string;

#include <sstream>
using std::ostringstream;

#include <algorithm>
using std::sort;

typedef vector<int> IntVector;
typedef map<string, bool, less<string> > IntVectorMap;

class MemoizationLevel
{
protected:
	IntVectorMap ivmNoGoods;

	string makeKey(IntVector &iv);
	string intToKey(int i);
public:
	MemoizationLevel();
	virtual ~MemoizationLevel();

	bool isNoGood(IntVector &ivGoals);
	void addNoGood(IntVector &ivGoals);

	int size();

	string toString();
};

#endif // !defined(AFX_MEMOIZATIONLEVEL_H__AFD51A47_01BE_45EC_8F6E_81ACA5F26C33__INCLUDED_)
