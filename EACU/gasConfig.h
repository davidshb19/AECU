#include <Servo.h>
Servo throttleServo;
#ifdef CHOKE
  #include "choke.h"
#endif
int thrPos=0;
int gasLev=0;
boolean engenON=false;

int rpm()
{
  int rpms=0;//add code to read RPM***************************
  return rpms;
}

int thrRead()
{
  return map(analogRead(THROTTLE_PIN),THR_LOW,THR_HIGH,THROTTLE_SERVO_LOW,THROTTLE_SERVO_HIGH);
}

boolean key()
{
  if(digitalRead(KEY_PIN)==KEY_POS)
    return true;
  return false;
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

void engienAlive()
{
  if(rpm()<5&&key())
    startEngine();
  else
    stopEngine();
}

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
}
void go()
{
  engienAlive();
  throttle();
  #ifdef CHOKE
    choke();
  #endif
}
