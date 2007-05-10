// PredicateLevel.cpp: implementation of the PredicateLevel class.
//
//////////////////////////////////////////////////////////////////////

#include "PredicateLevel.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

PredicateLevel::PredicateLevel()
{

}

PredicateLevel::~PredicateLevel()
{

}

//////////////////////////////////////////////////////////////////////
// Adds the given predicates to the predicate level
//////////////////////////////////////////////////////////////////////
void PredicateLevel::addPredicates(PredicateInstanceVector &piv)
{
	for(PredicateInstanceVector::iterator i=piv.begin(); i!=piv.end(); i++)
	{
		this->addPredicate(*i);
	}
}

//////////////////////////////////////////////////////////////////////
// Adds a single predicate to the predicate level
// The predicate is stored in a PredicateNode
//////////////////////////////////////////////////////////////////////
int PredicateLevel::addPredicate(PredicateInstance *pi)
{
	PredicateNode pn(pi);

	//if(pnvPredicates.find(pn)!=pnvPredicates.end())
	pnvPredicates.push_back(pn);

	return 0;
}

//////////////////////////////////////////////////////////////////////
// Returns the PredicateNode stored in the given index
//////////////////////////////////////////////////////////////////////
PredicateNode &PredicateLevel::operator[](int iRef)
{
	return this->pnvPredicates[iRef];
}

//////////////////////////////////////////////////////////////////////
// Returns the the number of predicate nodes stored in this level
//////////////////////////////////////////////////////////////////////
int PredicateLevel::size()
{
	return this->pnvPredicates.size();
}

//////////////////////////////////////////////////////////////////////
// Returns wheter the predicate nodes referred by the indexes
// are mutex or not
//////////////////////////////////////////////////////////////////////
bool PredicateLevel::isMutex(int i1, int i2)
{
	return pnvPredicates[i1].isMutex(i2);
}

//////////////////////////////////////////////////////////////////////
// Adds a mutex relation between the two referred predicates
//////////////////////////////////////////////////////////////////////
void PredicateLevel::addMutex(int i1, int i2)
{
	pnvPredicates[i1].addMutex(i2);
	pnvPredicates[i2].addMutex(i1);
}

//////////////////////////////////////////////////////////////////////
// Counts the number of mutexes between the nodes in this level
//////////////////////////////////////////////////////////////////////
int PredicateLevel::countMutexes()
{
	int iRes=0;

	for(PredicateNodeVector::iterator i=pnvPredicates.begin(); i!=pnvPredicates.end(); i++)
	{
		iRes+=i->countMutexes();
	}

	return iRes;
}

//////////////////////////////////////////////////////////////////////
// Checks the predicate level given for equality
//////////////////////////////////////////////////////////////////////
bool PredicateLevel::operator==(PredicateLevel &plRight)
{
	bool bRes=true;

	if(this!=&plRight)
	{
		bRes &= ((this->size() == plRight.size()) && (this->countMutexes() == plRight.countMutexes()));

		for(int i=0; bRes && (i<this->size()); i++)
		{
			bRes &= (pnvPredicates[i]==plRight[i]);
		}	
	}else
		bRes=true;

	return bRes;
}

//////////////////////////////////////////////////////////////////////
// Returns a string representation of the predicate level
//////////////////////////////////////////////////////////////////////
string PredicateLevel::toString()
{
	ostringstream sRes;

	for(int i=0; i<pnvPredicates.size(); i++)
	{
		sRes << " * " << i << "-" << pnvPredicates[i].toString();
	}

	return sRes.str();
}