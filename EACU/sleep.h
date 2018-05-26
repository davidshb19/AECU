int sleepTime;
boolean sleep;
void engienAlive()
{
  if(rpm()<100&&key()&&!sleep)
    startEngine();
  else if(!key()||sleep)
    stopEngine();
  if(thrPos==THROTTLE_SERVO_LOW)
  {
    if(millis()-sleepTime>=ENGEN_SLEEP_TIME)
      {
        sleep=true;
      }
  }
  else
  {
    sleep=false;
    sleepTime=millis();
  }
}
