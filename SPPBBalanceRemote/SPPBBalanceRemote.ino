#include "Wire.h"
#include <SoftwareSerial.h>

SoftwareSerial WiFlySerial(4,3); //RX  TX

int RemoteButton = 2;
int ButtonValue = 0;
boolean flag_test = false;
int Received = 0;

String RemoteSignal = "remote";

void WiFiSend(String data_send)
{
  WiFlySerial.print(data_send);
  WiFlySerial.println("");
  WiFlySerial.println("");
  Serial.println("wifi sent");
}

void WiFiSend(unsigned int data_send)
{ 
  WiFlySerial.print(data_send);
  WiFlySerial.println("");
  WiFlySerial.println("");
}


void setup(void)
{
  Wire.begin();
  Serial.begin(9600);
  pinMode(RemoteButton, INPUT);
  WiFlySerial.begin(9600);
}

void loop(void)
{
  
  /*if(WiFlySerial.available()) {
    Received = WiFlySerial.read();
    Serial.println(Received);
  }
  
  if (Received == 49)      
  {
    Serial.println("Need to press button");
    flag_test = true; 
    Received = 0;
  }
  
  if(flag_test)
  {*/
    ButtonValue = digitalRead(RemoteButton);
    if(ButtonValue)
    {
      delay(200);
      ButtonValue = digitalRead(RemoteButton);
      if(ButtonValue)
      {
        Serial.println("pressed");
        WiFiSend(RemoteSignal);
        flag_test = false;
        delay(2000);
      }
    }
  //}
  
}
