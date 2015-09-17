#include <DTIOI2CtoParallelConverter.h>
#include <Wire.h>

DTIOI2CtoParallelConverter ioConverter(0x77);

void setup()
{
  Serial.begin(9600);
  Wire.begin();
  ioConverter.portMode0(ALLOUTPUT);
  ioConverter.digitalWritePort0(0xFF);
  ioConverter.portMode1(ALLINPUT);
  //ioConverter.twiWrite(POLINVPORT1, 0xFF); //inverting polarity of PORT 1
}

void loop()
{
  byte pin0 = 0, pin1 = 1;
  
  ioConverter.digitalRead1(pin0);
  if(pin0 == 0)
    ioConverter.digitalWrite0(0, LOW);
  else
    ioConverter.digitalWrite0(0, HIGH);
  
  ioConverter.digitalRead1(pin1);
  if(pin1 == 0)
    ioConverter.digitalWrite0(1, LOW);
  else
    ioConverter.digitalWrite0(1, HIGH);
}
