// CausalLink.cpp: implementation of the CausalLink class.
//
//////////////////////////////////////////////////////////////////////

#include "CausalLink.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
CausalLink::CausalLink()
{
	this->oFulfills=NULL;
	this->pCauses=NULL;
}

CausalLink::CausalLink(Operator *oFulfills, Predicate *pCauses)
{
	assert(oFulfills != NULL && pCauses!=NULL);
	this->oFulfills=oFulfills;
	this->pCauses=pCauses;
}

CausalLink::~CausalLink()
{

}

bool CausalLink::fulfills(Operator *o)
{
	return (o==this->oFulfills);
}

bool CausalLink::fulfilled(Predicate *p)
{
	return (p==this->pCauses);
}

CausalLink &CausalLink::operator=(CausalLink &clRight)
{
	if(this != &clRight)
	{
		this->oFulfills=clRight.oFulfills;
		this->pCauses=clRight.pCauses;
	}

	assert(oFulfills != NULL && pCauses != NULL);

	return *this;
}

string CausalLink::toString()
{
	assert(oFulfills != NULL && pCauses!=NULL);
	string sRes = oFulfills->toString() + " causes " + pCauses->toString();

	return sRes;
}