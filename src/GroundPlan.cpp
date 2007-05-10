// GroundPlan.cpp: implementation of the GroundPlan class.
//
//////////////////////////////////////////////////////////////////////

#include "GroundPlan.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

GroundPlan::GroundPlan()
{

}

GroundPlan::~GroundPlan()
{

}

OperatorInstanceVector GroundPlan::toVector()
{
	OperatorInstanceVector oivDummy;

	return oivDummy;
}

string GroundPlan::toString(OperatorInstanceVector &oiv)
{
	ostringstream out;

	for(OperatorInstanceVector::iterator i=oiv.begin(); i!=oiv.end(); i++)
	{
		OperatorInstance *oi=*i;
		out << oi->getKey() << "\n";
	}

	return out.str();
}


string GroundPlan::toString()
{
	string sRes;

	return sRes;
}
