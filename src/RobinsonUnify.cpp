// RobinsonUnify.cpp: implementation of the RobinsonUnify class.
//
//////////////////////////////////////////////////////////////////////

#include "RobinsonUnify.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

RobinsonUnify::RobinsonUnify()
{
	this->t1=NULL;
	this->t2=NULL;
}

RobinsonUnify::~RobinsonUnify()
{

}

//////////////////////////////////////////////////////////////////////
// Extracted from The Handbook of Logic in Artificial Intelligence 
//and Logic Programming
// Unifies two terms and assigns the variable bindings in the pointer
//structure
//////////////////////////////////////////////////////////////////////
bool RobinsonUnify::unify(Term *k1, Term*k2)
{
	if(k1==k2)//If the nodes are physically identical, then no unification is necessary
	{
		return true;
	}else
	{
		Term *u;
		Term *v;
		// If one of the nodes is a variable node then assign the variable to *u
		if(!k2->isVariable())
		{
			u=k1;
			v=k2;
		}else
		{
			u=k2;
			v=k1;
		}
		
		if(u->isVariable())
		{
			if(v->occur(u))
				return false;// Occur check failure
			else
			{
				u->bind(v); // Replace variable u by the term corresponding to v
				return true;
				//At this point we should keep track of which bindings we have made 
				//if we want to roll back the unification of terms
			}
		}else // *u and *v are both function nodes
		{
			if((u->getName() != v->getName()) || (u->getArity() != v->getArity())) //Verify if the symbols are the same
				return false;//Clash failure
			else//If there's no clash failure, try to unify each term in *u and *v
			{
				bool bRes=true;
				int iArity=u->getArity();

				TermVector dnvTermsV=v->getTerms();
				TermVector dnvTermsU=u->getTerms();

				for(int i=0; (i<iArity && bRes); i++)
				{
					Term *dnV=dnvTermsV.at(i);
					Term *dnU=dnvTermsU.at(i);

					if(dnV->isVariable())//Added for variable trick (not in original algorithm)
						dnV=dnV->getBinding();
					if(dnU->isVariable())//Added for variable trick (not in original algorithm)
						dnU=dnU->getBinding();
					
					bRes &= unify(dnU, dnV);
				}

				return bRes;
			}
		}

	}
	return false;
}

//////////////////////////////////////////////////////////////////////
//Tries to unify two predicates
//////////////////////////////////////////////////////////////////////
bool RobinsonUnify::unifyPredicates(Predicate *p1, Predicate *p2)
{
	bool bRes=false;

	t1=p1->getTerm();
	t2=p2->getTerm();

	//PRINTL("Unifying: " << dn1->toString() << " --> " << dn2->toString())

	bRes=this->unify(t1, t2);

	if(!bRes)
	{
		//t1->unBindVariables();
		//t2->unBindVariables();
		this->rollback();
	}else
	{
		PRINTL("Unified: " << t1->toString() << " --> " << t2->toString())
	}

	return bRes;
}

void RobinsonUnify::rollback()
{

}