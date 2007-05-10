// TermSignature.h: interface for the TermSignature class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TERMSIGNATURE_H__65A71333_7B3E_4E27_9845_F2AD41BFA644__INCLUDED_)
#define AFX_TERMSIGNATURE_H__65A71333_7B3E_4E27_9845_F2AD41BFA644__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Signature.h"
#include "Term.h"

class TermSignature : public Signature  
{
protected:
	Term *tSignature;
public:
	TermSignature();
	TermSignature(Term *t);
	virtual ~TermSignature();

	virtual string toString();
	TermSignature & operator=(TermSignature &tRight);

	Term *getTerm();
	
	static string getSignature(Term *t);
};

#endif // !defined(AFX_TERMSIGNATURE_H__65A71333_7B3E_4E27_9845_F2AD41BFA644__INCLUDED_)
