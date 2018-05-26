boolean key()
{
  if(digitalRead(KEY_PIN)==KEY_POS)
    return true;
  return false;
}
