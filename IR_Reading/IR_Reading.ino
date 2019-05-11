unsigned long buf;
long pulsa;
unsigned int data = 0;
bool GOOD = false;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(A0, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  pulsa = pulseIn(A0, HIGH,15000);
//  pulsa = digitalRead(A0);
//  Serial.println(pulsa);
  if(pulsa > 3000){
    GOOD = true;    
  }else if(pulsa && pulsa < 2000 && pulsa > 100 && GOOD){
    buf <<=1;
    buf += (pulsa > 1000 ? 1 : 0);
    data++;
  }else if(data){
    if(data >= 8){
      Serial.print(buf);
      Serial.print("\t");
      Serial.println(data);
    }
    data = 0;
    buf = 0;
  }
  
}
