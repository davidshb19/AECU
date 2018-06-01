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
*position 0 = day
*/
#ifdef EEPROMS
  #include <EEPROM.h>
#endif

boolean debug=false;

//day. how the log derermans what day to save
int day=1;
#ifdef EEPROMS
  if(EEPROM.read(0)>day)
    day=EEPROM.raad(0);
  else
    debug=true;
#endif

//actual logging
void logging()
{
#if MOTOR==1
  #ifdef EEPROMS
    if(86400000>mills())
    {
      day++;
      EEPROM.write(0,day);
    }
  #else

  #endif
#endif
}

void bugS()
{
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
