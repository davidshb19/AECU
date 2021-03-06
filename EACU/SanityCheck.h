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
//Configuration.h requied
#ifndef MOTHERBOARD
  #error "MOTHERBOARD must be specified."
#elif !defined(MOTOR)
  #error "MOTOR must be specified"
#elif !defined(THR_LOW)
  #error "THR_LOW must be specified."
#elif !defined(THR_HIGH)
  #error "THR_HIGH must be specified."
#elif !defined(KEY_POS)
  #error "KEY_POS must be specified."
#endif
#if MOTOR==1
  #ifndef THROTTLE_SERVO_LOW
    #error "THROTTLE_SERVO_LOW must be specified"
  #elif !defined(THROTTLE_SERVO_HIGH)
    #error "THROTTLE_SERVO_HIGH must be specified"
  #endif
#endif
//Configuration.h optional
#if MOTOR==1
  #ifdef EXHAUST_OX
    #ifdef NO_OX
      #error "NO_OX and EXHAUST_OX can not be enabled at the same time"
    #elif !defined(EXHAUST_OX_LOW)
      #error "EXHAUST_OX_LOW must be specified"
    #elif !defined(EXHAUST_OX_HIGH)
      #error "EXHAUST_OX_HIGH must be specified"
    #elif !defined(CHOKE_DEADZONE)
      #error "CHOKE_DEADZONE must be specified"
    #endif
  #endif
  #ifdef NO_OX
    #ifndef CHOKE_REV_TIME
      #error "CHOKE_REV_TIME must be specified"
    #endif
  #endif
  #ifdef CHOKE
    #ifndef CHOKE_SERVO_LOW
      #error "CHOKE_SERVO_LOW must be specified"
    #elif !defined(CHOKE_SERVO_HIGH)
      #error "CHOKE_SERVO_HIGH must be specified"
    #endif
  #endif
  #ifdef ENGEN_SLEEP
    #ifndef ENGEN_SLEEP_TIME
      #error "ENGEN_SLEEP_TIME must be specified"
    #endif
  #endif
#endif
//board/pins
#ifndef ANALOG_LOW
  #error "ANALOG_LOW must be specified."
#elif !defined(ANALOG_HIGH)
  #error "ANALOG_HIGH must be specified."
#elif !defined(DIGITAL_LOW)
  #error "DIGITAL_LOW must be specified."
#elif !defined(DIGITAL_HIGH)
  #error "DIGITAL_HIGH must be specified"
#elif !defined(THROTTLE_PIN)
  #error "THROTTLE_PIN must be specified."
#elif THROTTLE_PIN<ANALOG_LOW||THROTTLE_PIN>ANALOG_HIGH
  #error "THROTTLE_PIN is out of range."
#elif !defined(KEY_PIN)
  #error "KEY_PIN must be specified."
#elif KEY_PIN<DIGITAL_LOW||KEY_PIN>DIGITAL_HIGH
  #error "KEY_PIN is out of range."
#endif
#if MOTOR==1
  #ifndef THROTTLE_SERVO_PIN
    #error "THROTTLE_PIN must be specified."
  #elif THROTTLE_SERVO_PIN<DIGITAL_LOW||THROTTLE_SERVO_PIN>DIGITAL_HIGH
    #error "THROTTLE_SERVO_PIN is out of range."
  #elif !defined(SPARK_ACTIVE_PIN)
    #error "SPARK_ACTIVE_PIN must be specified."
  #elif SPARK_ACTIVE_PIN<DIGITAL_LOW||SPARK_ACTIVE_PIN>DIGITAL_HIGH
    #error "SPARK_ACTIVE_PIN is out of range."
  #elif !defined(IGNITION_MOTOR_PIN)
    #error "IGNITION_MOTOR_PIN must be specified."
  #elif IGNITION_MOTOR_PIN<DIGITAL_LOW||IGNITION_MOTOR_PIN>DIGITAL_HIGH
    #error "IGNITION_MOTOR_PIN is out of range."
  #elif !defined(EXHAUST_OX_PIN)
    #error "EXHAUST_OX_PIN must be specified."
  #elif EXHAUST_OX_PIN<ANALOG_LOW||EXHAUST_OX_PIN>ANALOG_HIGH
    #error "EXHAUST_OX_PIN is out of range."
  #elif !defined(CHOKE_SERVO_PIN)
    #error "CHOKE_SERVO_PIN must be specified."
  #elif CHOKE_SERVO_PIN<DIGITAL_LOW||CHOKE_SERVO_PIN>DIGITAL_HIGH
    #error "CHOKE_SERVO_PIN is out of range."
  #endif
#endif
