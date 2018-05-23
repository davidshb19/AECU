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
