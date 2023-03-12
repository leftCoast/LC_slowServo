#include <slowServo.h>        // This gives you the slow servo stuff.
#include <serialStr.h>        // This gives you a easy way to get stuff from serial.


slowServo   aServo(2);        // Create a slow servo given a pin number.
serialStr   inStr;            // The Serial string reader.
int         newPos = 0;       // We're just going to do a sweep. This holds the next end.
bool        stopped;          // We can stop the servo, this tells this stuff that we stopped it.


void setup() {

   Serial.begin(57600);          // Fire up the Serial port.
   inStr.setCallback(gotStr);    // When we get a command, call this funtion.
   aServo.begin();               // You need to call begin on each servo.
   Serial.println("Enter a number say.. 0..30 that slows down the servo.");
   Serial.println("Enter a negitive number to stop the servo");
}            


// This is the funtion we call when something is typed into the serial monitor.
void gotStr(char* command) {

   int   newDelay;

   stopped = false;                       // Turn off the handbrake.
   newDelay = atoi(command);              // Take the command, assume its a number, grab that number.
   if (newDelay<0) {                      // If the number is negitive..
      aServo.stop();                      // Stop the servo.
      Serial.println("stopped");          // Tell Mrs user.
      stopped = true;                     // Crank on the handbrake. Stops the position stuff.
   } else {                               // Else we have a non-negitive value..
      Serial.print("setting delay to ");  // Tell the user.
      Serial.print(newDelay);
      Serial.println(" ms.");
      aServo.setMsPerDeg(newDelay);       // And we set the value into the servo.
   }
}


void loop() {
  
  idle();                              // idle(); must be called to run everything.
  if (!stopped && !aServo.moving()) {  // If its not stopped and the servo is not moving..
      if (newPos) {                    // If newPos is not zero.
         newPos = 0;                   // Make newPos zero.
      } else {                         // Else it was zero..
         newPos = 180;                 // Make it 180 deg.
      }
      aServo.setDeg(newPos);           // Set the new position to the servo.
  }
}