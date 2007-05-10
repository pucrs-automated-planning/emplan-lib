// OrderLinkList.cpp: implementation of the OrderLinkList class.
//
//////////////////////////////////////////////////////////////////////

#include "OrderLinkList.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

OrderLinkList::OrderLinkList()
{

}

OrderLinkList::~OrderLinkList()
{

}

void OrderLinkList::addOrderLink(Operator *oBefore, Operator *oAfter)
{
	OrderLink ol(oBefore, oAfter);
	
	olmOrder.insert(pair<Operator *, OrderLink> (oBefore, ol));

}

bool OrderLinkList::before(Operator *oBefore, Operator *oAfter)
{
	for(OrderLinkMap::iterator i=olmOrder.find(oBefore);i!=olmOrder.end();i++)
	{
		if(i->second.before(oBefore, oAfter))
			return true;
	}

	return false;
}

string OrderLinkList::toString()
{
	ostringstream oRes;

	oRes << "Order Links\n";

	for(OrderLinkMap::iterator i=olmOrder.begin(); i!=olmOrder.end(); i++)
	{
		if(i!=olmOrder.begin())
			oRes << "\n";
		oRes << i->second.toString();
	}

	return oRes.str();
}