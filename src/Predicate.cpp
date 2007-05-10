// Predicate.cpp: implementation of the Predicate class.
//
//////////////////////////////////////////////////////////////////////

#include "Predicate.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Predicate::Predicate()
{
	this->dnPredicate=NULL;
	this->dnmVariables=NULL;
}

Predicate::~Predicate()
{
	delete dnPredicate;
}

Predicate::Predicate(Term *dnPredicate, bool bNot)
{
	this->dnPredicate=dnPredicate;
	this->dnmVariables=NULL;
	this->bNot=bNot;
}

Predicate::Predicate(Term *dnPredicate, TermMap *dnmVariables, bool bNot)
{
	this->dnPredicate=dnPredicate;
	this->dnmVariables=dnmVariables;
	this->bNot=bNot;
}


const Predicate &Predicate::operator =(const Predicate &pRight)
{
	if(this != &pRight)
	{
		this->dnPredicate=pRight.dnPredicate;
		this->dnmVariables=dnmVariables;
	}

	return *this;
}

const bool Predicate::operator ==(const Predicate &pRight)
{
	bool bRes=true;
	if(this != &pRight)
	{
		bRes &= (this->dnPredicate == pRight.dnPredicate);
	}else
		bRes=true;
	return bRes;
}

void Predicate::flip()
{
	this->bNot=!bNot;
}

const TermVector Predicate::getTerms()
{
	return this->dnPredicate->getTerms();
}

string Predicate::getName()
{
	return this->dnPredicate->getName();
}

int Predicate::getArity()
{
	return this->dnPredicate->getArity();
}

Term * Predicate::getTerm()
{
	return this->dnPredicate;
}

bool Predicate::isNegative()
{
	return this->bNot;
}

TermMap *Predicate::getVariables()
{
	return this->dnmVariables;
}

Predicate::Predicate(Predicate *p, TermMap *dnmVariables)
{
	this->bNot=p->bNot;
	this->dnmVariables=dnmVariables;
	this->dnPredicate=new Term(p->getTerm(), dnmVariables);
}

string Predicate::toString()
{
	string sRes="[(Predicate)";

	sRes+=this->dnPredicate->toString();

	sRes+="]";

	return sRes;
}


void Predicate::unbind()
{
	TermVector tvTerms=dnPredicate->getTerms();
	for(TermVector::iterator i=tvTerms.begin(); i!=tvTerms.end(); i++)
	{
		(*i)->unbind();
	}
}