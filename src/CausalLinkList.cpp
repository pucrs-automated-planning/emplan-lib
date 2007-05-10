// CausalLinkList.cpp: implementation of the CausalLinkList class.
//
//////////////////////////////////////////////////////////////////////

#include "CausalLinkList.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CausalLinkList::CausalLinkList()
{

}

CausalLinkList::~CausalLinkList()
{

}

void CausalLinkList::addCausalLink(Operator *oFulfills, Predicate *pCauses)
{
	if(!this->isFulfilled(pCauses))
	{
		CausalLink cl(oFulfills, pCauses);
		clmCauses[pCauses]=cl;
	}
}

bool CausalLinkList::isFulfilled(Predicate *p)
{
	if(clmCauses.find(p) != clmCauses.end())
		return true;
	else
		return false;
}

CausalLink &CausalLinkList::operator[](Predicate *p)
{
	return clmCauses[p]; 
}

string CausalLinkList::toString()
{
	ostringstream oRes;

	oRes << "Causal Links\n";

	for(CausalLinkMap::iterator i=clmCauses.begin(); i!=clmCauses.end(); i++)
	{
		if(i!=clmCauses.begin())
			oRes << " ** ";
		oRes << i->second.toString();
	}

	return oRes.str();
}