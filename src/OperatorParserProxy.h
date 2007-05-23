// OperatorParserProxy.h: interface for the OperatorParserProxy class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_OPERATORPARSERPROXY_H__439AC185_545F_4213_8F3D_58BBB00D3F70__INCLUDED_)
#define AFX_OPERATORPARSERPROXY_H__439AC185_545F_4213_8F3D_58BBB00D3F70__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Debug.h"
#include "Consoleout.h"

#include <iostream>
using std::cin;
using std::cerr;
using std::istream;

#include <string>
using std::string;

#include <fstream>
using std::ifstream;

#include "OperatorParser.h"
#include "OperatorLexer.h"

//The OperatorParserProxy is a frontend to whatever parser you may be trying to use
//to parse the input language
class OperatorParserProxy  
{
protected:
	bool bStartUp;
	int n;
	OperatorLexer lexer;
	OperatorParser parser;
public:
	OperatorParserProxy();
	virtual ~OperatorParserProxy();

	//Parses the file given as input and returns if it has been sucessfull
	bool parse(string sFilename);
	bool parse(istream &input);

	//Returns 
	PredicateVector getStart();
	PredicateVector getGoal();
	OperatorVector getOperators();
	SymbolTable *getSymbolTable();

	string toString();
};

#endif // !defined(AFX_OPERATORPARSERPROXY_H__439AC185_545F_4213_8F3D_58BBB00D3F70__INCLUDED_)
