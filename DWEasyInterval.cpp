/*
 * DWEasyInterval.cpp
 *
 *  Created on: 24 Mar 2015
 *      Author: dejaworks
 */

#include "DWEasyInterval.h"

DWEasyInterval::DWEasyInterval()
{
	_delay		=	500;
	_lastMillis	=	millis();
	_running	=	false;
	_enable		=	true;

	(void*)_functionHandler;


}
DWEasyInterval::~DWEasyInterval()
{
	// TODO Auto-generated destructor stub
}
void DWEasyInterval::start()
{
	_lastMillis	=	millis();
	_running	=	true;
	_currStatus	=	false;
	_currTime	=	_times;
}
void DWEasyInterval::stop()
{
	_running	=	false;
}
void DWEasyInterval::restart()
{
	stop();
	start();
}
void DWEasyInterval::loop()
{
    if ( _running && _enable && _functionHandler && (_currTime>0 || _times==0) && (millis() >= _lastMillis + _delay) )
    {
    	_lastMillis	=	millis();
		if(_currTime>0)_currTime--;

		_functionHandler();
    }
}
void DWEasyInterval::setDelay(unsigned long delay, unsigned int times)
{
	_delay				=	delay;
	_times				=	times;
}
void DWEasyInterval::setFunction(functionPointer theFunction)
{
	_functionHandler	=   theFunction;
}
