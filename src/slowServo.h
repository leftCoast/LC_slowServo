#ifndef slowServo_h
#define slowServo_h

#ifdef ESP32 || ESP8266		// If using ESP.. ESP use different servo library.
#include <ESP32Servo.h>		// Their library. Same calls.
#else								// else..
#include <Servo.h>			// Ususal Arduino stuff.
#endif							// ESP32

#include <idlers.h>
#include <timeObj.h>

// THIS CODE RELIES ON THE STANDARD ARDUINO Servo library.
// IT ALSO RELIES ON THE LC_baseTools library that can be
// installed using the Arduino library manager.


class	slowServo :	public idler {

	public:
				slowServo(int inPin,int startDeg=0);
	virtual	~slowServo(void);

				void  begin(void);
				void  setMsPerDeg(int inMs);
				void  setDeg(int inDeg);
				bool  moving(void);
				void	stop(void);
	virtual	void  idle();

				Servo*  servoPtr;
				timeObj degTimer;
				int     pin;
				int     MsDelay;
				int     currentDeg;
				int     desiredDeg;
};

#endif