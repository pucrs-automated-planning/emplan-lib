// OrderLinkList.h: interface for the OrderLinkList class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ORDERLINKLIST_H__DD9B447E_02DF_4B7E_BE69_2013F0336BCC__INCLUDED_)
#define AFX_ORDERLINKLIST_H__DD9B447E_02DF_4B7E_BE69_2013F0336BCC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <string>
using std::string;

#include <sstream>
using std::stringstream;

#include <map>
using std::multimap;
using std::less;
using std::pair;

#include "OrderLink.h"

typedef multimap<Operator *, OrderLink, less<Operator *> > OrderLinkMap;

class OrderLinkList  
{
protected:
	OrderLinkMap olmOrder;
public:
	OrderLinkList();
	virtual ~OrderLinkList();

	void addOrderLink(Operator *oBefore, Operator *oAfter);
	bool before(Operator *oBefore, Operator *oAfter);



	string toString();
};

#endif // !defined(AFX_ORDERLINKLIST_H__DD9B447E_02DF_4B7E_BE69_2013F0336BCC__INCLUDED_)
