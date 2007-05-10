// PredicateInstance.cpp: implementation of the PredicateInstance class.
//
//////////////////////////////////////////////////////////////////////

#include "PredicateInstance.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

PredicateInstance::PredicateInstance()
{

}

PredicateInstance::PredicateInstance(string sName, TermInstanceVector &tivTerms, bool bNot)
{
	this->sName=sName;
	this->tivTerms=tivTerms;
	this->bNot=bNot;
	this->sPredicate=this->makePredicate();
	if(bNot)
		this->sKey="-"+this->sPredicate;
	else
		this->sKey=this->sPredicate;
}

PredicateInstance::~PredicateInstance()
{

}

string PredicateInstance::makePredicate()
{
	string sRes;

	sRes+=sName;
	sRes+="(";
	for(TermInstanceVector::iterator i=tivTerms.begin(); i!=tivTerms.end(); i++)
	{
		if(i!=tivTerms.begin())
			sRes+=",";
		TermInstance *ti=*i;
		sRes+=ti->getKey();
	}
	sRes+=")";

	return sRes;
}

bool PredicateInstance::operator ==(PredicateInstance &piRight)
{
	if(this!=&piRight)
	{
		return this->sKey==piRight.sKey;
	}else
		return true;
}

PredicateInstance &PredicateInstance::operator=(PredicateInstance &piRight)
{
	if(this!=&piRight)
	{
		this->sName=piRight.sName;
		this->sKey=piRight.sKey;
		this->tivTerms=piRight.tivTerms;
	}
	return *this;
}

bool PredicateInstance::isMutex(PredicateInstance *pi)
{
	return (pi->sPredicate==this->sPredicate && this->bNot!=pi->bNot);
}

string PredicateInstance::getKey()
{
	return sKey;
}

string PredicateInstance::toString()
{
	return sKey;
}

string PredicateInstance::getKey(Predicate *p)
{
	string sRes;
	
	if(p!=NULL)
	{
		if(p->isNegative())
			sRes="-";

		sRes+=p->getName();
	
		sRes+="(";

		TermVector tv=p->getTerms();
		
		for(TermVector::iterator i=tv.begin(); i!=tv.end(); i++)
		{
			if(i!=tv.begin())
				sRes+=",";
			Term *t=*i;
			sRes+=TermInstance::getKey(t);
		}

		sRes+=")";
	}

	return sRes;
}