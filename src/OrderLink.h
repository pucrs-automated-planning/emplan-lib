// OrderLink.h: interface for the OrderLink class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ORDERLINK_H__EDEADAD8_0DD8_4A98_AF72_C29ED70823A1__INCLUDED_)
#define AFX_ORDERLINK_H__EDEADAD8_0DD8_4A98_AF72_C29ED70823A1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <string>
using std::string;

#include <sstream>
using std::ostringstream;

#include <vector>
using std::vector;

#include "Operator.h"

class OrderLink  
{
protected:
	Operator *oBefore;
	Operator *oAfter;
public:
	OrderLink();
	OrderLink(Operator *oBefore, Operator *oAfter);
	virtual ~OrderLink();

	bool before(Operator *oBefore, Operator *oAfter);
	OrderLink &operator=(OrderLink &olRight);

	string toString();
};

typedef vector<OrderLink> OrderLinkVector;

#endif // !defined(AFX_ORDERLINK_H__EDEADAD8_0DD8_4A98_AF72_C29ED70823A1__INCLUDED_)
