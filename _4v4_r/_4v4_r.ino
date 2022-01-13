#include <Servo.h>

Servo servo_pin_10;
Servo servo_pin_11;
Servo servo_pin_9;
Servo servo_pin_12;
Servo servo_pin_13;

void setup()
{
servo_pin_9.attach(9);
servo_pin_10.attach(10);
servo_pin_11.attach(11);
servo_pin_12.attach(12);

}

void loop()
{
servo_pin_10.write( 45 );
servo_pin_11.write( 45 );
servo_pin_12.write( 135 );
servo_pin_9.write( 45 );
servo_pin_13_.write( 45 );w

}
