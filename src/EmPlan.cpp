#include "EmPlan.h"

#include "Starter.h"
#include "TimeTracker.h"

JNIEXPORT jboolean JNICALL Java_org_meneguzzi_jemplan_EMPlan_emplan
	(JNIEnv *env, jobject obj, jstring sInputfile, jstring sOutputfile, 
	jstring sPlanner, jstring sStats, jstring sGrounds) {
		cout << "Embedded Planner version 1.0\n";
		
		CommandLineOptions options;
		options.iPlanner = CommandLineOptions::GRAPHPLAN;
		//options.sInputFile = env->GetStringUTFChars(sInputfile, JNI_TRUE);
		
		Starter s(options);
		int iRes=s.start();
		
		if(iRes) {
			return JNI_TRUE;
		} else {
			return JNI_FALSE;
		}
	}

