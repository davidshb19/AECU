#include "Configuration.h"
#include "boards.h"
#include "pins.h"
#include "SanityCheck.h"
#if MOTOR==1
  #include "gasConfig.h"
#endif
#if MOTOR==2
  #include "electricConfig.h"
#endif
