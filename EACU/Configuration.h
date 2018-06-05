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
//main board model. board names can be found in boards.h
#ifndef MOTHERBOARD
  #define MOTHERBOARD BOARD_UNO
#endif

//logging. if you want to use logging in your setup.
//if you have a sd card reader / wighter it is highly recomendedou use it as to prevent eeprom dammege.
#ifndef LOG
  #define LOG
#endif
#ifdef LOG
  #ifndef EEPROMS
    #define EEPROMS
  #endif
#endif

//motor model. uncommit the correct line fot the type of moter you have.
//if you have gas set to 1.
// if electric set to 2
#ifndef MOTOR
  #define MOTOR 1
#endif

//throtel posisitions. this is where you input the low and high positions of your potentiomiter and servo(if you have a gas engen) for the throtel
#ifndef THR_LOW
  #define THR_LOW 0
#endif
#ifndef THR_HIGH
  #define THR_HIGH 255
#endif
#if MOTOR==1
  #ifndef THROTTLE_SERVO_LOW
    #define THROTTLE_SERVO_LOW 0
  #endif
  #ifndef THROTTLE_SERVO_HIGH
    #define THROTTLE_SERVO_HIGH 180
  #endif
#endif

#if MOTOR==1
  //oxegen sensor. this is were you input the low and high positions of your Oxegen Sensor if you dont have a one or any of the oxygen sensors below commit it out.
  //if you want to use the choke features but dont have a oxegen sensor than uncommit NO_OX
  //#define NO_OX
  #define EXHAUST_OX
  #ifdef EXHAUST_OX
    #ifndef EXHAUST_OX_LOW
      #define EXHAUST_OX_LOW 0
    #endif
    #ifndef EXHAUST_OX_HIGH
      #define EXHAUST_OX_HIGH 127
    #endif
    #ifndef CHOKE_DEADZONE
        #define CHOKE_DEADZONE 7
    #endif
  #endif
  #ifdef NO_OX
    #ifndef CHOKE_REV_TIME
      #define CHOKE_REV_TIME 100 //mesured in miliseconds
    #endif
  #endif

  //choke positions. this is where you input the low and high positions of your servo for the choke positions.
  //if you dont have a choke (throtel/choke combo) than commit the folowing line out.
  //if you want to proporly use the choke you will need at least a oxegen sensor on the exhaust.
  //you can run choke without a oxegen sensor but it will just open the choke once you have reved high for a set amout of time.
  #define CHOKE
  #ifdef CHOKE
    #ifndef CHOKE_SERVO_LOW
      #define CHOKE_SERVO_LOW 0
    #endif
    #ifndef CHOKE_SERVO_HIGH
      #define CHOKE_SERVO_HIGH 180
    #endif
  #endif

  //engen sleep. this feature allows the engen to automaticly turn off and on
  //depending on weather it has been inactive for a set amout of time.
  //if you want to enable this feature uncommit this line below.
  #define ENGEN_SLEEP
  #ifdef ENGEN_SLEEP
    #ifndef ENGEN_SLEEP_TIME
      #define ENGEN_SLEEP_TIME 5000 //time in miliseconds
    #endif
  #endif
#endif

//key position if inseted
#ifndef KEY_POS
  #define KEY_POS 1
#endif

#if MOTOR==1
  //spark active.
  #define SPARK_ACTIVE_ON HIGH //state for relay to be in on position
  //starter motor. comment out the fllowing line of code if you dont have a ignition motor
  //#define IGNITION_MOTOER
  #ifdef IGNITION_MOTOER
  	#define IGNITION_MOTOER_ON HIGH //state for relay to be in on position
  #endif
#endif
