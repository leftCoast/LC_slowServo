# LC_slowServo

So you want to set your servo speed, and trying that with delay() is making everything else in your code stop?
Here's the solution.

1) Make sure LC_baseTools as well as LC_slowServo are installed on your machine, **using the Arduino Library manager.**
2) In your sketch add the line.. #include <slowServo.h>
3) Instead of creating standard Arduino servo objects for your sketch, create slowServos. And when you create a slow servo, you need to give it a pin number. For example : slowServo myServo(2); NEW : You can add a start angle to this if you like.
4) In your setup(); function, call myServo.begin(); For each of your servos. This sets up your servos for use.
5) In your loop(); function, add the line idle(); to the top. This runs everything that wants to be run in the background. Like these servos.
6) To set a position, call the method myServo.setDeg(angle);. Your servo will begin to move to that position.
7) To set speed, call the method myServo.setMsPerDeg(Ms); Your servo will delay this much time per degree movement. IE 0 means full blast.
8) **WARNING!!! DO NOT USE delay(); FOR ANYTHING!** This WILL stop everything, no matter what. Replace your delay(); calls with sleep(); calls. This stops your main loop, but keeps the servos and everything else that runs in the background, running.
9) You can call myServo.moving(); to see if your servo is moving or not.
10) You can call myServo.stop(); to stop your servo.

That's all there is to it.

Here is a wokwi example : https://wokwi.com/projects/358434260375219201
