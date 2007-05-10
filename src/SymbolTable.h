// SymbolTable.h: interface for the SymbolTable class.
//
//////////////////////////////////////////////////////////////////////

#ifndef SYMBOLTABLE_H
#define SYMBOLTABLE_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <string>
using std::string;
#include <map>
using std::map;
using std::less;

#include "TermSignature.h"
#include "PredicateSignature.h"
#include "OperatorSignature.h"
#include "Debug.h"

typedef map<string, TermSignature *, less<string> > TermSignatureMap;
typedef map<string, PredicateSignature *, less<string> > PredicateSignatureMap;
typedef map<string, OperatorSignature *, less<string> > OperatorSignatureMap;

class SymbolTable  
{
protected:
	TermSignatureMap tsmTerms;
	PredicateSignatureMap psmPredicates;
	OperatorSignatureMap osmOperators;
public:
	void registerOperator(Operator *o);
	void registerPredicate(Predicate *p);
	void registerTerm(Term *t);
	string toString();
	SymbolTable();
	virtual ~SymbolTable();

	TermSignatureMap getTermSignatures();
	PredicateSignatureMap getPredicateSignatures();
	OperatorSignatureMap getOperatorSignatures();
};

#endif // !defined(AFX_SYMBOLTABLE_H__86B0B0B8_75C8_44BB_8D5A_9C2B734F0742__INCLUDED_)
