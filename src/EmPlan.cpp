#include "EmPlan.h"

#include "Starter.h"
#include "TimeTracker.h"

#include <sstream>
using std::istringstream;
using std::ostringstream;

#include <string>
using std::string;

JNIEXPORT jboolean JNICALL Java_org_meneguzzi_jemplan_EMPlan_emplan
	(JNIEnv *env, jobject obj, jstring sInputfile, jstring sOutputfile, 
	jstring sPlanner, jstring sStats, jstring sGrounds) {
		cout << "Embedded Planner version 1.0\n";
		
		CommandLineOptions options;
		options.iPlanner = CommandLineOptions::GRAPHPLAN;
		jboolean isCopy;
		options.sInputFile = env->GetStringUTFChars(sInputfile, &isCopy);
		
		options.sOutputFile = env->GetStringUTFChars(sOutputfile, &isCopy);
		if(!options.sOutputFile.empty()) {
			options.bWritePlan = true;
			options.bScreenPlan = false;
		}
		
		//cout << "Output file is " << options.sOutputFile << endl;
		
		options.sStatistics = env->GetStringUTFChars(sStats, &isCopy);
		if(!options.sStatistics.empty()) {
			options.bWriteStats = true;
		}
		
		options.sGrounds = env->GetStringUTFChars(sGrounds, &isCopy);
		if(!options.sGrounds.empty()) {
			options.bWriteGrounds = true;
		}
		
		Starter s(options);
		int iRes=s.start();
		
		if(!iRes) {
			return JNI_TRUE;
		} else {
			return JNI_FALSE;
		}
	}

JNIEXPORT jstring JNICALL Java_org_meneguzzi_jemplan_EMPlan_emplanStream
  (JNIEnv *env, jobject obj, jstring jsInput) {
  	CommandLineOptions options;
	options.iPlanner = CommandLineOptions::GRAPHPLAN;
	jboolean isCopy;
	options.bWritePlan = true;
	options.bScreenPlan = false;
	
 	istringstream input(env->GetStringUTFChars(jsInput, &isCopy));
 	ostringstream output;
 	
 	//WRITE("Input is " << input.str());
  	
  	Starter s(options);
  	int iRes = s.start(input, output);
  	
  	jstring jsOutput = NULL;
  	
  	if(!iRes) {
  		string s = output.str();
  		jsOutput = env->NewStringUTF(s.c_str());
  	}
  	
  	return jsOutput;
  }