// PredicateSignature.cpp: implementation of the PredicateSignature class.
//
//////////////////////////////////////////////////////////////////////

#include "PredicateSignature.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

PredicateSignature::PredicateSignature()
{
	this->pSignature=NULL;
}

PredicateSignature::PredicateSignature(Predicate *p):Signature()
{
	this->pSignature=PredicateSignature::makeSignaturePredicate(p->getName(), p->getArity());
	this->sName=PredicateSignature::getSignature(pSignature);
}

PredicateSignature::~PredicateSignature()
{
	delete pSignature;
}

Predicate *PredicateSignature::getPredicate()
{
	return this->pSignature;
}

string PredicateSignature::toString()
{
	return this->sName;
}

string PredicateSignature::getSignature(Predicate *p)
{
	ostringstream out;
	out << p->getName();
	out << "/";
	out << p->getArity();

	return out.str();
}

PredicateSignature & PredicateSignature::operator=(PredicateSignature &pRight)
{
	if(this!=&pRight)
	{
		this->sName=pRight.sName;
		this->iId=pRight.iId;
		this->pSignature=pRight.pSignature;
	}

	return *this;
}

Predicate *PredicateSignature::makeSignaturePredicate(string sName, int iArity)
{
	TermVector tvTerms;
	tvTerms.resize(iArity);
	string sVarBase="A";

	for(int i=0; i<iArity; i++)
	{
		ostringstream out;
		out<<sVarBase<<i;
		
		//Create a variable
		Term *t=new Term(out.str(), true);
		tvTerms[i]=t;
	}

	Term *t=new Term(sName, tvTerms);
	Predicate *p=new Predicate(t);

	return p;
}