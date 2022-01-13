int idkL;
int idkR;

void clear();

void setup()
{
Serial.begin(9600);
pinMode (2,INPUT);
}

void loop()
{
  
            idkL = digitalRead(4); // keeps the left IR sensor updated
            idkR = digitalRead(3); // keeps the right IR sensor updated  


if ( !idkR && !idkL ) {
 Serial.print("I'm surrounded!!");
 clear();
 
} else {
  
  if ( !idkL ) {

 Serial.print("Object is on the left side!");
 clear();
 
}

if ( !idkR ) {
 Serial.print("Object is on the right side!");
 clear();

}
  
}



if ( idkR && idkL ) {
 Serial.print("I'm safe!");
 clear();
 
 
}



delay(250 );
}


// function


void clear()
{

 Serial.println("");
 Serial.println("");
 Serial.println("");
 Serial.println("");
 Serial.println("");
 Serial.println("");
 Serial.println("");
 Serial.println("");
 Serial.println("");
 Serial.println("");
 Serial.println("");
 Serial.println("");
 Serial.println("");
 Serial.println("");
 Serial.println("");
 Serial.println("");
 Serial.println("");
 Serial.println("");
 Serial.println("");
 Serial.println("");
 Serial.println("");
 Serial.println("");
 Serial.println("");
 Serial.println("");
 Serial.println("");
 Serial.println("");
 Serial.println("");
 Serial.println("");
 Serial.println("");
 Serial.println("");
 Serial.println("");
 Serial.println("");
 Serial.println("");
 Serial.println("");
 Serial.println("");
 Serial.println("");
 Serial.println("");
 Serial.println("");
 Serial.println("");
 Serial.println("");
 Serial.println("");
 Serial.println("");
 Serial.println("");
 Serial.println("");
 Serial.println("");
 Serial.println("");
 Serial.println("");
 Serial.println("");
 Serial.println("");
 Serial.println("");
 Serial.println("");
 Serial.println("");


}
