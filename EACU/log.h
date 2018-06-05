/**
*MIT License
*
*Copyright (c) 2018 Harrison Davidson

*Permission is hereby granted, free of charge, to any person obtaining a copy
*of this software and associated documentation files (the "Software"), to deal
*in the Software without restriction, including without limitation the rights
*to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
*copies of the Software, and to permit persons to whom the Software is
*furnished to do so, subject to the following conditions:
*
*The above copyright notice and this permission notice shall be included in all
*copies or substantial portions of the Software.
*
*THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
*IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
*FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
*AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
*LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
*OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
*SOFTWARE.
*/

/**
* position 0 = day
* if gas
* position 1 = thrPos
* position 2 = gasLev
* position 3 = engenOn()
* position 4 = gasLev()
*/
#ifdef EEPROMS
  #include <EEPROM.h>
#endif

int incomingByte = 0;
boolean debug=false;

//day. how the log derermans what day to save
int day=1;

#ifdef EEPROMS
void eepromSetup()
{
  if(EEPROM.read(0)>day)
    day=EEPROM.read(0);
  else
    debug=true;
}
#endif

//actual logging
void logging()
{
  #ifdef EEPROMS
    if(86400000>millis())
    {
      day++;
      EEPROM.write(0,day);
    }
  #endif
  #if MOTOR==1
    if(thrPos!=EEPROM.read(1)&&engenOn())
      EEPROM.write(1,thrPos);
    if(gasLev!=EEPROM.read(2))
      EEPROM.write(2,gasLev);
    if(engenOn()!=EEPROM.read(3))
      EEPROM.write(3,engenOn());
    if(rpm()!=EEPROM.read(4))
      EEPROM.write(4,rpm());
    if(key()!=EEPROM.read(5))
      EEPROM.write(5,key());
    if(choPos!=EEPROM.read(6))
      EEPROM.write(6,choPos);
    #ifdef EXHAUST_OX
      if(exhaustOx()!=EEPROM.read(7))
        EEPROM.write(7,exhaustOx());
    #endif
    #ifdef ENGEN_SLEEP
      if(sleep!=EEPROM.read(8))
        EEPROM.write(8,sleep)
    #endif
  #endif
}

void bugS()
{
  //fail safe and kil engen
  digitalWrite(SPARK_ACTIVE_PIN, !SPARK_ACTIVE_ON);
  Serial.begin(9600);
}

void bug()
{
  if (Serial.available() > 0)
  {
    incomingByte = Serial.read();
    #ifdef EEPROMS
      Serial.println(EEPROM.read(incomingByte));
    #endif
  }
}
