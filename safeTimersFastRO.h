/*
 * safeTimers.h (original name timers.h) is developed by Erik
 * 
 * Willem Aandewiel and Robert van den Breemen made some changes due 
 * to the "how can I handle the millis() rollover" by Edgar Bonet and added 
 * CHANGE_INTERVAL() and RESTART_TIMER() macro's
 *
 * see: https://arduino.stackexchange.com/questions/12587/how-can-i-handle-the-millis-rollover
 * 
 * DECLARE_TIMER_MIN(timername, interval, {CATCH_UP_MISSED_EVENTS | SKIP_MISSED_EVENTS})     // interval in minutes
 * DECLARE_TIMER_SEC(timername, interval, {CATCH_UP_MISSED_EVENTS | SKIP_MISSED_EVENTS})     // interval in seconds
 * DECLARE_TIMER_MS(timername,  interval, {CATCH_UP_MISSED_EVENTS | SKIP_MISSED_EVENTS})     // interval in milliseconds
 * DECLARE_TIMER(timername,     interval, {CATCH_UP_MISSED_EVENTS | SKIP_MISSED_EVENTS})     // interval in seconds
 *  Declares two uint32_t's: 
 *    <timername>_due for next execution
 *    <timername>_interval for interval in seconds
 *    <timername>_skip boolean skip 'missed' events
 * 
 * TIME_LEFT_MIN(timerName)
 *  returns the time left in minutes
 * TIME_LEFT_SEC(timerName)
 *  returns the time left in seconds
 * TIME_LEFT_MS(timerName)
 *  returns the time left in milliseconds
 * TIME_LEFT_M(timerName)
 *  returns the time left in seconds
 * 
 * CHANGE_INTERVAL_MIN(timername, interval, {CATCH_UP_MISSED_EVENTS | SKIP_MISSED_EVENTS})
 * CHANGE_INTERVAL_SEC(timername, interval, {CATCH_UP_MISSED_EVENTS | SKIP_MISSED_EVENTS})
 * CHANGE_INTERVAL_MS(timername,  interval, {CATCH_UP_MISSED_EVENTS | SKIP_MISSED_EVENTS})
 * CHANGE_INTERVAL(timername,     interval, {CATCH_UP_MISSED_EVENTS | SKIP_MISSED_EVENTS})
 *  Changes the uint32_t's declared by DECLARE_TIMER(): 
 *    <timername>_due for next execution
 *    <timername>_interval for interval in seconds
 *    <timername>_skip (boolean) skip 'missed' due's
 *    
 * RESTART_TIMER(timername)
 *  Changes the uint32_t declared by DECLARE_TIMER(): 
 *    <timername>_due = millis() + <timername>_interval
 *    
 * DUE(timername) 
 *  returns false (0) if interval hasn't elapsed since last DUE-time
 *          true (current millis) if it has
 *  updates <timername>_due
 *  
 *  Usage example:
 *  
 *  DECLARE_TIMER(screenUpdate, 200, SKIP_MISSED_EVENTS)          // update screen every 200 ms
 *  ...
 *  loop()
 *  {
 *  ..
 *    if ( DUE(screenUpdate) ) {
 *      // update screen code
 *    }
 *    
 *    // to change the screenUpdate interval:
 *    CHANGE_INTERVAL(screenUpdate, 500, CATCH_UP_MISSED_EVENTS); // change interval to 500 ms
 *    
 *    // to restart the screenUpdate interval:
 *    RESTART_TIMER(screenUpdate);                                // restart timer so next DUE is in 500ms
 *  }
 *  
 */

#define SKIP_MISSED_EVENTS      0
#define CATCH_UP_MISSED_EVENTS  1

