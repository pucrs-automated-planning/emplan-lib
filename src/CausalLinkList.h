// CausalLinkList.h: interface for the CausalLinkList class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CAUSALLINKLIST_H__E7442EFB_FA92_4887_A413_8A2120FD1297__INCLUDED_)
#define AFX_CAUSALLINKLIST_H__E7442EFB_FA92_4887_A413_8A2120FD1297__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <string>
using std::string;

#include <sstream>
using std::ostringstream;

#include <map>
using std::map;
using std::less;

#include "CausalLink.h"

typedef map<Predicate *, CausalLink, less<Predicate *> > CausalLinkMap;

class CausalLinkList  
{
protected:
	//CausalLinkVector cvlCauses;
	CausalLinkMap clmCauses;
public:
	CausalLinkList();
	virtual ~CausalLinkList();

	void addCausalLink(Operator *oFulfills, Predicate *pCauses);
	bool isFulfilled(Predicate *p);
	CausalLink &operator[](Predicate *p);

	string toString();
};

#endif // !defined(AFX_CAUSALLINKLIST_H__E7442EFB_FA92_4887_A413_8A2120FD1297__INCLUDED_)
