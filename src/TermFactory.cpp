// TermFactory.cpp: implementation of the TermFactory class.
//
//////////////////////////////////////////////////////////////////////

#include "TermFactory.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

TermFactory::TermFactory()
{

}

TermFactory::~TermFactory()
{

}

Term * TermFactory::newTerm(const string &sName, bool bVar)
{
	return new Term(sName, bVar);
}

Term * TermFactory::newTerm(const string &sName, TermVector dnvTerms)
{
	return new Term(sName, dnvTerms);
}
