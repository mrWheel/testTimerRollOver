/*
 * safeTimers.h is initially created by Erik as timers.h
 * 
 * I made some changes due to the "how can I handle the micros() rollover"
 * by Edgar Bonet
 * 
 * DECLARE_TIMER(timername, interval)
 *  Declares four uint32_t var's: 
 *    <timername>_next for next execution
 *    <timername>_prev holds the previous execution time
 *    <timername>_interval for interval in seconds
 *    <timername>_refTime holds the timer value of the last DUE()
 *    
 *    
 * DECLARE_TIMER_MS is same as DECLARE_TIMER **but** uses microseconds!
 * DECLARE_TIMER_MIN is same as DECLARE_TIMER **but** uses minutes!
 *    
 * DUE(timername) 
 *  returns false (0) if interval hasn't elapsed since previous DUE-time
 *          true (current micros) if it has
 *  updates <timername>_next
 *  updates <timername>_prev
 *  updates <timername>_refTime
 *    
 *  RESTART_TIMER(timername)
 *   it restarts the timer
 *   updates <timername>_next
 *  
 *  Usage example:
 *  
 *  DECLARE_TIMER(screenUpdate, 200) // update screen every 200 ms
 *  ...
 *  setup()
 *  {
 *  ..
 *    RESTART_TIMER(screenUpdate);  // restart the timer for 200 ms!
 *  }
 *  ...
 *  loop()
 *  {
 *  ..
 *    if ( DUE(screenUpdate) ) {
 *      // update screen
 *    }
 *  }
 *  
 *  https://arduino.stackexchange.com/questions/12587/how-can-i-handle-the-micros-rollover
 *  
 */
 
#define DECLARE_TIMER_MIN(timerName, timerTime) static uint32_t timerName##_interval = timerTime * 60 * 1000 * 1000,          \
                                                timerName##_next = micros()+random(timerName##_interval,(timerName##_interval*1.5)),\
                                                timerName##_prev = micros(),                                                \
                                                timerName##_refTime = micros();
#define DECLARE_TIMER_SEC(timerName, timerTime) static uint32_t timerName##_interval = timerTime * 1000 * 1000,                \
                                                timerName##_next = micros()+random(timerName##_interval,(timerName##_interval*1.5)),\
                                                timerName##_prev = micros(),                                                \
                                                timerName##_refTime = micros();
#define DECLARE_TIMER_MS(timerName, timerTime)  static uint32_t timerName##_interval = timerTime * 1000,                       \
                                                timerName##_next = micros()+random(timerName##_interval,(timerName##_interval*1.5)),\ 
                                                timerName##_prev = micros(),                                                \
                                                timerName##_refTime = micros();

#define DECLARE_TIMER   DECLARE_TIMER_SEC

#define TIME_LEFT_MIN(timerName)                (__TIME_LEFT(timerName##_next, micros(), 60000) )
#define TIME_LEFT_SEC(timerName)                (__TIME_LEFT(timerName##_next, micros(),  1000) )
#define TIME_LEFT_MS(timerName)                 (__TIME_LEFT(timerName##_next, micros(),     1) )
#define TIME_LEFT     TIMER_LEFT_SEC

#define RESTART_TIMER(timerName)                { timerName##_next = micros()+timerName##_interval; }

#define DUE(timerName)                          (__DUE__(timerName##_next, timerName##_prev, \
                                                         timerName##_interval, timerName##_refTime) )

uint32_t __DUE__(uint32_t &next, uint32_t &prev, uint32_t interval, uint32_t &refTime)
{
  //  0<(t)--------------------------------(r)--(n)->MAX
  //  refTime > timer so a rollover has occured
  //  we now need to advance the 'next' until it also
  //  roll's over
  if (refTime > micros()) // rollover on timer occurd
  {
    Serial.printf("32Bit: [%u] rollover [%u].. next[%u] ", refTime, micros(), next);
    //  0<----------------------------(ni)------(n)->MAX
    //  we have to advance (next+interval) until it is > next
    while(next > (next+interval)) // add interval to next until it also roll's over
    {
      next += interval;
      Serial.print("+");
    }
    Serial.printf(" .. next[%u]\r\n", next);
    //  0<-(n)(n+i)--------------------------------->MAX
  }
  
  //  0<--(n)---------------------------------(p)->MAX
  //  prev > next so a rollover of next has occured
  //  we now need to advance time (wast) until the
  //  timer also roll's over
  if (prev > next) // rollover on next occurd
  {
    Serial.printf("32Bit: prev[%u] rollover next[%u] \r\n", prev, next);
    //--- now we need to wait for the timer to also rollover!
    Serial.printf("32Bit: wast some time: timer[%u][%d] ..", micros(), (micros()>>31));
    //  0<--------------------------------------(t)->MAX
    while((micros()>>31)) //--- wait for timer to rollover
    {
      //--- do some background tasks in here (to be implemented)
      //Serial.print("t");
      delay(10);
      yield();
    }
    Serial.printf(" .. new timer[%u]\r\n", micros());
    //  0(t)---------------------------------------MAX
  }

  //  now what if next > (timer + interval)??
  //  0<-------------(ti)------(n)---------------->MAX
  //  we obviously missed some next events and now we
  //  have to catch-up
  if (next > (micros() + interval))
  {
    Serial.printf("32Bit: catch-up: next > (timer+interval) => [%u] > [%u] ..", next, (micros()+interval));
    while (next > (micros()+interval) )
    {
      next+=interval;
      yield();
    }
    Serial.printf(".. timer[%u] next[%u]\r\n", micros(), next);
  }
  //  0<-------------------------(t)(n)---------->MAX


  prev  = next;
  if (micros() > next)  // timer is overdue
  {
    next   += interval;
    if ((next - micros()) < 1)  // if time left
    {
      next += interval; // make sure next > micros()!!!
    }
    refTime = micros();
    return next;  // set new next
  }
  refTime = micros();
  return 0;
}


