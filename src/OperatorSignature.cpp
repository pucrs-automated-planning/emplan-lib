// OperatorSignature.cpp: implementation of the OperatorSignature class.
//
//////////////////////////////////////////////////////////////////////

#include "OperatorSignature.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

OperatorSignature::OperatorSignature()
{
	this->oSignature=NULL;
}

OperatorSignature::OperatorSignature(Operator *o):Signature()
{
	this->oSignature=new Operator(o);
	this->sName=OperatorSignature::getSignature(oSignature);
}

OperatorSignature::~OperatorSignature()
{
	delete oSignature;
}

Operator *OperatorSignature::getOperator()
{
	return this->oSignature;
}

string OperatorSignature::toString()
{
	return this->sName;
}

OperatorSignature & OperatorSignature::operator=(OperatorSignature &oRight)
{
	if(this!=&oRight)
	{
		this->sName=oRight.sName;
		this->iId=oRight.iId;
		this->oSignature=oRight.oSignature;
	}

	return *this;
}

//This method exists so that the SymbolTable can grab the signature of an
//operator without the need for instantiating a new signature
string OperatorSignature::getSignature(Operator *o)
{
	ostringstream out;

	out << o->getName();

	out << "/";

	out << o->getArity();

	return out.str();
}