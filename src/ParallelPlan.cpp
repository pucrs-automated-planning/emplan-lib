// ParallelPlan.cpp: implementation of the ParallelPlan class.
//
//////////////////////////////////////////////////////////////////////

#include "ParallelPlan.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

ParallelPlan::ParallelPlan()
{

}

ParallelPlan::ParallelPlan(int iSize)
{
	pplv.resize(iSize);
}

ParallelPlan::~ParallelPlan()
{

}

void ParallelPlan::addAction(int iLevel, OperatorInstance *oiAction)
{
	if(pplv.size()<=iLevel)
	{
		pplv.resize(iLevel+1);
	}

	if(find(pplv[iLevel].begin(), pplv[iLevel].end(), oiAction)==pplv[iLevel].end())
	{
		pplv[iLevel].push_back(oiAction);
	}
}

ParallelPlanLevel &ParallelPlan::operator[](int iLevel)
{
	return pplv[iLevel];
}

OperatorInstanceVector ParallelPlan::toVector()
{
	OperatorInstanceVector oivRes;

	for(ParallelPlanLevelVector::iterator i=pplv.begin(); i!=pplv.end() ;i++)
	{
		for(ParallelPlanLevel::iterator j=i->begin(); j!=i->end(); j++)
		{
			oivRes.push_back(*j);
		}
	}
	
	return oivRes;
}

string ParallelPlan::toString(OperatorInstanceVector &oiv)
{
	ostringstream out;

	for(OperatorInstanceVector::iterator i=oiv.begin(); i!=oiv.end(); i++)
	{
		OperatorInstance *oi=*i;
		out << oi->getKey() << ".\n";
	}

	return out.str();
}

string ParallelPlan::toString()
{
	ostringstream out;

	for(int i=0; i<pplv.size(); i++)
	{
		out << "Level " << i << ":\n";
		for(int j=0; j<pplv[i].size(); j++)
		{
			out << "\t" << pplv[i][j]->getKey() << "\n";
		}
	}

	return out.str();
}