uint32_t __TIME_LEFT(uint32_t sLast, uint32_t sTimer, uint32_t divider)
{
  if (sLast > sTimer) return ((sLast - sTimer) / (divider * 1000));
  return 0;
  
} // __TIME_LEFT()

//-------------------------------------------------------------------------------------
//--- to test the roll-over in a reasanable time frame I defined the same functions ---
//--- but with a 16 bit unsigned integer                                             ---
//--- Rollover takes place every ~65 seconds                                         ---
//-------------------------------------------------------------------------------------

uint16_t timer16Bit()
{
  return ((millis() & 0b1111111111111111)); // only 16 bits
  
} // timer16Bit()


#define DECLARE_16BIT_TIMER(timerName, timerTime)   static uint16_t timerName##_interval = timerTime,                                       \
                                                    timerName##_next = timer16Bit()+random(timerName##_interval,(timerName##_interval*1.5)),\
                                                    timerName##_prev = timer16Bit(),                                                        \
                                                    timerName##_refTime = timer16Bit();

#define RESTART_16BIT_TIMER(timerName)              { timerName##_next = timer16Bit()+timerName##_interval; }

#define TIME_LEFT_16BIT(timerName)                  (__TIME_LEFT_16BIT(timerName##_next))

#define DUE_16BIT(timerName) (__DUE_16BIT(timerName##_next, timerName##_prev, timerName##_interval, timerName##_refTime) )

uint16_t __DUE_16BIT(uint16_t &next, uint16_t &prev, uint16_t interval, uint16_t &refTime)
{
  //  0<(t)--------------------------------(r)--(n)->MAX
  //  refTime > timer so a rollover has occured
  //  we now need to advance the 'next' until it also
  //  roll's over
  if (refTime > timer16Bit()) // rollover on timer occurd
  {
    Serial.printf("16Bit: [%d] rollover [%d].. next[%d] ", refTime, timer16Bit(), next);
    //  0<----------------------------(ni)------(n)->MAX
    //  we have to advance (next+interval) until it is > next
    while(next > (next+interval)) // add interval to next until it also roll's over
    {
      next += interval;
      Serial.print("+");
    }
    Serial.printf(" .. next[%d]\r\n", next);
    //  0<-(n)(n+i)--------------------------------->MAX
  }
  
  //  0<--(n)---------------------------------(p)->MAX
  //  prev > next so a rollover of next has occured
  //  we now need to advance time (wast) until the
  //  timer also roll's over
  if (prev > next) // rollover on next occurd
  {
    Serial.printf("16Bit: prev[%d] rollover next[%d] \r\n", prev, next);
    //--- now we need to wait for the timer to also rollover!
    Serial.printf("16Bit: wast some time: timer[%d][%d] ..", timer16Bit(), (timer16Bit()>>15));
    //  0<--------------------------------------(t)->MAX
    while((timer16Bit()>>15)) //--- wait for timer to rollover
    {
      //--- do some background tasks in here (to be implemented)
      //Serial.print("t");
      delay(10);
      yield();
    }
    Serial.printf(" .. new timer[%d]\r\n", timer16Bit());
    //  0<(t)--------------------------------------->MAX
  }

  //  now what if next > (timer + interval)??
  //  0<-------------(ti)------(n)---------------->MAX
  //  we obviously missed some next events and now we
  //  have to catch-up
  if (next > (timer16Bit() + interval))
  {
    Serial.printf("16Bit: catch-up: next > (timer+interval) => [%d] > [%d] ..", next, (timer16Bit()+interval));
    while (next > (timer16Bit()+interval) )
    {
      next+=interval;
      yield();
    }
    Serial.printf(".. timer[%d] next[%d]\r\n", timer16Bit(), next);
  }
  //  0<-------------------------(t)(n)---------->MAX


  prev  = next;
  if (timer16Bit() > next)  // timer is overdue
  {
    next   += interval;
    if ((next - timer16Bit()) < 1)  // if time left
    {
      next += interval; // make sure next > timer16Bit()!!!
    }
    refTime = timer16Bit();
    return next;  // set new next
  }
  refTime = timer16Bit();
  return 0;
}


uint16_t __TIME_LEFT_16BIT(uint16_t next)
{
  if (next > timer16Bit()) return (next - timer16Bit());
  return 0;
  
} // __TIME_LEFT_16BIT()

/* 
**      
** eof 
*/ 
