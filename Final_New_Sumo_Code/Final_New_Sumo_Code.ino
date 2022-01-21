
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
  Serial.println("Ultrasonic Sensor HC-SR04 Test"); // print some text in Serial Monitor
  Serial.println("with Arduino UNO R3");
}
void loop() {

  
  if ( (distance) != (0) && (distance) < 15 ) {  
  
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  servo_pin_10.write( -135 );
  servo_pin_11.write( -135 );
  delay(1200);
  
  
  } else { // if no entity found, keep spinning
  
    Serial.print( "Scanning For Entities..." );
    Serial.println("");
    servo_pin_10.write( 135 );
    servo_pin_11.write( 135 );
    delay(300);
    servo_pin_10.detach();
    servo_pin_11.detach();
    eyes();
    delay(400);
    servo_pin_10.attach(10);
    servo_pin_11.attach(11);
  
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
    if ( (distance) != (0) && (distance) < 15 ) {
     
     counter = 1;
      
    }
  
}
