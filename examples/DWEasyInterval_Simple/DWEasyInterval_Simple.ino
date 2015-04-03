#include "DWEasyInterval.h"

DWEasyInterval interval;

void setup()
{
	pinMode(13,OUTPUT);
	digitalWrite(13,false);

	interval.setDelay(1000,2);
	interval.setFunction(ledOn);
	interval.start();
}
void loop()
{
	interval.loop();
}
void ledOn()
{
	digitalWrite(13,true);
	delay(500);
	digitalWrite(13,false);
}

