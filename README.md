# safeTimers.h
This program is to test the millis() rollover in just a few seconds ...

For your convenience we have made a `safeTimers.h` file that you can use in your own programs/sketches
and never have to worry about your timers anymore!

There is an ongoing discussion on the internet about the problems due to 
the rollover of the millis()/micros() timer functions.

The timer-rollover problem is addressed by `Edgar Bonet` on `StackExchange`.

You can find the discussion [here](https://arduino.stackexchange.com/questions/12587/how-can-i-handle-the-millis-rollover).



This program tackles the rollover problem by means of a `safeTimers.h` file originally created by **Erik**
and modified by *Willem Aandewiel* and *Robert van den Breemen*.

In the `safeTimers.h` file you will find the following macro definitions:
```
//--- timerType's -----------------------
#define SKIP_MISSED_TICKS             0
#define SKIP_MISSED_TICKS_WITH_SYNC   1
#define CATCH_UP_MISSED_TICKS         2


#define DECLARE_TIMER(timerName, ...)  \
                      static uint32_t timerName##_interval = (getParam(0, __VA_ARGS__, 0)), \
                                      timerName##_due  = millis()                           \
                                                        +timerName##_interval               \
                                                        +random(timerName##_interval / 3);  \
                      static byte     timerName##_type = getParam(1, __VA_ARGS__, 0);

#define CHANGE_INTERVAL(timerName, ...)  \
                                      timerName##_interval = (getParam(0, __VA_ARGS__, 0) ),        \
                                      timerName##_due  = millis()                                   \
                                                       +timerName##_interval                        \
                                                       +random(timerName##_interval / 3);           \
                                      timerName##_type = getParam(1, __VA_ARGS__, 0);


#define TIME_LEFT(timerName)          ( __TimeLeft__(timerName##_due) ) 
#define TIME_PAST(timerName)          ( (timerName##_interval - TIME_LEFT(timerName)) )

#define RESTART_TIMER(timerName)      ( timerName##_due = millis()+timerName##_interval ); 

#define DUE(timerName)                ( __Due__(timerName##_due, timerName##_interval, timerName##_type) )
```

## USING TIMERS
Creating a timer is as simple as:
```
  DECLARE_TIMER(<timerName>, <Interval>)
```
or
```
  DECLARE_TIMER(<timerName>, <Interval>, timerType)
```

In your program write the following code to use the timer:
```
  if (DUE( <timerName> ) )
  {
    ...
    ... do what you need to do
    ...
  }
```
You can best place this code in the `loop()` of your program/sketch.

There can be as many timers as you want!

## TESTING THE CORRECT WORKING OF THE TIMERS
In the file `safeTimersFastRO.h` we have changed the `millis()` into `micros()` so the rollover will occur 
rougly in 1 hour and 11 minutes.
For even faster testing there are also definitions for 16 bit timers:
```
#define DECLARE_TIMER_16BIT(timerName, ...)  \
                        static uint16_t timerName##_interval = getParam(0, __VA_ARGS__, 0),     \
                                        timerName##_due  = timer16Bit()                         \
                                                          +timerName##_interval                 \
                                                          +random(timerName##_interval / 3);    \
                        static byte     timerName##_type = getParam(1, __VA_ARGS__, 0);

#define CHANGE_16BIT_INTERVAL(timerName, ...) \
                                        timerName##_interval = (getParam(0, __VA_ARGS__, 0) ),  \
                                        timerName##_due  = timer16Bit()                         \
                                                          +timerName##_interval                 \
                                                          +random(timerName##_interval / 3);    \
                                        timerName##_type = getParam(1, __VA_ARGS__, 0);
                                                    
#define RESTART_TIMER_16BIT(timerName)  timerName##_due = timer16Bit()+timerName##_interval;

#define TIME_LEFT_16BIT(timerName)      ( __TimeLeft16Bit__(timerName##_due) ) 

#define TIME_PAST_16BIT(timerName)      ( (timerName##_interval - TIME_LEFT_16BIT(timerName)) )

#define DUE_16BIT(timerName)            ( __Due16Bit__(timerName##_due                \
                                                         , timerName##_interval       \
                                                         , timerName##_type) )
```
Those macro's work the same as the 32 bit equevalents but the rollover time is reduced to 1 minute and some 
seconds.

If you want to use the rollover-safe-timers in your program just copy `safeTimers.h` and
include it at the beginning of your program.
```
     #include "safeTimers.h"
```

