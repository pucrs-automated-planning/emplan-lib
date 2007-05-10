// GroundDataTable.h: interface for the GroundDataTable class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_GROUNDDATATABLE_H__CB24BF6E_C678_434F_99ED_6E2D4B76E3BC__INCLUDED_)
#define AFX_GROUNDDATATABLE_H__CB24BF6E_C678_434F_99ED_6E2D4B76E3BC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <vector>
using std::vector;

#include <string>
using std::string;

#include <sstream>
using std::ostringstream;

#include <map>
using std::map;
using std::less;

#include "OperatorInstance.h"
#include "PredicateInstance.h"
#include "TermInstance.h"

#include "TermSignature.h"
#include "PredicateSignature.h"
#include "OperatorSignature.h"
#include "Debug.h"

typedef map<string , TermSignature *, less<string> > TermSignatureMap;
typedef map<string , PredicateSignature *, less<string> > PredicateSignatureMap;
typedef map<string , OperatorSignature *, less<string> > OperatorSignatureMap;

typedef map<string, TermInstance *, less<string> > TermInstanceMap;
typedef map<string, PredicateInstance *, less<string> > PredicateInstanceMap;
typedef map<string, OperatorInstance *, less<string> > OperatorInstanceMap;

typedef vector<TermSignatureMap::iterator> TSMIterator;

class GroundDataTable  
{
protected:
	TermInstanceMap timTerms;
	PredicateInstanceMap pimPredicates;
	OperatorInstanceMap oimOperators;

	void createTermInstances(TermSignatureMap &tsm);
	void createPredicateInstances(TermSignatureMap &tsm, PredicateSignatureMap &psm);
	void createOperatorInstances(TermSignatureMap &tsm, OperatorSignatureMap &osm);
	void createMaintenanceOperators();

	void initializeIterators(TermSignatureMap &tsm, TSMIterator &iv);
	bool iteratorsFinished(TermSignatureMap &tsm, TSMIterator &iv);
	bool advanceIterators(TermSignatureMap &tsm, TSMIterator &iv);
	void bindVariables(TermVector &tv, TSMIterator &iv);
public:
	GroundDataTable();
	GroundDataTable(TermSignatureMap &tsm, PredicateSignatureMap &psm, OperatorSignatureMap &osm);
	
	virtual ~GroundDataTable();

	TermInstance *addTermInstance(Term *t);
	PredicateInstance *addPredicateInstance(Predicate *p);
	OperatorInstance *addOperatorInstance(Operator *o);

	TermInstance *getTermInstance(string sKey);
	PredicateInstance *getPredicateInstance(string sKey);
	OperatorInstance *getOperatorInstance(string sKey);

	PredicateInstanceVector convertPredicates(PredicateVector pv);
	OperatorInstanceVector getOperators();

	string toString();
};

#endif // !defined(AFX_GROUNDDATATABLE_H__CB24BF6E_C678_434F_99ED_6E2D4B76E3BC__INCLUDED_)
