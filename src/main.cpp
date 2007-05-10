#include "Debug.h"
#include "Consoleout.h"

#include <iostream>
using std::cout;
using std::cerr;
using std::endl;

#include <fstream>
using std::ifstream;
using std::ofstream;

#include "Starter.h"
#include "TimeTracker.h"

int main(int argc, char *argv[])
{
	cout << "Embedded Planner version 1.0\n";

	//Parse the command line arguments
	CommandLineOptions options(argc, argv);
	
	if(!options.parseSuccessfull())
	{
		string sProgname=argv[0];
		options.printCommandLineOptions(sProgname);
		exit(1);
	}

	
	Starter s(options);
	int iRes=s.start();

	WRITELN("");

	return iRes;
}