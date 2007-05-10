// Signature.h: interface for the Signature class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SIGNATURE_H__BBA6AF45_03AA_4C30_9321_A039704214ED__INCLUDED_)
#define AFX_SIGNATURE_H__BBA6AF45_03AA_4C30_9321_A039704214ED__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <string>
using std::string;

class Signature  
{
protected:
	string sName;
	int iId;

	static int iGlobalId;
public:
	Signature();
	virtual ~Signature();

	virtual string toString()=0;
	virtual int getId();
};

#endif // !defined(AFX_SIGNATURE_H__BBA6AF45_03AA_4C30_9321_A039704214ED__INCLUDED_)
