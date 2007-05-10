// TermInstance.cpp: implementation of the TermInstance class.
//
//////////////////////////////////////////////////////////////////////

#include "TermInstance.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

TermInstance::TermInstance()
{

}

TermInstance::TermInstance(string sName)
{
	this->sName=sName;
}

TermInstance::~TermInstance()
{

}

bool TermInstance::operator==(TermInstance &tRight)
{
	if(this!=&tRight)
	{
		return this->sName==tRight.sName;
	}else
		return true;
}

TermInstance & TermInstance::operator=(TermInstance &tRight)
{
	if(this!=&tRight)
	{
		this->sName=tRight.sName;
	}

	return *this;
}

string TermInstance::getKey()
{
	return sName;
}

string TermInstance::toString()
{
	return this->sName;
}


string TermInstance::getKey(Term *t)
{
	if(t!=NULL)
	{
		t=t->getBinding();
		return t->getName();
	}else
		return "";
}