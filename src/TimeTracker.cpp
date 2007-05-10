// TimeTracker.cpp: implementation of the TimeTracker class.
//
//////////////////////////////////////////////////////////////////////

#include "TimeTracker.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

TimeTracker::TimeTracker()
{

}

TimeTracker::~TimeTracker()
{

}

void TimeTracker::startTracker()
{
#ifdef WIN32
	_ftime(&startTime);
#else
	ftime(&startTime);
#endif
}

void TimeTracker::stopTracker()
{
#ifdef WIN32
	_ftime(&endTime);
#else
	ftime(&endTime);
#endif

	this->lSeconds=endTime.time - startTime.time;
	if(lSeconds!=0)
	{
		if(endTime.millitm >= startTime.millitm)
		{
			this->lMilli=endTime.millitm - startTime.millitm;
		}else
		{
			lSeconds--;
			this->lMilli=endTime.millitm + startTime.millitm;
			if(lMilli >= 1000)
			{
				lSeconds++;
				lMilli-=1000;
			}
		}
	}else
	{
		this->lMilli=endTime.millitm - startTime.millitm;
	}
}

long TimeTracker::getElapsedSeconds()
{
	return this->lSeconds;
}

long TimeTracker::getElapsedMilliseconds()
{
	return this->lMilli;
}

double TimeTracker::getElapsedTime()
{
	double dTime=this->lSeconds;
	dTime+=(this->lMilli/1000.0);

	return dTime;
}

string TimeTracker::toString()
{
	ostringstream sRes;

	sRes << this->lSeconds << ".";
	if(lMilli < 100)
		sRes << "0";
	if(lMilli < 10)
		sRes << "0";
	
	sRes << this->lMilli;
	sRes << "s";

	return sRes.str();
}