// TermInstance.h: interface for the TermInstance class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TERMINSTANCE_H__55EDF537_C7F5_4769_9BBB_D5A45AE4C3BA__INCLUDED_)
#define AFX_TERMINSTANCE_H__55EDF537_C7F5_4769_9BBB_D5A45AE4C3BA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <string>
using std::string;

#include <vector>
using std::string;

#include "Term.h"

class TermInstance
{
protected:
	string sName;
public:
	TermInstance();
	TermInstance(string sName);
	virtual ~TermInstance();

	bool operator==(TermInstance &tRight);
	TermInstance & operator=(TermInstance &tRight);

	string getKey();
	string toString();

	static string getKey(Term *t);
};

typedef vector<TermInstance *> TermInstanceVector;

#endif // !defined(AFX_TERMINSTANCE_H__55EDF537_C7F5_4769_9BBB_D5A45AE4C3BA__INCLUDED_)
