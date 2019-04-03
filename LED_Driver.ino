//BLYNK app software for controlling an LED
//Created by Juan Ruiz

#define BLYNK_PRINT Serial
#include <BlynkSimpleSerialBLE.h>
#include <SoftwareSerial.h>

//THIS IS THE ONLY CODE YOU SHOULD CHANGE ACCORDING TO YOUR DIGITAL PINOUTS
//----------------------------------------------
int led = 10;

//DO NOT CHANCE THESE, CONNECT THE RX TO DIGITAL PIN 2 AND TX TO DIGITAL PIN 3
int RX = 2;
int TX = 3;
//----------------------------------------------

SoftwareSerial SwSerial(RX, TX); // RX, TX
  
//MAKE SURE TO USE YOUR AUTH KEY GIVEN BY THE BLYNK APP
//----------------------------------------------
char auth[] = "INSERT YOUR OWN KEY HERE";
//----------------------------------------------

SoftwareSerial SerialBLE(RX, TX); // RX, TX

void setup()
{
  pinMode(led, OUTPUT);

  // Debug console
  Serial.begin(9600);

  SerialBLE.begin(9600);
  Blynk.begin(SerialBLE, auth);
  
  Serial.println("Waiting for connections...");

}

void loop()
{
  Blynk.run(); 
}


//LEFT SIDE
BLYNK_WRITE(V0)
{
  digitalWrite(led, HIGH);
  
  if(param.asInt() == 0)
  {
    digitalWrite(led, LOW);
  }
  
}// END V0
