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
#include <Servo.h>
#include "rpm.h"
#include "key.h"
#ifdef CHOKE
  #include "choke.h"
#endif
#ifdef LOG
  #include "log.h"
#endif
Servo throttleServo;
int thrPos=0;
int gasLev=0;
boolean engenON=false;

int thrRead()
{
  return map(analogRead(THROTTLE_PIN),THR_LOW,THR_HIGH,THROTTLE_SERVO_LOW,THROTTLE_SERVO_HIGH);
}

boolean engineOn()
{
  if(rpm()>5&&key())
    return true;
  return false;
}

void startEngine()
{
  while(key()&&!engineOn())
  {
    digitalWrite(SPARK_ACTIVE_PIN, SPARK_ACTIVE_ON);
    #ifdef IGNITION_MOTOER
      digitalWrite(IGNITION_MOTOR_PIN, IGNITION_MOTOER_ON);
    #endif
  }
  #ifdef IGNITION_MOTOER
    digitalWrite(IGNITION_MOTOR_PIN, !IGNITION_MOTOER_ON);
  #endif
  engenON=true;
}

void stopEngine()
{
  digitalWrite(SPARK_ACTIVE_PIN, !SPARK_ACTIVE_ON);
  engenON=false;
}

#ifndef ENGEN_SLEEP
  void engienAlive()
  {
    if(rpm()<5&&key())
      startEngine();
    else if(!key())
      stopEngine();
  }
#elif defined(ENGEN_SLEEP)
  #include "sleep.h"
#endif

void throttle()
{
  if(thrRead()>thrPos)
    thrPos++;
  else if(thrRead()<thrPos)
    thrPos--;
  if(engineOn())
  {
    if(thrPos>THROTTLE_SERVO_HIGH)
      thrPos=THROTTLE_SERVO_HIGH;
    else if(thrPos<THROTTLE_SERVO_LOW)
      thrPos=THROTTLE_SERVO_LOW;
    throttleServo.write(thrPos);
  }
  else
    throttleServo.write(THROTTLE_SERVO_LOW);
}

void setUP()
{
  throttleServo.attach(THROTTLE_SERVO_PIN);
  throttleServo.write(THROTTLE_SERVO_LOW);
  pinMode(THROTTLE_PIN, INPUT);
  #ifdef CHOKE
    chokeServo.attach(CHOKE_SERVO_PIN);
    chokeServo.write(THROTTLE_SERVO_LOW);
  #endif
  #ifdef EXHAUST_OX
    pinMode(EXHAUST_OX_PIN, INPUT);
  #endif
  pinMode(SPARK_ACTIVE_PIN, OUTPUT);
  digitalWrite(SPARK_ACTIVE_PIN, !SPARK_ACTIVE_ON);
  #ifdef IGNITION_MOTOER
    pinMode(IGNITION_MOTOR_PIN, OUTPUT);
    digitalWrite(IGNITION_MOTOR_PIN, !IGNITION_MOTOER_ON);
  #endif
  #ifdef EEPROMS
    eepromSetup();
  #endif
}
void go()
{
  engienAlive();
  throttle();
  #ifdef CHOKE
    choke();
  #endif
  #ifdef LOG
    logging();
  #endif
}
