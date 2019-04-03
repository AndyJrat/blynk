//BLYNK app software for controlling four motors
//Created by Juan Ruiz

#define BLYNK_PRINT Serial
#include <BlynkSimpleSerialBLE.h>
#include <SoftwareSerial.h>

//THIS IS THE ONLY CODE YOU SHOULD CHANGE ACCORDING TO YOUR DIGITAL PINOUTS
//----------------------------------------------
int left_Front = 8;
int left_Back = 9;

int right_Front = 10;
int right_Back = 11;

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
  pinMode(left_Front, OUTPUT);
  pinMode(left_Back, OUTPUT);
  
  pinMode(right_Front, OUTPUT);
  pinMode(right_Back, OUTPUT);
  
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
  digitalWrite(left_Front, LOW);
  digitalWrite(left_Back, HIGH);
  
  if(param.asInt() == 0)
  {
    digitalWrite(left_Front, LOW);
    digitalWrite(left_Back, LOW);
  }
}// END V0

BLYNK_WRITE(V1)
{
  digitalWrite(left_Front, HIGH);
  digitalWrite(left_Back, LOW);

  if(param.asInt() == 0)
  {
    digitalWrite(left_Front, LOW);
    digitalWrite(left_Back, LOW);
  }
}//END V1




//RIGHT SIDE
BLYNK_WRITE(V2)
{
  digitalWrite(right_Front, LOW);
  digitalWrite(right_Back, HIGH);
  
  if(param.asInt() == 0)
  {
    digitalWrite(right_Front, LOW);
    digitalWrite(right_Back, LOW);
  }
}//END V2

BLYNK_WRITE(V3)
{
  digitalWrite(right_Front, HIGH);
  digitalWrite(right_Back, LOW);

  if(param.asInt() == 0)
  {
    digitalWrite(right_Front, LOW);
    digitalWrite(right_Back, LOW);
  }
}//END V3
