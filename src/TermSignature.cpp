// TermSignature.cpp: implementation of the TermSignature class.
//
//////////////////////////////////////////////////////////////////////

#include "TermSignature.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

TermSignature::TermSignature()
{
	this->tSignature=NULL;
}

TermSignature::TermSignature(Term *t):Signature()
{
	assert(t!=NULL);
	this->sName=TermSignature::getSignature(t);
	this->tSignature=new Term(t->getName());
}

TermSignature::~TermSignature()
{

}

string TermSignature::toString()
{
	return this->sName;
}

Term *TermSignature::getTerm()
{
	return this->tSignature;
}

TermSignature & TermSignature::operator=(TermSignature &tRight)
{
	if(this!=&tRight)
	{
		this->sName=tRight.sName;
		this->iId=tRight.iId;
		this->tSignature=tRight.tSignature;
		assert(tSignature != NULL);
	}

	return *this;
}

string TermSignature::getSignature(Term *t)
{
	assert(t!=NULL);
	return t->getName();
}