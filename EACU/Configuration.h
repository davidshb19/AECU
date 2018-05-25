//main board model. board names can be found in boards.h
#ifndef MOTHERBOARD
  #define MOTHERBOARD BOARD_UNO
#endif

//motor model. uncommit the correct line fot the type of moter you have.
//if you have gas set to 1.
// if electric set to 2
#ifndef
  #define MOTOR 1
#endif

//throtel posisitions. this is where you input the low and high positions of your potentiomiter and servo(if you have a gas engen) for the throtel
#ifndef THR_LOW
  #define THR_LOW 0
#endif
#ifndef THR_HIGH
  #define THR_HIGH 255
#endif
#ifdef GAS
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
#endif

//key position if inseted
#ifndef KEY_POS
  #define KEY_POS 1
#endif

#ifdef GAS
  //spark active.
  #define SPARK_ACTIVE_ON HIGH //state for relay to be in on position
  //starter motor. comment out the fllowing line of code if you dont have a ignition motor
  //#define IGNITION_MOTOER
  #ifdef IGNITION_MOTOER
  	#define IGNITION_MOTOER_ON HIGH //state for relay to be in on position
  #endif
#endif
