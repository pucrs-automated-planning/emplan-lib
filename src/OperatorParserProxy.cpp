// OperatorParserProxy.cpp: implementation of the OperatorParserProxy class.
//
//////////////////////////////////////////////////////////////////////

#include "OperatorParserProxy.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

OperatorParserProxy::OperatorParserProxy()
{
	if (parser.yycreate(&lexer) && parser.setSymbolTable(lexer.getSymbolTable())) {
		if (lexer.yycreate(&parser) && lexer.yyin!=NULL) {
			this->bStartUp=true;
			//n = parser.yyparse();
			//while(lexer.yylex()!=0);
		}else
			this->bStartUp=false;
	}else
		this->bStartUp=false;
}

OperatorParserProxy::~OperatorParserProxy()
{

}


bool OperatorParserProxy::parse(string sFilename)
{
	if(bStartUp)
	{
		ifstream *yyin=new ifstream(sFilename.c_str());
		//FILE *yyin = fopen(sFilename.c_str(),"r");
		if(!yyin->fail())
		//if(yyin)
		{
			lexer.yyin=yyin;
			PRINTL("Teste 1")
			n = parser.yyparse();
			//lexer.yyin=&cin;
			//fclose(yyin);
			yyin->close();
		}else
		{
			WRITELN("Cannot open file: \""<< sFilename << "\".");
			n = YYEXIT_FAILURE;
		}
		//delete yyin;
	}
	else
	{
		cerr << "Error initializing parser" << endl;
		return false;
	}

	if(n==YYEXIT_SUCCESS)
	{
		WRITELN("Parse Process Complete");
		//Do planning now
		return true;
	}else
		return false;
}

//A helper method that reads the problem from any stream
//This replication of code is nasty, and I will go to hell
//because of it, but at least I will have the results for
//a paper
bool OperatorParserProxy::parse(istream &input) {
	
	if(bStartUp) {
		lexer.yyin=&input;
		PRINTL("Teste 1")
		n = parser.yyparse();
	} else {
		cerr << "Error initializing parser" << endl;
		return false;
	}

	if(n==YYEXIT_SUCCESS)
	{
		WRITELN("Parse Process Complete");
		//Do planning now
		return true;
	}else
		return false;
}

PredicateVector OperatorParserProxy::getStart()
{
	return *parser.getStart();
}

PredicateVector OperatorParserProxy::getGoal()
{
	return *parser.getGoal();
}

OperatorVector OperatorParserProxy::getOperators()
{
	return *parser.getOperators();
}

SymbolTable *OperatorParserProxy::getSymbolTable()
{
	return lexer.yyst;
}

string OperatorParserProxy::toString()
{
	string sRes;

	sRes+=lexer.version+"\n";
	sRes+=parser.version+"\n";

	return sRes;
}
