// OrderLink.cpp: implementation of the OrderLink class.
//
//////////////////////////////////////////////////////////////////////

#include "OrderLink.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

OrderLink::OrderLink()
{
	this->oBefore=NULL;
	this->oAfter=NULL;
}

OrderLink::OrderLink(Operator *oBefore, Operator *oAfter)
{
	assert(oBefore != NULL && oAfter != NULL);
	this->oBefore=oBefore;
	this->oAfter=oAfter;
}

OrderLink::~OrderLink()
{

}

bool OrderLink::before(Operator *oBefore, Operator *oAfter)
{
	return ((this->oBefore==oBefore) && (this->oAfter==oAfter));
}

OrderLink &OrderLink::operator=(OrderLink &olRight)
{
	if(this != &olRight)
	{
		this->oBefore=olRight.oBefore;
		this->oAfter=olRight.oAfter;
	}

	assert(oBefore != NULL && oAfter != NULL);

	return *this;
}

string OrderLink::toString()
{
	ostringstream oRes;

	assert(oBefore != NULL && oAfter != NULL);

	oRes << oBefore->toHeaderString() << " -> " << oAfter->toHeaderString();

	return oRes.str();
}