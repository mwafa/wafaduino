#include <SoftwareSerial.h>
#include "DHT.h"

#define DHTPIN 8
#define DHTTYPE DHT22  
#define pinTrig 12
#define pinEcho 11

DHT dht(DHTPIN, DHTTYPE);
SoftwareSerial ser(10, 9); //(rx,tx)
String token = "BBFF-u6lxxsDa81mVX7hgt9rhEx********"; //Token Ubidots API
 
void setup()
{
  ser.begin(115200); //baudrate pada Shield = 19200           
  Serial.begin(9600); //baudrate serial monitor
  dht.begin();
  pinMode(pinTrig,OUTPUT);
  pinMode(pinEcho,INPUT);
  delay(2000);
  ser.begin(115200);
  ser.println("AT+RST");
  delay(1000);
  ser.println("AT+CWMODE=1");
  String wifi = "AT+CWJAP=\"";
  wifi+= "SSID\",\"Password123\"";  //SSID and Password
  ser.println(wifi);
  if(ser.find("OK")){
    Serial.println(wifi);
  }

}

long ultra_sensor(){
  long dur;
  long dis;

  digitalWrite(pinTrig,LOW);
  delayMicroseconds(2);

  digitalWrite(pinTrig,HIGH);
  delayMicroseconds(10);
  digitalWrite(pinTrig,LOW);

  dur=pulseIn(pinEcho,HIGH);
  dur=(dur/2) / 29.1;
  return dur;
}
 
 
 
void loop()
{
  ser.println("AT+CIPSTART=\"TCP\",\"industrial.api.ubidots.com\",80");
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  long  n = ultra_sensor();
  
  String poster= "{\"temperature\": "+String(t)+", \"humidity\": "+String(h)+", \"nutrition-volume\": "+String(n)+"}\r\n\r\n";
  int len=poster.length();
  
  Serial.println(poster);
  String post = "POST /api/v1.6/devices/device-name/?token="+token+" HTTP/1.1\r\n";
         post+= "Host: things.ubidots.com\r\nContent-Type: application/json\r\nContent-Length: ";
         post+= String(len)+"\r\n\r\n";
         post+=poster;
  ser.print(F("AT+CIPSEND=")); 
  ser.println(post.length()); 
  delay(10);
  ser.print(post);
  if (ser.available()) {
    Serial.println(ser.readString());
  }
  if(ser.find("SEND OK"))
  {
    Serial.print("yaya");
    ser.println(F("AT+CIPCLOSE")); //stop koneksi
  }
  delay(2000);
}

