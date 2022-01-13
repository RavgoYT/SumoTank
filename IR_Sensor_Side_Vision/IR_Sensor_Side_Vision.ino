void setup()
{
Serial.begin(9600);
pinMode (2,INPUT);
}

void loop()
{
  
            idkL = digitalRead(4); // keeps the left IR sensor updated
            idkR = digitalRead(2); // keeps the right IR sensor updated  

if ( !idkL ) {
  
 Serial.print("Object is on the left side!");
 Serial.println("");
  
}

if ( !idkR ) {
  
   Serial.print("Object is on the right side!");
   Serial.println("");
}

if ( !idkR && !idkL ) { 

  
   Serial.print("I'm surrounded!!");
   Serial.println("");

}

if ( idkR && idkL ) { 

  
   Serial.print("I'm safe!!");
   Serial.println("");

}

delay( 250 );
}
