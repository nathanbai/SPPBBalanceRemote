#include "Nrf2401.h"
#include "Wire.h"

Nrf2401 Radio;
int RemoteButton = 7;
int ButtonValue = 0;

void setup(void)
{
  Wire.begin();
  Serial.begin(9600);
  pinMode(RemoteButton, INPUT);
  
  Radio.remoteAddress = 1;
  Radio.txMode(2);
}

void loop(void)
{
  ButtonValue = digitalRead(RemoteButton);
  if(ButtonValue)
  {
    delay(1000);
    ButtonValue = digitalRead(RemoteButton);
    if(ButtonValue)
    {
      Radio.data[0] = (0x55);
      Radio.write();
      delay(2000);
    }
  }
}
