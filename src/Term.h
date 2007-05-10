// Term.h: interface for the Term class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_Term_H__3EAEC4EE_B806_402B_A624_ACD810143A38__INCLUDED_)
#define AFX_Term_H__3EAEC4EE_B806_402B_A624_ACD810143A38__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <vector>
using std::vector;

#include <map>
using std::map;
using std::less;

#include <string>
using std::string;

#include "Debug.h"

class Term  
{
	typedef map<string, Term *, less<string> > TermMap;
	typedef vector<Term *> TermVector;
private:
	TermMap *dnmVariables;//To store references to variables
protected:
	Term * getVariable(Term *dnVar);
	string sName;
	bool bVariable;//To denote that the current node is a variable
	bool bFunction;//To denote that the current node is a function i.e. dnvTerms!=NULL
	Term *dnBinding;//Pointer to bound term if this is a variable
	TermVector dnvTerms;//The child terms if this is a function
public:
	
	Term(const string &sName, bool bVar=false);
	Term(const string &sName, TermVector dnvTerms);
	Term(Term *dn, TermMap *dnmVariables);
	string getName();
	bool isFunction();
	bool isVariable();
	bool bind(Term *dn);
	bool occur(Term *dn);
	virtual ~Term();
	int getArity();
	Term * getBinding();
	TermVector getTerms();

	bool operator ==(const Term &dn);
	void unbind();

	string toString();
};

typedef map<string, Term *, less<string> > TermMap;
typedef vector<Term *> TermVector;

#endif // !defined(AFX_Term_H__3EAEC4EE_B806_402B_A624_ACD810143A38__INCLUDED_)
