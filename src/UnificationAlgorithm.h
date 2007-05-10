// UnificationAlgorithm.h: interface for the UnificationAlgorithm class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UNIFICATIONALGORITHM_H__AA138CB1_ECC3_48CD_943D_5C1EC2A9DAD1__INCLUDED_)
#define AFX_UNIFICATIONALGORITHM_H__AA138CB1_ECC3_48CD_943D_5C1EC2A9DAD1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Predicate.h"
#include "Term.h"

class UnificationAlgorithm  
{
public:
	UnificationAlgorithm();
	virtual ~UnificationAlgorithm();

	//Unifies two Predicates assigning the variable bindings in the
	//Predicate's pointer structures
	virtual bool unifyPredicates(Predicate *p1, Predicate *p2)=0;
	//Rolls back the unification so that the variable binding made in
	//the last unification are undone
	virtual void rollback()=0;
};

#endif // !defined(AFX_UNIFICATIONALGORITHM_H__AA138CB1_ECC3_48CD_943D_5C1EC2A9DAD1__INCLUDED_)
