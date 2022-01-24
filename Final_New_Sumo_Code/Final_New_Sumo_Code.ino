
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

void setup() {
  counter = 0;
  servo_pin_10.attach(10);
  servo_pin_11.attach(11);
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT
  Serial.begin(9600); // // Serial Communication is starting with 9600 of baudrate speed
  Serial.println("Begin:"); // print some text in Serial Monitor
}
void loop() {
  
  if ( (counter) != 1 ) {  // if no entity found, keep spinning

    Serial.print( "Scanning..." );
    Serial.println("");
    servo_pin_10.write( 105 );
    servo_pin_11.write( 105 );
    delay(300);
    servo_pin_10.detach();
    servo_pin_11.detach();
    eyes();
    delay(400);
    servo_pin_10.attach(10);
    servo_pin_11.attach(11);
  } else { // if counter = 1 that means this code will run (Entity found)
    
    servo_pin_10.detach();
    servo_pin_11.detach();
    Serial.print( "Found!" );
    Serial.println("");
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
    if ( (distance) != (0) && (distance) < 15 ) { // 15 centimeters
     
     counter = 1;
      
    }
  
}
