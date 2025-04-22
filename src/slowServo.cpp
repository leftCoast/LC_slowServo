#include <slowServo.h>


// Constructor, Lets have a pin number to play with.
slowServo::slowServo(int inPin,int startDeg) {
  
  servoPtr    = NULL;   	// We have no servo object yet.
  pin         = inPin;  	// Here's our pin number, save that.
  MsDelay     = 1;      	// set delay to a default of 1 Ms.
  currentDeg  = startDeg;	// set current degree to startDeg.
  desiredDeg  = startDeg;	// Assume these will be the same.
}

// Destructor, recycle the servo onbject.
slowServo::~slowServo(void) { if (servoPtr) delete(servoPtr); }

// Yes this servo thing needs a begin call.
void slowServo::begin(void) {

  if (!servoPtr) {                  // If servoPtr is NULL..
    servoPtr = new Servo;           // Create a new servo object.
    servoPtr->attach(pin);          // Do the attach pin thing.                       
    servoPtr->write(currentDeg);		// Set our start locaton.
    degTimer.setTime(MsDelay);      // Set our defualt delay time.
    hookup();                       // Hook us into the idle queue. (ignition ON!)
  }                                 // If we already have a servo object? Don't bother.
}


// Set a new speed. IE Ms delay per degree.
void slowServo::setMsPerDeg(int inMs) { MsDelay = inMs; }


// Set a new position. IE Degre rotation.
void slowServo::setDeg(int inDeg) { desiredDeg = inDeg; }


// Are we moving?
bool slowServo::moving(void) { return desiredDeg != currentDeg; } 


// Stop this nonsense. Entering a new position starts it again.
void slowServo::stop(void) { desiredDeg = currentDeg; }


// Run the machine. This gets called automatically by the
// idle(); command in your sketch's loop. It will NOT be
// called if begin is not called to set things up beforehand.
void slowServo::idle(void) {

  if (moving() && degTimer.ding()) {
    if (currentDeg>desiredDeg) {
      currentDeg--;
    } else {
      currentDeg++;
    }
    servoPtr->write(currentDeg);
    degTimer.setTime(MsDelay,true);
  }
}