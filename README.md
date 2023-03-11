# LC_slowServo

So you want to set your servo speed, and trying that with delay() is making everything else in your code stop?
Here's the solution.

1) Make sure LC_baseTools is installed on your machine using the Arduino Library manager.
2) In your sketch add the line.. #include <slowServo.h>
3) Instead of creating standard Arduino servo objects for your sketch, create slowServos. And when yuo create a slow servo you need to give it a pin number. For example : slowServo myServo(2);
4) In your setup(); function, instead of calling attach(2); you will just call begin();. It will do the attach thing for you.
5) In your loop(); function, add the line idle(); to the top. This runs everything that wants to be run in the background. Like these servos.
6) To set a position, call the method setDeg(angle);. Your servo will begin to move to that position.
7) To set speed, call the method setMsPerDeg(Ms); Your servo will delay this much time per degree movement. IE 0 means full blast.
8) WARNING!!! DO NOT USE delay(); FOR ANYTHING! This WILL stop everything, no matter what. Replace your delay(); calls with sleep(); calls. This stops your main loop, but keeps the servos and everything else that runs in the background, running.

That's all there is to it.
