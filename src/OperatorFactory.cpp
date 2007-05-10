// OperatorFactory.cpp: implementation of the OperatorFactory class.
//
//////////////////////////////////////////////////////////////////////

#include "OperatorFactory.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

OperatorFactory::OperatorFactory()
{

}

OperatorFactory::~OperatorFactory()
{

}

//////////////////////////////////////////////////////////////////////
// Constructs a new Operator object
//////////////////////////////////////////////////////////////////////
Operator * OperatorFactory::newOperator(const string &sOperator, TermVector *dnvParams, PredicateVector *pvPreconds, PredicateVector *pvEffects)
{
	TermVector dnv;
	PredicateVector pvPre, pvEff;

	if(dnvParams!=NULL)
		dnv=*dnvParams;

	if(pvPreconds!=NULL)
		pvPre=*pvPreconds;

	if(pvEffects!=NULL)
		pvEff=*pvEffects;

	return new Operator(sOperator, dnv, pvPre, pvEff, true, true);
}

//////////////////////////////////////////////////////////////////////
// Verifies that the operator has been correctly constructed,
//that is, that the preconditions or effects do not use variables
//that were not declared in the operator's parameters
//////////////////////////////////////////////////////////////////////
bool OperatorFactory::checkOperator(const string &sOperator, TermVector *dnvParams, PredicateVector *pvPreconds, PredicateVector *pvEffects)
{
	TermMap tmVariables;
	
	TermVector tvPar;
	PredicateVector pvPre, pvEff;

	if(dnvParams!=NULL)
		tvPar=*dnvParams;
	if(pvPreconds!=NULL)
		pvPre=*pvPreconds;
	if(pvEffects!=NULL)
		pvEff=*pvEffects;


	for(TermVector::iterator i=tvPar.begin(); i!=tvPar.end(); i++)
	{
		Term *dn=*i;;
		tmVariables[dn->getName()]=dn;
	}

	for(PredicateVector::iterator i2=pvPre.begin(); i2!=pvPre.end(); i2++)
	{
		Predicate *p=*i2;
		TermVector tv=p->getTerms();

		for(TermVector::iterator i=tv.begin(); i!=tv.end(); i++)
		{
			Term *t=*i;
			if(t->isVariable() && (tmVariables.find(t->getName())==tmVariables.end()))
				return false;
		}
	}

	for(PredicateVector::iterator i2=pvEff.begin(); i2!=pvEff.end(); i2++)
	{
		Predicate *p=*i2;
		TermVector tv=p->getTerms();

		for(TermVector::iterator i=tv.begin(); i!=tv.end(); i++)
		{
			Term *t=*i;
			if(t->isVariable() && (tmVariables.find(t->getName())==tmVariables.end()))
				return false;
		}
	}
	return true;
}