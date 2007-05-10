// OperatorSignature.h: interface for the OperatorSignature class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_OPERATORSIGNATURE_H__7E865286_1846_4564_8BA0_D747DD8DC345__INCLUDED_)
#define AFX_OPERATORSIGNATURE_H__7E865286_1846_4564_8BA0_D747DD8DC345__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Signature.h"
#include "Operator.h"
#include "Predicate.h"
#include "Term.h"

#include <sstream>
using std::ostringstream;

class OperatorSignature : public Signature  
{
protected:
	Operator *oSignature;
public:
	OperatorSignature();
	OperatorSignature(Operator *o);
	virtual ~OperatorSignature();
	
	static string getSignature(Operator *o);

	OperatorSignature & operator=(OperatorSignature &oRight);

	Operator *getOperator();

	virtual string toString();
};

#endif // !defined(AFX_OPERATORSIGNATURE_H__7E865286_1846_4564_8BA0_D747DD8DC345__INCLUDED_)
