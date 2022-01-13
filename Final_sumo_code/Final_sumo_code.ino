#include <Servo.h>

int _ABVAR_7_Light;

Servo servo_pin_10;
Servo servo_pin_11;

void beeping(); // whenever it detects enemies
void victory(); // when it hits white line


int idkL;
int idkR;
int counter;
int _ABVAR_1_Light;
#define echoPin 7 // attach pin D2 Arduino to pin Echo of HC-SR04
#define trigPin 6 //attach pin D3 Arduino to pin Trig of HC-SR04

// defines variables
long duration; // variable for the duration of sound wave travel
int distance; // variable for the distance measurement

void setup()
{
counter = 0;
servo_pin_10.attach(10);
servo_pin_11.attach(11);
Serial.begin(9600);
pinMode( 2, INPUT);
_ABVAR_1_Light = 0;
pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT
Serial.begin(9600); // // Serial Communication is starting with 9600 of baudrate speed
}

void loop()
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
          _ABVAR_1_Light = analogRead(A0) ;
          Serial.print( "Light =" );
          Serial.print( _ABVAR_1_Light );
          Serial.println("");
          Serial.println("");
          idkL = digitalRead(4); // keeps the left IR sensor updated
          idkR = digitalRead(2); // keeps the right IR sensor updated  
          Serial.print(counter);
if ( ( _ABVAR_1_Light ) < ( 280 ) ) { // Less than 280 means it is no longer on a black floor
     // get off white line
    Serial.print( "Cliff Detected! Steering clear..." );
    Serial.println("");
    servo_pin_10.write( 45 );//------|
    servo_pin_11.write( 135 );//     |
    delay(1000);             //      | ------------------ Backs up for one second, turns in one direction, and then continues scanning for entities.
    servo_pin_10.write( 135 );//     |
    servo_pin_11.write( 135 );//-----|
    delay(450);
    counter = 0; // to start spinning again to find enemy
  } else { // check for enemies on the sides
  
  if ( !idkL && !idkR) { // if either idk is a 0 that means there is entities on the sides
      
      servo_pin_10.write( 135 );//------|\
//                                        | ---- Moves forward sharply to avoid enemy 
      servo_pin_11.write( 45 );//-------|/
  } else { // Since we checked both sides and the light sensor, the robot is completely safe so it can do the rest of the code...
  
  
  if ( (distance) != (0) && (distance) < (50) ) // if entity found
  {
    counter = 1; // to lock onto enemy position
      Serial.print( "Entity Found" );
      Serial.print(" ");
      Serial.print(distance);
      Serial.print("cm away...Destroy!");
      Serial.println("");
    servo_pin_10.write( 135 );
    servo_pin_11.write( 45 );
    delay(5000);
    servo_pin_10.write( 45 );
    servo_pin_11.write( 135 );
    delay( 500 );
    beeping();
  }
  else
  {
  if (counter != 0) { 
    servo_pin_10.write( 135 );
    servo_pin_11.write( 45 );
    delay(5000);
    servo_pin_10.write( 45 );
    servo_pin_11.write( 135 );
    delay( 500 );
    beeping();
    
  } else { // keep spining and scanning for enemies
  
    Serial.print( "Scanning For Entities..." );
    Serial.println("");
    servo_pin_10.write( 80 );
    servo_pin_11.write( 80 );
  
  }
  }
  
  
  
  }
}
}


// functions down here wooo

void beeping()
{

    tone(3, 1000, 500);
    delay (100);
    tone(3, 1000, 500);
    delay (100);
    tone(3, 1000, 500);
    delay (100);
    tone(3, 1000, 500);
    delay (100);
    tone(3, 1000, 500);
    delay (100);  
  
  
}

void victory()
{
  
  
 // just empty for now...need to find a cool sound :/ 
  
  
}


















































   

