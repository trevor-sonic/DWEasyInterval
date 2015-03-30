/*
 * DWEasyInterval.h
 *
 *  Created on: 24 Mar 2015
 *      Author: dejaworks
 */

#ifndef DWEASYINTERVAL_H_
#define DWEASYINTERVAL_H_
#include "Arduino.h"
//-----------------------------------------------
typedef void (*functionPointer)(void);
//-----------------------------------------------
class DWEasyInterval {
public:
	DWEasyInterval();
	virtual ~DWEasyInterval();

	void setFunction        ( functionPointer theFunction);
	void setDelay			(unsigned long delay, unsigned int times);
	void stop();
	void start();
	void restart();
	void loop();

private:
	bool			_running;
	bool			_currStatus;
	bool 			_enable;

	unsigned int	_currTime;
	unsigned int	_times;
	unsigned long 	_lastMillis;
	unsigned long  	_delay;

    void        (*_functionHandler)    (void);
};

#endif /* DWEASYINTERVAL_H_ */
