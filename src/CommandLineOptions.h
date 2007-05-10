// CommandLineOptions.h: interface for the CommandLineOptions class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_COMMANDLINEOPTIONS_H__25E4F07B_C570_4F59_8E14_D8E2E3C6B32D__INCLUDED_)
#define AFX_COMMANDLINEOPTIONS_H__25E4F07B_C570_4F59_8E14_D8E2E3C6B32D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Debug.h"
#include "Consoleout.h"

#include <string>
using std::string;

#include <iostream>
using std::cout;
using std::cerr;
using std::endl;

class CommandLineOptions  
{
protected:
	bool bParseSuccessfull;

	bool parseOptions(int argc, char *argv[]);
	void setDefaults();
public:

	static const int GRAPHPLAN;
	static const int POP;

	//The name of the file containing the planning problem
	string sInputFile;
	//Whether or not write the plan down to a file
	bool bWritePlan;
	//The name of the file where the plan will be written to
	string sOutputFile;
	//Whether to write the resulting plan into the screen or not
	bool bScreenPlan;
	//Whether to write the ground terms, predicates and operators (i.e. Herbrand Universe) into a file
	bool bWriteGrounds;
	//The file name where the grounds will be written to
	string sGrounds;
	//Whether to generate and write the planning statistics to a file
	bool bWriteStats;
	//The file name where the statistics will be written to
	string sStatistics;
	//If using grahplan, whether to draw the resulting planning graph to a file
	bool bDrawGraph;
	//The file where the planning graph will be written to
	string sDrawGraphFile;
	//If using graphplan, whether to use memoization or not
	bool bUseMemoization;

	//The number of times to run the same planning problem to gather time statistics
	int iPlanRuns;
	//Whether or not to write final run times to a file
	bool bWriteRuns;
	//The filename where these times should be written to
	string sPlanRunsFile;

	//The planner selected for execution
	int iPlanner;

	CommandLineOptions();
	CommandLineOptions(int iArgc, char *sArgv[]);
	virtual ~CommandLineOptions();

	bool parseSuccessfull();

	void printCommandLineOptions(string sProgname);
	void printCommandLineError(string sError);

	int selectPlanner(string sPlanner);

	CommandLineOptions &operator=(CommandLineOptions &cloRight);
};

#endif // !defined(AFX_COMMANDLINEOPTIONS_H__25E4F07B_C570_4F59_8E14_D8E2E3C6B32D__INCLUDED_)
