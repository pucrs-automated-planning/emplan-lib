// Starter.h: interface for the Starter class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_STARTER_H__46AD0FEE_F352_4DAC_AF3A_84BF07495859__INCLUDED_)
#define AFX_STARTER_H__46AD0FEE_F352_4DAC_AF3A_84BF07495859__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Debug.h"
#include "Consoleout.h"

#include <iostream>
using std::cout;
using std::cerr;
using std::endl;

using std::istream;
using std::ostream;

#include <fstream>
using std::ifstream;
using std::ofstream;

#include "CommandLineOptions.h"
#include "OperatorParserProxy.h"
#include "GroundDataTable.h"
#include "GraphplanPlanner.h"
#include "PopPlanner.h"

#include "TimeTracker.h"

class Starter  
{
protected:
	CommandLineOptions options;

	bool runGraphplan(PredicateInstanceVector &pivStart, 
				  PredicateInstanceVector &pivGoal, 
				  OperatorInstanceVector &oivOperators);
				  
	bool runGraphplan(PredicateInstanceVector &pivStart, 
				  PredicateInstanceVector &pivGoal, 
				  OperatorInstanceVector &oivOperators,
				  ostream &output);
	
	bool runPopPlanner(PredicateVector &pvStart,
					PredicateVector &pvGoal,
					OperatorVector &ovOperators);
public:
	Starter();
	Starter(CommandLineOptions &options);
	virtual ~Starter();

	virtual int start();
	//A stream based start method, to avoid using files directly
	virtual int start(istream &input, ostream &output);

	virtual Starter &operator=(Starter &sRight);
};

#endif // !defined(AFX_STARTER_H__46AD0FEE_F352_4DAC_AF3A_84BF07495859__INCLUDED_)
