//BLYNK app software for controlling four motors
//Created by Juan Ruiz

#define BLYNK_PRINT Serial
#include <BlynkSimpleSerialBLE.h>
#include <SoftwareSerial.h>

//THIS IS THE ONLY CODE YOU SHOULD CHANGE ACCORDING TO YOUR DIGITAL CONNECTIONS
//----------------------------------------------
int in1 = 8;
int in2 = 9;

int in3 = 10;
int in4 = 11;

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
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  
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
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  
  if(param.asInt() == 0)
  {
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
  }
}// END V0

BLYNK_WRITE(V1)
{
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);

  if(param.asInt() == 0)
  {
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
  }
}//END V1




//RIGHT SIDE
BLYNK_WRITE(V2)
{
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  
  if(param.asInt() == 0)
  {
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
  }
}//END V2

BLYNK_WRITE(V3)
{
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);

  if(param.asInt() == 0)
  {
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
  }
}//END V3
