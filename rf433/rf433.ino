long data;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(A0, INPUT);
  pinMode(6, OUTPUT);
  analogWrite(6,150); //450
  analogWrite(6,50); //800
}

void loop() {
  // put your main code here, to run repeatedly:
  data = pulseIn(A0, HIGH);
  Serial.println(data);
}
