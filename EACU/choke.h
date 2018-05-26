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
Servo chokeServo;
int choPos=0;
int choTime;

#ifdef EXHAUST_OX
int exhaustOx()
{
  return map(analogRead(EXHAUST_OX_PIN),EXHAUST_OX_LOW,EXHAUST_OX_HIGH,0,255);
}
#endif
void choke()
{
  #ifdef NO_OC
    if(thrPos==THROTTLE_SERVO_HIGH)
    {
      if(millis()-choTime>=CHOKE_REV_TIME)
      {
        choPos=CHOKE_SERVO_HIGH;
      }
    }
    else
      choPos=CHOKE_SERVO_LOW;
      choTime=millis();
  #endif
  #ifdef EXHAUST_OX
    if(exhaustOx()>127)
      choPos--;
    else if(exhaustOx()<127)
      choPos++;
  #endif
  chokeServo.write(choPos);
}
