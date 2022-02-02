#include <Servo.h>

Servo servo_pin_10;
Servo servo_pin_11;

// defines variables
int _ABVAR_1_Light;
int idkL;
int idkR;
int counter;

void setup() {
  counter = 0;
  servo_pin_10.attach(10);
  servo_pin_11.attach(11);
  pinMode( 2, INPUT);
  _ABVAR_1_Light = 0;
}
void loop() {
              idkL = digitalRead(4); // keeps the left IR sensor updated
            idkR = digitalRead(3); // keeps the right IR sensor updated  
            _ABVAR_1_Light = analogRead(A0) ;
if ( ( _ABVAR_1_Light ) < ( 250 ) ) { // less than 280 means it's no longer on black floor
     // get off white line

    servo_pin_10.write( 45 );//------|
    servo_pin_11.write( 135 );//     |
    delay(1000);             //      | ------------------ Backs up for one second, turns in one direction, and then continues scanning for entities.
    servo_pin_10.write( 135 );//     |
    servo_pin_11.write( 135 );//-----|
    delay(450);
} else { // code works properly

if ( !idkR && !idkL ) {
    servo_pin_10.write( 45 );
    servo_pin_11.write( 135 );
} else {
  
  if ( !idkL ) {

    servo_pin_10.write( 135 );
    servo_pin_11.write( 135 );
}

if ( !idkR ) {
    servo_pin_10.write( 45 );
    servo_pin_11.write( 45 );
}
  
}



if ( idkR && idkL ) {
  
  if ( (counter) != 2) {
    servo_pin_10.write( 135 );
    servo_pin_11.write( 45 );
    delay(5000);
  }

    counter = 2;
    if ( (counter) != 0) {
    servo_pin_10.write( 135 );
    servo_pin_11.write( 45 );
    delay(1500);
    servo_pin_10.write( 45 );
    servo_pin_11.write( 135 );
    delay(500);
    
    }
 
}
  }
      
      }