#define DECLARE_TIMER_MIN(timerName, timerTime, doSkip) \
                                          static uint32_t timerName##_interval = (timerTime * 60 * 1000 * 1000), \
                                          timerName##_due = micros()+timerName##_interval               \
                                                               +random(timerName##_interval / 3);       \
                                          static bool timerName##_skip = doSkip;
#define DECLARE_TIMER_SEC(timerName, timerTime, doSkip) \
                                          static uint32_t timerName##_interval = (timerTime * 1000 * 1000),     \
                                                  timerName##_due = micros()+timerName##_interval               \
                                                               +random(timerName##_interval / 3);       \
                                          static bool timerName##_skip = doSkip;
#define DECLARE_TIMER_MS(timerName, timerTime, doSkip)  \
                                          static uint32_t timerName##_interval = (timerTime * 1000),    \
                                          timerName##_due = micros()+timerName##_interval               \
                                                               +random(timerName##_interval / 3);       \
                                          static bool timerName##_skip = doSkip;

#define DECLARE_TIMER   DECLARE_TIMER_MS

#define CHANGE_INTERVAL_MIN(timerName, timerTime, doSkip) \
                                          timerName##_interval = (timerTime * 60 * 1000 * 1000);\
                                          timerName##_due = micros()+timerName##_interval;      \
                                          timerName##_skip = doSkip;
#define CHANGE_INTERVAL_SEC(timerName, timerTime, doSkip) \
                                          timerName##_interval = (timerTime * 1000 * 1000);     \
                                          timerName##_due = micros()+timerName##_interval;      \
                                          timerName##_skip = doSkip;
#define CHANGE_INTERVAL_MS(timerName, timerTime, doSkip)  \
                                          timerName##_interval = (timerTime * 1000);            \
                                          timerName##_due = micros()+timerName##_interval;      \
                                          timerName##_skip = doSkip;

#define CHANGE_INTERVAL CHANGE_INTERVAL_MS

#define TIME_LEFT(timerName)          ( __TIME_LEFT__(timerName##_due, timerName##_interval) ) 
#define TIME_LEFT_MS(timerName)       ( (TIME_LEFT(timerName) ) )
#define TIME_LEFT_MIN(timerName)      ( (TIME_LEFT(timerName) ) / (60 * 1000))
#define TIME_LEFT_SEC(timerName)      ( (TIME_LEFT(timerName) ) / 1000 )

#define TIME_PAST(timerName)          ( (timerName##_interval - TIME_LEFT(timerName)) )
#define TIME_PAST_MS(timerName)       ( (TIME_PAST(timerName) )
#define TIME_PAST_SEC(timerName)      ( (TIME_PAST(timerName) / 1000) )
#define TIME_PAST_MIN(timerName)      ( (TIME_PAST(timerName) / (60*1000)) )

#define RESTART_TIMER(timerName)      ( timerName##_due = micros()+timerName##_interval ); 

#define DUE(timerName)                ( __DUE__(timerName##_due, timerName##_interval, timerName##_skip) )


uint32_t __DUE__(uint32_t &timer_due, uint32_t timer_interval, uint8_t doSkip)
{
  if ((int32_t)(micros() - timer_due) >= 0) 
  {
    switch (doSkip) {
        case 1:   timer_due += timer_interval;
                  break;
        default:  timer_due = micros() + timer_interval;
                  break;
    }
    return timer_due;  
  }
  
  return 0;
  
} // __DUE__()


uint16_t __TIME_LEFT__(uint16_t timer_due, uint16_t timer_interval)
{
  uint16 tmp;
  if ((timer_due - micros()) >= 0)
  {
    tmp = timer_due - micros();
  }
  else
  {
    tmp = ((timer_due+ UINT16_MAX) - micros());
  }
  //--- ok, this is a bit silly but will normaly 
  //--- only occur once every 49 day's
  while (tmp >= timer_interval)
  {
    tmp -= timer_interval;
    yield();
  }
  return tmp;
  
} // __TIME_LEFT__()

/*
 *  16 bit timers macro's for testing purposes
 */

uint16_t timer16Bit()
{
  return ((millis() & 0b1111111111111111)); // only 16 bits
  
} // timer16Bit()

#define DECLARE_16BIT_TIMER(timerName, timerTime, doSkip)  \
                                            static uint16_t timerName##_interval = timerTime,         \
                                            timerName##_due  = timer16Bit()                           \
                                                                  +timerName##_interval               \
                                                                  +random(timerName##_interval / 3);  \
                                            static bool timerName##_skip = doSkip;

#define CHANGE_16BIT_INTERVAL(timerName, timerTime, doSkip) \
                                            timerName##_interval = timerTime;                         \
                                            timerName##_due = micros()+timerName##_interval;          \
                                            timerName##_skip = doSkip;
                                                    
#define RESTART_16BIT_TIMER(timerName)      timerName##_due = timer16Bit()+timerName##_interval;

#define TIME_LEFT_16BIT(timerName)          ( __TIME_LEFT_16BIT__(timerName##_due, timerName##_interval) ) 
#define TIME_LEFT_SEC_16BIT(timerName)      ( (TIME_LEFT_16BIT(timerName) / 1000) )

#define TIME_PAST_16BIT(timerName)          ( (timerName##_interval - TIME_LEFT_16BIT(timerName)) )
#define TIME_PAST_SEC_16BIT(timerName)      ( (TIME_PAST_16BIT(timerName) / 1000) )

#define DUE_16BIT(timerName)                ( __DUE_16BIT__(timerName##_due        \
                                                         , timerName##_interval \
                                                         , timerName##_skip) )


uint16_t __DUE_16BIT__(uint16_t &timer_due, uint16_t timer_interval, uint8_t doSkip)
{
  if ((int16_t)(timer16Bit() - timer_due) >= 0) 
  {
    switch (doSkip) {
        case 1:   timer_due += timer_interval;
                  break;
        default:  timer_due = timer16Bit() + timer_interval;
                  //onderstaande formule geeft exact hetzelfde resultaat als de regel hierboven
                  //timer_due  += (((timer16Bit() - timer_due) / timer_interval)+1 ) * timer_interval;
                  break;
    } // switch()
    
    return timer_due;  
  }
  
  return 0;

} // __DUE_16BIT__()


uint16_t __TIME_LEFT_16BIT__(uint16_t timer_due, uint16_t timer_interval)
{
  uint16 tmp;
  if ((timer_due - timer16Bit()) >= 0)
  {
    tmp = timer_due - timer16Bit();
  }
  else
  {
    tmp = ((timer_due+ UINT16_MAX) - timer16Bit());
  }
  //--- ok, this is a bit silly but will normaly 
  //--- only occur once every 49 day's
  while (tmp >= timer_interval)
  {
    tmp -= timer_interval;
    yield();
  }
  
  return tmp;
  
} // __TIME_LEFT_16BIT__()

/*
 * 
*/
