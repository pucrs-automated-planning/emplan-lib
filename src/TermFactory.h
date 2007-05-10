// TermFactory.h: interface for the TermFactory class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TermFACTORY_H__C53C04D7_5D7D_4AC3_895E_EC59C33372FB__INCLUDED_)
#define AFX_TermFACTORY_H__C53C04D7_5D7D_4AC3_895E_EC59C33372FB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Term.h"

class TermFactory  
{
public:
	static Term * newTerm(const string &sName, TermVector dnvTerms);
	static Term * newTerm(const string &sName, bool bVar=false);
	TermFactory();
	virtual ~TermFactory();

};

#endif // !defined(AFX_TermFACTORY_H__C53C04D7_5D7D_4AC3_895E_EC59C33372FB__INCLUDED_)
