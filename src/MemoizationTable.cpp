// MemoizationTable.cpp: implementation of the MemoizationTable class.
//
//////////////////////////////////////////////////////////////////////

#include "MemoizationTable.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

MemoizationTable::MemoizationTable()
{

}

MemoizationTable::~MemoizationTable()
{

}

//////////////////////////////////////////////////////////////////////
// Checks if the given goals in the give predicate level have not 
//already been proven unsatisfiable
//////////////////////////////////////////////////////////////////////
bool MemoizationTable::isNoGood(int iPredicateLevel, IntVector &ivGoals)
{
	//If there is no such memoization level, then obviously there can
	//be no impossible goals for it
	if(iPredicateLevel < mlNoGoods.size())
		return mlNoGoods[iPredicateLevel].isNoGood(ivGoals);
	else
		return false;
}

//////////////////////////////////////////////////////////////////////
// Marks the referred goals in the given level as not satisfiable
//////////////////////////////////////////////////////////////////////
void MemoizationTable::addNoGood(int iPredicateLevel, IntVector &ivGoals)
{
	//If there is no such predicate level
	//then allocate a new one
	if(iPredicateLevel >= mlNoGoods.size())
	{
		mlNoGoods.resize(iPredicateLevel+1);
	}
	mlNoGoods[iPredicateLevel].addNoGood(ivGoals);
}

//////////////////////////////////////////////////////////////////////
// Returns the leve
//////////////////////////////////////////////////////////////////////
MemoizationLevel &MemoizationTable::operator[](int iPredicateLevel)
{
	return mlNoGoods[iPredicateLevel];
}

//////////////////////////////////////////////////////////////////////
// Finds out if the plan has not been proven impossible to fullfill 
//given the memoization table
// The critereum behind this is that if the graph has levelled off
//at some level l and the number of memoized no-goods of l+1 equals
//the number at level l, then no plan exists
// *******************************************************************
// This method MUST be updated, I don't still know if it really works
//in its entirety * * * * * * * * * * * * * *
// It is suposed to work now, but it still depends on
//the PredicateLevel given as parameter;
// *******************************************************************
//////////////////////////////////////////////////////////////////////
bool MemoizationTable::planPossible(int iPredicateLevel)
{
	if(iPredicateLevel < mlNoGoods.size())
	{
		bool bRes=mlNoGoods[iPredicateLevel].size() != mlNoGoods[iPredicateLevel-1].size();
		return bRes;
	}else
		return true;
}

string MemoizationTable::toString()
{
	ostringstream out;

	out << "No Goods in graph:\n";
	
	for(int i=0; i<mlNoGoods.size(); i++)
	{
		out << "Level "<< i << ":\n";
		out << mlNoGoods[i].toString();
	}

	return out.str();
}