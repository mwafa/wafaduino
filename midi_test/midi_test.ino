int val = 0; 
int lastVal = 0;

void setup()
{
   Serial.begin(9600);       // Set the speed of the midi port to the same as we will be using in the Hairless Midi software 
}

void loop()
{
   val = analogRead(A1)/8;  
   if (val != lastVal) 
   {
   MIDImessage(176,1,val);}         // 176 = CC command (channel 1 control change), 1 = Which Control, val = value read from Potentionmeter 1 NOTE THIS SAYS VAL not VA1 (lowercase of course)
   lastVal = val;
delay(10); //here we add a short delay to help prevent slight fluctuations, knocks on the pots etc. Adding this helped to prevent my pots from jumpin up or down a value when slightly touched or knocked.
}

void MIDImessage(byte command, byte data1, byte data2) //pass values out through standard Midi Command
{
   Serial.write(command);
   Serial.write(data1);
   Serial.write(data2);
}
