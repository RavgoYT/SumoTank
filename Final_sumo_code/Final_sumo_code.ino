
#define echoPin 7 // attach pin D2 Arduino to pin Echo of HC-SR04
#define trigPin 6 //attach pin D3 Arduino to pin Trig of HC-SR04
#include <Servo.h>

Servo servo_pin_10;
Servo servo_pin_11;

void eyes();

// defines variables
long duration; // variable for the duration of sound wave travel
int distance; // variable for the distance measurement
int counter;
int detect;
int _ABVAR_1_Light;

void setup() {
  counter = 0;
  detect = 60; // Change detection range by centimeters
  servo_pin_10.attach(10);
  servo_pin_11.attach(11);
  pinMode( 2, INPUT);
  _ABVAR_1_Light = 0;
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT
  Serial.begin(9600); // // Serial Communication is starting with 9600 of baudrate speed
  Serial.println("Begin:"); // print some text in Serial Monitor
}
void loop() {
            _ABVAR_1_Light = analogRead(A0) ;
          Serial.print( "Light =" );
          Serial.print( _ABVAR_1_Light );
          Serial.println("");
          Serial.println("");
if ( ( _ABVAR_1_Light ) < ( 250 ) ) { // less than 280 means it's no longer on black floor
     // get off white line

    Serial.print( "Cliff Detected! Steering clear..." );
//    servo_pin_10.write( 45 );//------|
//    servo_pin_11.write( 135 );//     |
//    delay(1000);             //      | ------------------ Backs up for one second, turns in one direction, and then continues scanning for entities.
//    servo_pin_10.write( 135 );//     |
//    servo_pin_11.write( 135 );//-----|
    servo_pin_10.write( 45 );// --|\
    servo_pin_11.write( 135 );//--| \temporary
    delay(450);
    counter = 0; // to start spinning again to find enemy
} else { // code works properly                                                         ====================== ADD IR SENSOR CODE HERE ===========================

  if ( (counter) != 1 ) {  // if no entity found, keep spinning

    Serial.print( "Scanning..." );
    Serial.println("");
    servo_pin_10.write( -100 );
    servo_pin_11.write( -100 );
    delay(200);
    servo_pin_10.detach();
    servo_pin_11.detach();
    eyes();
    delay(500);
    servo_pin_10.attach(10);
    servo_pin_11.attach(11);
  } else { // if counter = 1 that means this code will run (Entity found)
    tone(13, 1000, 500);
    servo_pin_10.write( 135 );
    servo_pin_11.write( 45 );
    Serial.print( "Found!" );
    Serial.println("");
}
  
  }

}

void eyes()
{
   // Clears the trigPin condition
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
  // Displays the distance on the Serial Monitor 
    Serial.print( "Eye check" );
    Serial.println("");
    if ( (distance) != (0) && (distance) < detect ) { // 90 centimeters
    servo_pin_10.detach();
    servo_pin_11.detach();
    delay(300);
       // Clears the trigPin condition
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
    if ( (distance) != (0) && (distance) < detect ) {
        counter = 1; 
        servo_pin_10.attach(10);
        servo_pin_11.attach(11);
    }
    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" cm");

    }
  
}
 
