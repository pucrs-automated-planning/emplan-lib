// PredicateFactory.cpp: implementation of the PredicateFactory class.
//
//////////////////////////////////////////////////////////////////////

#include "PredicateFactory.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

PredicateFactory::PredicateFactory()
{

}

PredicateFactory::~PredicateFactory()
{

}

Predicate * PredicateFactory::newPredicate(const string &s, bool bNot)
{
	TermVector dnvTerms;
	Term *dn=new Term(s, dnvTerms);
	Predicate *p=new Predicate(dn, bNot);

	return p;
}

Predicate * PredicateFactory::newPredicate(const string &s, TermVector *dnvTerms, bool bNot)
{
	TermVector dnv;
	if(dnvTerms!=NULL)
	{
		dnv=*dnvTerms;
		delete dnvTerms;
	}

	Term *dn=new Term(s, dnv);
	Predicate *p=new Predicate(dn, bNot);

	return p;
}

bool PredicateFactory::isFullyInstantiated(PredicateVector *pvPredicates)
{
	if(pvPredicates==NULL)
		return true;

	for(PredicateVector::iterator i= pvPredicates->begin(); i!=pvPredicates->end(); i++)
	{
		Predicate *p=*i;
		TermVector tv=p->getTerms();
		for(TermVector::iterator j=tv.begin(); j!=tv.end(); j++)
		{
			Term *t=*j;
			if(t->isVariable() && (t->getBinding() == t))
				return false;
		}
	}

	return true;
}