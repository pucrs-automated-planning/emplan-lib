// GroundPlan.h: interface for the GroundPlan class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_GROUNDPLAN_H__551E02B8_7A70_44A4_9051_3DB31839865D__INCLUDED_)
#define AFX_GROUNDPLAN_H__551E02B8_7A70_44A4_9051_3DB31839865D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <string>
using std::string;

#include <sstream>
using std::ostringstream;

#include "OperatorInstance.h"

//////////////////////////////////////////////////////////////////////
// Represents a plan comprised of ground terms
//////////////////////////////////////////////////////////////////////
class GroundPlan
{
public:
	GroundPlan();
	virtual ~GroundPlan();

	//Returns the plan as a vector of operator instances
	virtual OperatorInstanceVector toVector();

	virtual string toString(OperatorInstanceVector &oiv);
	//Prints a string representation of the plan
	virtual string toString();
};

#endif // !defined(AFX_GROUNDPLAN_H__551E02B8_7A70_44A4_9051_3DB31839865D__INCLUDED_)
