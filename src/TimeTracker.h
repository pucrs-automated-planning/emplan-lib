// TimeTracker.h: interface for the TimeTracker class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TIMETRACKER_H__A96E0C6D_5FCC_4EE0_9424_C1EC8ABF5398__INCLUDED_)
#define AFX_TIMETRACKER_H__A96E0C6D_5FCC_4EE0_9424_C1EC8ABF5398__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

extern "C"{
	#include <time.h>
	#include <sys/timeb.h>
	#include <sys/types.h>
};

#include <string>
using std::string;

#include <sstream>
using std::ostringstream;

class TimeTracker  
{
protected:
#ifdef WIN32
	struct _timeb startTime;
	struct _timeb endTime;
#else
	struct timeb startTime;
	struct timeb endTime;
#endif

	long lSeconds;
	long lMilli;
public:
	TimeTracker();
	virtual ~TimeTracker();

	void stopTracker();
	void startTracker();

	long getElapsedSeconds();
	long getElapsedMilliseconds();
	double getElapsedTime();

	string toString();
};

#endif // !defined(AFX_TIMETRACKER_H__A96E0C6D_5FCC_4EE0_9424_C1EC8ABF5398__INCLUDED_)
