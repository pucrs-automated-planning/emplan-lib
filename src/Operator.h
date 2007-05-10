// Operator.h: interface for the Operator class.
//
//////////////////////////////////////////////////////////////////////

#if !defined OPERATOR_H
#define OPERATOR_H

#include <vector>
using std::vector;

#include <deque>
using std::deque;

#include <string>
using std::string;

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Predicate.h"
#include "Debug.h"

class Operator  
{
protected:
	TermVector dnvParams;
	PredicateVector pvEffects;
	PredicateVector pvPreconds;
	string sName;
	TermMap *dnmVariables;

	Term *getVariable(Term *dgVar);
public:
	Operator(Operator *o, bool bPruneOld=false);
	Operator(const string &sName, TermVector dnvParams, PredicateVector pvPreconds, PredicateVector pvEffects, bool bMapVariables=true, bool bPrune=true);
	Operator();
	TermVector getParameters();
	PredicateVector getEffects();
	PredicateVector getPreconds();
	virtual string toString();
	virtual string toHeaderString();
	virtual ~Operator();
	const Operator &operator=(const Operator &oRight);
	bool isFullyInstantiated();
	bool isNotInstantiated();
	bool threatened(Predicate *pThreat);
	string getName();
	int getArity();
	void unbind();
private:
	void init(const string &sName, TermVector dnvParams, PredicateVector pvPreconds, PredicateVector pvEffects, bool bMapVariables, bool bPruneOld);
};

typedef vector<Operator*> OperatorVector;
typedef OperatorVector::iterator OperatorVectorIterator;

#endif // !defined(OPERATOR_H)
