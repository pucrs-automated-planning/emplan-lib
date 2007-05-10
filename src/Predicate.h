// Predicate.h: interface for the Predicate class.
//
//////////////////////////////////////////////////////////////////////

#if !defined PREDICATE_H
#define PREDICATE_H

#include <vector>
using std::vector;

#include <deque>
using std::deque;

#include <string>
using std::string;

#include "Term.h"
#include "Debug.h"

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class Predicate  
{
protected:
	Term *dnPredicate;
	TermMap *dnmVariables;
	bool bNot;
public:
	Predicate();
	Predicate(Predicate *p, TermMap *dnmVariables);
	Predicate(Term *dnPredicate, bool bNot=false);
	Predicate(Term *dnPredicate, TermMap *dnmVariables, bool bNot=false);

	bool isNegative();
	Term * getTerm();
	virtual ~Predicate();

	const Predicate &operator =(const Predicate &pRight);
	const bool operator ==(const Predicate &pRight);

	void flip();

	const TermVector getTerms();
	int getArity();
	string getName();

	TermMap *getVariables();

	virtual string toString();

	void unbind();
};

typedef vector<Predicate *> PredicateVector;
typedef PredicateVector::iterator PredicateVectorIterator;

#endif // !defined(PREDICATE_H)
