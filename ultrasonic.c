#include <stdio.h>
#include <wiringPi.h>
#include <stdlib.h>


#define TRIG 0
#define ECHO 2

int main(void){

	wiringPiSetup();
	pinMode(TRIG, OUTPUT);
	pinMode(ECHO, INPUT);

	digitalWrite(TRIG, LOW);
	delay(2);

	digitalWrite(TRIG, HIGH);
	delay(0.00001);
	digitalWrite(TRIG, LOW);

	long TimeElapsed;
        int  distance;

	while(digitalRead(ECHO) == LOW);
   	long StartTime = micros();

	while(digitalRead(ECHO) == HIGH);
	long StopTime = micros();

	TimeElapsed = StopTime - StartTime;
	distance = (TimeElapsed  * 34300)/(2 * 1000000); // TimeElapsed is in micro sec and 34300 is ultrasonic speer. We devide it by to because the signals has to trave to the object  and come back.

	printf("Distance: %1d cm \n", distance);
	return 0;

}







