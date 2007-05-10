// RobinsonUnify.h: interface for the RobinsonUnify class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ROBINSONUNIFY_H__FDCCF0A1_FB2A_4A13_8AA3_6C77104E6FD9__INCLUDED_)
#define AFX_ROBINSONUNIFY_H__FDCCF0A1_FB2A_4A13_8AA3_6C77104E6FD9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "UnificationAlgorithm.h"

class RobinsonUnify : public UnificationAlgorithm  
{
protected:
	Term *t1, *t2;

	bool unify(Term *k1, Term *k2);
public:
	RobinsonUnify();
	virtual ~RobinsonUnify();

	virtual bool unifyPredicates(Predicate *p1, Predicate *p2);
	virtual void rollback();
};

#endif // !defined(AFX_ROBINSONUNIFY_H__FDCCF0A1_FB2A_4A13_8AA3_6C77104E6FD9__INCLUDED_)
