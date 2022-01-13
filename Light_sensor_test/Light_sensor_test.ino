int _ABVAR_1_Light;

void setup()
{
Serial.begin(9600);
_ABVAR_1_Light = 0;
}

void loop()
{
_ABVAR_1_Light = analogRead(A7) ;
Serial.print( "Light =" );
Serial.print( _ABVAR_1_Light );
Serial.println("");
delay( 100 );
}
