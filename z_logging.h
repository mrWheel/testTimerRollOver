***************************
* Date: 24-02-2020  12:50 *
***************************
Stresstest for safeTimersFastRO.h macro's 

---TYPE 0------SKIP_MISSED_TICKS--------------------------------------------------
 t1     t2     t3     t4     t5     t6     t7     t8     t9     t10    t11    t12
 |             |     <   processor    >            \      \
 |             |     <     bussy      >             \      \
 d1<int>d2<int>d3<....................>d4<int>d5<int>d6<int>d7<int>d8 enz
                      t4     t5     t6 missed
                            d3 --> d4 == longer then interval
                            d4 --> d5 (etc) == interval (shifted from time-ticks)

---TYPE 1------SKIP_MISSED_TICKS_WITH_SYNC-------------------------------------------------------
 t1     t2     t3     t4     t5     t6     t7     t8     t9     t10    t11    t12
 |             |     <   processor    >    |      |
 |             |     <     bussy      >    |      |
 d1<int>d2<int>d3<........................>d4<int>d5<int>d6<int>d7 enz
                      t4     t5     t6 missed
                            d3 --> d4 == longer then interval
                            d4 --> d5 (etc) == interval (always on time-ticks!)

---TYPE 2------CATCH_UP_MISSED_TICKS----------------------------------------------
 t1     t2     t3     t4     t5     t6     t7     t8     t9     t10    t11    t12
 |             |     <   processor   >            |      |
 |             |     <     bussy     >            |      |
 d1<int>d2<int>d3<...................>d4.d5.d6.d7.d8<int>d9<int>d10 enz
                            d3 --> d4 == longer then interval
                            d4>d5>d6>d7<.>d8 < less then interval, then sync to time-ticks
                            d8 --> d9 (etc) == interval  

Due_Test1[ 3000]ms Due_Test2[ 3000]ms Due_Test3[ 3000]ms Due_Test4[ 7500]ms Due_Test5[12000]ms 
testType1[0]       testType2[1]       testType3[2]       testType4[0]       testType5[0]       

[  630] StartTime[00:00:630]

[ 6630] [00:06:630]  .  .  .  .  .  .  .  .  .  .  .  .  .  => test1 runned! ([ 3.0]Sec.) -> 1_due[ 9630]
[ 7130]           [00:07:130]                               => test2 runned! ([ 3.0]Sec.) -> 2_due[10130]
[ 7630]                     [00:07:630]  .  .  .  .  .  .  .=> test3 runned! ([ 3.0]Sec.) -> 3_due[10630]
[ 9630] [00:09:630]                                         => test1 runned! ([ 3.0]Sec.) -> 1_due[12630]
[10022]                               [00:10:022]  .  .  .  => test4 runned! ([10.0]Sec.) -> 4_due[17522]
[10130]           [00:10:130]                               => test2 runned! ([ 3.0]Sec.) -> 2_due[13130]
[10630]                     [00:10:630]  .  .  .  .  .  .  .=> test3 runned! ([ 3.0]Sec.) -> 3_due[13630]
[12630] [00:12:630]                                         => test1 runned! ([ 3.0]Sec.) -> 1_due[15630]
[12640]                                         [00:12:640] => test5 runned! ([12.6]Sec.) -> 5_due[24640]
[13130]           [00:13:130]                               => test2 runned! ([ 3.0]Sec.) -> 2_due[16130]
[13630]                     [00:13:630]  .  .  .  .  .  .  .=> test3 runned! ([ 3.0]Sec.) -> 3_due[16630]
[15630] [00:15:630]                                         => test1 runned! ([ 3.0]Sec.) -> 1_due[18630]
[16130]           [00:16:130]  .  .  .  .  .  .  .  .  .  . => test2 runned! ([ 3.0]Sec.) -> 2_due[19130]
[16630]                     [00:16:630]                     => test3 runned! ([ 3.0]Sec.) -> 3_due[19630]
[17522]                               [00:17:522]  .  .  .  => test4 runned! ([ 7.5]Sec.) -> 4_due[25022]
[18630] [00:18:630]                                         => test1 runned! ([ 3.0]Sec.) -> 1_due[21630]
[19130]           [00:19:130]  .  .  .  .  .  .  .  .  .  . => test2 runned! ([ 3.0]Sec.) -> 2_due[22130]
[19630]                     [00:19:630]                     => test3 runned! ([ 3.0]Sec.) -> 3_due[22630]
[21630] [00:21:630]  .  .  .  .  .  .  .  .  .  .  .  .  .  => test1 runned! ([ 3.0]Sec.) -> 1_due[24630]
[22130]           [00:22:130]                               => test2 runned! ([ 3.0]Sec.) -> 2_due[25130]
[22630]                     [00:22:630]  .  .  .  .  .  .  .=> test3 runned! ([ 3.0]Sec.) -> 3_due[25630]
[24630] [00:24:630]                                         => test1 runned! ([ 3.0]Sec.) -> 1_due[27630]
[24640]                                         [00:24:640] => test5 runned! ([12.0]Sec.) -> 5_due[36640]
[25022]                               [00:25:022]           => test4 runned! ([ 7.5]Sec.) -> 4_due[32522]
[25130]           [00:25:130]  .  .  .  .  .  .  .  .  .  . => test2 runned! ([ 3.0]Sec.) -> 2_due[28130]
[25630]                     [00:25:630]                     => test3 runned! ([ 3.0]Sec.) -> 3_due[28630]
[27630] [00:27:630]  .  .  .  .  .  .  .  .  .  .  .  .  .  => test1 runned! ([ 3.0]Sec.) -> 1_due[30630]
[28130]           [00:28:130]                               => test2 runned! ([ 3.0]Sec.) -> 2_due[31130]
[28630]                     [00:28:630]  .  .  .  .  .  .  .=> test3 runned! ([ 3.0]Sec.) -> 3_due[31630]
[30630] [00:30:630]                                         => test1 runned! ([ 3.0]Sec.) -> 1_due[33630]
[31130]           [00:31:130]  .  .  .  .  .  .  .  .  .  . => test2 runned! ([ 3.0]Sec.) -> 2_due[34130]
[31630]                     [00:31:630]                     => test3 runned! ([ 3.0]Sec.) -> 3_due[34630]
[32522]                               [00:32:522]  .  .  .  => test4 runned! ([ 7.5]Sec.) -> 4_due[40022]
[33630] [00:33:630]                                         => test1 runned! ([ 3.0]Sec.) -> 1_due[36630]
[34130]           [00:34:130]  .  .  .  .  .  .  .  .  .  . => test2 runned! ([ 3.0]Sec.) -> 2_due[37130]
[34630]                     [00:34:630]                     => test3 runned! ([ 3.0]Sec.) -> 3_due[37630]
[36630] [00:36:630]  .  .  .  .  .  .  .  .  .  .  .  .  .  => test1 runned! ([ 3.0]Sec.) -> 1_due[39630]
[36640]                                         [00:36:640] => test5 runned! ([12.0]Sec.) -> 5_due[48640]
[37130]           [00:37:130]  .  .  .  .  .  .  .  .  .  . => test2 runned! ([ 3.0]Sec.) -> 2_due[40130]
[37630]                     [00:37:630]                     => test3 runned! ([ 3.0]Sec.) -> 3_due[40630]
[39630] [00:39:630]  .  .  .  .  .  .  .  .  .  .  .  .  .  => test1 runned! ([ 3.0]Sec.) -> 1_due[42630]
[40022]                               [00:40:022]           => test4 runned! ([ 7.5]Sec.) -> 4_due[47522]
[40130]           [00:40:130]  .  .  .  .  .  .  .  .  .  . => test2 runned! ([ 3.0]Sec.) -> 2_due[43130]
[40630]                     [00:40:630]                     => test3 runned! ([ 3.0]Sec.) -> 3_due[43630]

[41630] test1 counted[13] times run in [13] events --> EQUAL
[41630] test2 counted[13] times run in [13] events --> EQUAL
[41631] test3 counted[13] times run in [13] events --> EQUAL
[41635] test4 counted[5] times run in [5] events --> EQUAL
[41640] test5 counted[3] times run in [3] events --> EQUAL

[41646] timerTest1: Time past/left [ 2016/  984]ms  next due after [42630]!
[41653] timerTest2: Time past/left [ 1523/ 1477]ms  next due after [43130]!
[41659] timerTest3: Time past/left [ 1029/ 1971]ms  next due after [43630]!
[41666] timerTest4: Time past/left [ 1644/ 5856]ms  next due after [47520]!
[41673] timerTest5: Time past/left [    5/    6]sec next due after [48640]!

[41679] wait ... wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww.. continue

[45683] startHolding: Time left [  84946]ms, [   84]sec, [ 1]min.
[45684] timerTest1: Time past/left [ 3000/    0]ms  next due after [45680]!
[45686] timerTest2: Time past/left [ 3000/    0]ms  next due after [45680]!
[45693] timerTest3: Time past/left [ 3000/    0]ms  next due after [45690]!
[45699] timerTest4: Time past/left [ 5677/ 1823]ms  next due after [47520]!
[45706] timerTest5: Time past/left [    9/    2]sec next due after [48640]!


[45713] [00:45:713]  .  .  .  .  .  .  .  .  .  .  .  .  .  => test1 runned! ([ 6.1]Sec.) -> 1_due[48713]
[45733]                     [00:45:733]                     => test3 runned! ([ 5.1]Sec.) -> 3_due[46630]
[46130]           [00:46:130]  .  .  .  .  .  .  .  .  .  . => test2 runned! ([ 6.0]Sec.) -> 2_due[49130]
[46630]                     [00:46:630]                     => test3 runned! ([ 0.9]Sec.) -> 3_due[49630]
[47522]                               [00:47:522]  .  .  .  => test4 runned! ([ 7.5]Sec.) -> 4_due[55022]
[48640]                                         [00:48:640] => test5 runned! ([12.0]Sec.) -> 5_due[60640]
[48713] [00:48:713]  .  .  .  .  .  .  .  .  .  .  .  .  .  => test1 runned! ([ 3.0]Sec.) -> 1_due[51713]
[49130]           [00:49:130]                               => test2 runned! ([ 3.0]Sec.) -> 2_due[52130]
[49630]                     [00:49:630]  .  .  .  .  .  .  .=> test3 runned! ([ 3.0]Sec.) -> 3_due[52630]
[51713] [00:51:713]                                         => test1 runned! ([ 3.0]Sec.) -> 1_due[54713]
[52130]           [00:52:130]  .  .  .  .  .  .  .  .  .  . => test2 runned! ([ 3.0]Sec.) -> 2_due[55130]
[52630]                     [00:52:630]                     => test3 runned! ([ 3.0]Sec.) -> 3_due[55630]
[54713] [00:54:713]  .  .  .  .  .  .  .  .  .  .  .  .  .  => test1 runned! ([ 3.0]Sec.) -> 1_due[57713]
[55022]                               [00:55:022]           => test4 runned! ([ 7.5]Sec.) -> 4_due[62522]
[55130]           [00:55:130]  .  .  .  .  .  .  .  .  .  . => test2 runned! ([ 3.0]Sec.) -> 2_due[58130]
[55630]                     [00:55:630]                     => test3 runned! ([ 3.0]Sec.) -> 3_due[58630]
[57713] [00:57:713]  .  .  .  .  .  .  .  .  .  .  .  .  .  => test1 runned! ([ 3.0]Sec.) -> 1_due[60713]
[58130]           [00:58:130]                               => test2 runned! ([ 3.0]Sec.) -> 2_due[61130]
[58630]                     [00:58:630]  .  .  .  .  .  .  .=> test3 runned! ([ 3.0]Sec.) -> 3_due[61630]
[60640]                                         [01:00:640] => test5 runned! ([12.0]Sec.) -> 5_due[ 7104]
[60713] [01:00:713]  .  .  .  .  .  .  .  .  .  .  .  .  .  => test1 runned! ([ 3.0]Sec.) -> 1_due[63713]
[61130]           [01:01:130]                               => test2 runned! ([ 3.0]Sec.) -> 2_due[64130]
[61630]                     [01:01:630]  .  .  .  .  .  .  .=> test3 runned! ([ 3.0]Sec.) -> 3_due[64630]
[62522]                               [01:02:522]           => test4 runned! ([ 7.5]Sec.) -> 4_due[ 4486]
[63713] [01:03:713]  .  .  .  .  .  .  .  .  .  .  .  .  .  => test1 runned! ([ 3.0]Sec.) -> 1_due[ 1177]
[64130]           [01:04:130]                               => test2 runned! ([ 3.0]Sec.) -> 2_due[ 1594]
[64630]                     [01:04:630]  .  .  .  .  .  .  .=> test3 runned! ([ 3.0]Sec.) -> 3_due[ 2094]

[    0] ***** timer16Bit() has rolled-over! *****

[    0] timerTest1: Time past/left [ 1823/ 1177]ms  next due after [ 1170]!
[    0] timerTest2: Time past/left [ 1406/ 1594]ms  next due after [ 1590]!
[    7] timerTest3: Time past/left [  913/ 2087]ms  next due after [ 2090]!
[   13] timerTest4: Time past/left [ 3027/ 4473]ms  next due after [ 4480]!
[   20] timerTest5: Time past/left [    4/    7]sec next due after [ 7100]!

[ 1177] [01:06:713]                                         => test1 runned! ([ 3.0]Sec.) -> 1_due[ 4177]
[ 1594]           [01:07:130]  .  .  .  .  .  .  .  .  .  . => test2 runned! ([ 3.0]Sec.) -> 2_due[ 4594]
[ 2094]                     [01:07:630]                     => test3 runned! ([ 3.0]Sec.) -> 3_due[ 5094]
[ 4177] [01:09:713]  .  .  .  .  .  .  .  .  .  .  .  .  .  => test1 runned! ([ 3.0]Sec.) -> 1_due[ 7177]
[ 4486]                               [01:10:022]           => test4 runned! ([ 7.5]Sec.) -> 4_due[11986]
[ 4594]           [01:10:130]  .  .  .  .  .  .  .  .  .  . => test2 runned! ([ 3.0]Sec.) -> 2_due[ 7594]
      .
      .
      .
      .
[53094]                     [01:58:630]                     => test3 runned! ([ 3.0]Sec.) -> 3_due[56094]
[55104]                                         [02:00:640] => test5 runned! ([12.0]Sec.) -> 5_due[ 1568]
[55261] [02:00:797]                                         => test1 runned! ([ 3.0]Sec.) -> 1_due[58261]
[55594]           [02:01:130]  .  .  .  .  .  .  .  .  .  . => test2 runned! ([ 3.0]Sec.) -> 2_due[58594]
[56094]                     [02:01:630]                     => test3 runned! ([ 3.0]Sec.) -> 3_due[59094]
[56986]                               [02:02:522]  .  .  .  => test4 runned! ([ 7.5]Sec.) -> 4_due[64486]
[58261] [02:03:797]                                         => test1 runned! ([ 3.0]Sec.) -> 1_due[61261]
[58594]           [02:04:130]  .  .  .  .  .  .  .  .  .  . => test2 runned! ([ 3.0]Sec.) -> 2_due[61594]
[59094]                     [02:04:630]                     => test3 runned! ([ 3.0]Sec.) -> 3_due[62094]
[61261] [02:06:797]  .  .  .  .  .  .  .  .  .  .  .  .  .  => test1 runned! ([ 3.0]Sec.) -> 1_due[64261]
[61594]           [02:07:130]                               => test2 runned! ([ 3.0]Sec.) -> 2_due[64594]
[62094]                     [02:07:630]  .  .  .  .  .  .  .=> test3 runned! ([ 3.0]Sec.) -> 3_due[65094]
[64261] [02:09:797]                                         => test1 runned! ([ 3.0]Sec.) -> 1_due[ 1725]
[64486]                               [02:10:022]  .  .  .  => test4 runned! ([ 7.5]Sec.) -> 4_due[ 6450]
[64594]           [02:10:130]                               => test2 runned! ([ 3.0]Sec.) -> 2_due[ 2058]
[65094]                     [02:10:630]  .  .  .  .  .  .  .=> test3 runned! ([ 3.0]Sec.) -> 3_due[ 2558]

[65104] timerTest1: Time past/left [  844/ 2156]ms  next due after [67260]!
[65104] timerTest2: Time past/left [  511/ 2489]ms  next due after [67590]!
[65107] timerTest3: Time past/left [   14/ 2986]ms  next due after [68090]!
[65113] timerTest4: Time past/left [  628/ 6872]ms  next due after [71980]!
[65120] timerTest5: Time past/left [   10/    1]sec next due after [67100]!


[65127] hold ... 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1 .. continue
************************* using Random Delays from here on ***********************

[14596] startWaiting: Time left [      0]ms, [    0]sec., [ 0]min.

[14599] timerTest1: Time past/left [ 3000/    0]ms  next due after [14590]!
[14606] timerTest2: Time past/left [ 3000/    0]ms  next due after [14600]!
[14613] timerTest3: Time past/left [ 3000/    0]ms  next due after [14610]!
[14619] timerTest4: Time past/left [ 7500/    0]ms  next due after [14610]!
[14626] timerTest5: Time past/left [   12/    0]sec next due after [14620]!


[14672] [02:25:744]                                         => test1 runned! ([15.9]Sec.) -> 1_due[17672]
[14683]                     [02:25:755]  .  .  .  .  .  .  .=> test3 runned! ([15.1]Sec.) -> 3_due[ 5558]
[14693]                               [02:25:765]           => test4 runned! ([15.7]Sec.) -> 4_due[22193]
[14703]                                         [02:25:775] => test5 runned! ([25.1]Sec.) -> 5_due[26703]
[14733]                     [02:25:805]                     => test3 runned! ([ 0.1]Sec.) -> 3_due[ 8558]
[14819]                     [02:25:891]  .  .  .  .  .  .  .=> test3 runned! ([ 0.1]Sec.) -> 3_due[11558]
[15066]                     [02:26:138]                     => test3 runned! ([ 0.2]Sec.) -> 3_due[14558]
[15095]                     [02:26:167]  .  .  .  .  .  .  .=> test3 runned! ([ 0.0]Sec.) -> 3_due[17558]
[17145]           [02:28:217]                               => test2 runned! ([18.1]Sec.) -> 2_due[20058]
[17619]                     [02:28:691]  .  .  .  .  .  .  .=> test3 runned! ([ 2.5]Sec.) -> 3_due[20558]
[17812] [02:28:884]                                         => test1 runned! ([ 3.1]Sec.) -> 1_due[20812]
[20148]           [02:31:220]  .  .  .  .  .  .  .  .  .  . => test2 runned! ([ 3.0]Sec.) -> 2_due[23058]
[20742]                     [02:31:814]                     => test3 runned! ([ 3.1]Sec.) -> 3_due[23558]
[20880] [02:31:952]  .  .  .  .  .  .  .  .  .  .  .  .  .  => test1 runned! ([ 3.1]Sec.) -> 1_due[23880]
[22273]                               [02:33:345]           => test4 runned! ([ 7.6]Sec.) -> 4_due[29773]
[23190]           [02:34:262]  .  .  .  .  .  .  .  .  .  . => test2 runned! ([ 3.0]Sec.) -> 2_due[26058]
[23600]                     [02:34:672]                     => test3 runned! ([ 2.9]Sec.) -> 3_due[26558]
[23880] [02:34:952]  .  .  .  .  .  .  .  .  .  .  .  .  .  => test1 runned! ([ 3.0]Sec.) -> 1_due[26880]
[26204]           [02:37:276]                               => test2 runned! ([ 3.0]Sec.) -> 2_due[29058]
[26644]                     [02:37:716]  .  .  .  .  .  .  .=> test3 runned! ([ 3.0]Sec.) -> 3_due[29558]
[26804]                                         [02:37:876] => test5 runned! ([12.1]Sec.) -> 5_due[38804]
[27022] [02:38:094]  .  .  .  .  .  .  .  .  .  .  .  .  .  => test1 runned! ([ 3.1]Sec.) -> 1_due[30022]
[29206]           [02:40:278]                               => test2 runned! ([ 3.0]Sec.) -> 2_due[32058]
[29619]                     [02:40:691]  .  .  .  .  .  .  .=> test3 runned! ([ 3.0]Sec.) -> 3_due[32558]
[29870]                               [02:40:942]           => test4 runned! ([ 7.6]Sec.) -> 4_due[37370]
[30119] [02:41:192]  .  .  .  .  .  .  .  .  .  .  .  .  .  => test1 runned! ([ 3.1]Sec.) -> 1_due[33119]
[32172]           [02:43:244]                               => test2 runned! ([ 3.0]Sec.) -> 2_due[35058]
[32711]                     [02:43:783]  .  .  .  .  .  .  .=> test3 runned! ([ 3.1]Sec.) -> 3_due[35558]
[33160] [02:44:232]                                         => test1 runned! ([ 3.0]Sec.) -> 1_due[36160]
[35578]                     [02:46:650]  .  .  .  .  .  .  .=> test3 runned! ([ 2.9]Sec.) -> 3_due[38558]
[36190] [02:47:262]                                         => test1 runned! ([ 3.0]Sec.) -> 1_due[39190]
[37377]                               [02:48:449]  .  .  .  => test4 runned! ([ 7.5]Sec.) -> 4_due[44877]
[38157]           [02:49:229]                               => test2 runned! ([ 6.0]Sec.) -> 2_due[41058]
[38566]                     [02:49:638]  .  .  .  .  .  .  .=> test3 runned! ([ 3.0]Sec.) -> 3_due[41558]
[38963]                                         [02:50:035] => test5 runned! ([12.2]Sec.) -> 5_due[50963]
[39219] [02:50:291]  .  .  .  .  .  .  .  .  .  .  .  .  .  => test1 runned! ([ 3.0]Sec.) -> 1_due[42219]
[41071]           [02:52:143]                               => test2 runned! ([ 2.9]Sec.) -> 2_due[44058]
      .
      .
[ 3754] [04:25:898]                                         => test1 runned! ([ 3.1]Sec.) -> 1_due[ 6754]
      .
      .
[ 4738]                                         [04:26:882] => test5 runned! ([12.2]Sec.) -> 5_due[16738]
[ 6052]           [04:28:196]                               => test2 runned! ([ 3.0]Sec.) -> 2_due[ 8986]
[ 6172]                               [04:28:316]  .  .  .  => test4 runned! ([ 7.5]Sec.) -> 4_due[13672]
[ 6634]                     [04:28:778]                     => test3 runned! ([ 3.1]Sec.) -> 3_due[ 9486]
[ 6850] [04:28:994]  .  .  .  .  .  .  .  .  .  .  .  .  .  => test1 runned! ([ 3.1]Sec.) -> 1_due[ 9850]
[ 9070]           [04:31:214]                               => test2 runned! ([ 3.0]Sec.) -> 2_due[11986]
[ 9514]                     [04:31:658]  .  .  .  .  .  .  .=> test3 runned! ([ 2.9]Sec.) -> 3_due[12486]
[ 9958] [04:32:102]                                         => test1 runned! ([ 3.1]Sec.) -> 1_due[12958]
[12545]                     [04:34:689]  .  .  .  .  .  .  .=> test3 runned! ([ 3.0]Sec.) -> 3_due[15486]
[12958] [04:35:102]                                         => test1 runned! ([ 3.0]Sec.) -> 1_due[15958]

[13633] timerTest1: Time past/left [  675/ 2325]ms  next due after [15950]!
[13634] timerTest2: Time past/left [ 1648/ 1352]ms  next due after [14980]!
[13636] timerTest3: Time past/left [ 1150/ 1850]ms  next due after [15480]!
[13643] timerTest4: Time past/left [ 7471/   29]ms  next due after [13670]!
[13649] timerTest5: Time past/left [    8/    3]sec next due after [16730]!


[13656] hold ... 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1 .. continue
*********************** using NO random delays! from here on *********************

[28661] startWaiting: Time left [      0]ms, [    0]sec., [ 0]min.

[28665] timerTest1: Time past/left [ 3000/    0]ms  next due after [28660]!
[28671] timerTest2: Time past/left [ 3000/    0]ms  next due after [28670]!
[28678] timerTest3: Time past/left [ 3000/    0]ms  next due after [28670]!
[28685] timerTest4: Time past/left [ 7500/    0]ms  next due after [28680]!
[28691] timerTest5: Time past/left [   12/    0]sec next due after [28690]!


[28699] [04:50:843]  .  .  .  .  .  .  .  .  .  .  .  .  .  => test1 runned! ([15.7]Sec.) -> 1_due[31699]
[28719]                     [04:50:863]                     => test3 runned! ([16.2]Sec.) -> 3_due[18486]
[28729]                               [04:50:873]  .  .  .  => test4 runned! ([22.6]Sec.) -> 4_due[36229]
[28739]                                         [04:50:883] => test5 runned! ([24.0]Sec.) -> 5_due[40739]
[28749]                     [04:50:893]  .  .  .  .  .  .  .=> test3 runned! ([ 0.0]Sec.) -> 3_due[21486]
[28759]                     [04:50:903]                     => test3 runned! ([ 0.0]Sec.) -> 3_due[24486]
[28769]                     [04:50:913]  .  .  .  .  .  .  .=> test3 runned! ([ 0.0]Sec.) -> 3_due[27486]
[28779]                     [04:50:923]                     => test3 runned! ([ 0.0]Sec.) -> 3_due[30486]
[29986]           [04:52:130]  .  .  .  .  .  .  .  .  .  . => test2 runned! ([20.9]Sec.) -> 2_due[32986]
[30486]                     [04:52:630]                     => test3 runned! ([ 1.7]Sec.) -> 3_due[33486]
[31699] [04:53:843]  .  .  .  .  .  .  .  .  .  .  .  .  .  => test1 runned! ([ 3.0]Sec.) -> 1_due[34699]
[32986]           [04:55:130]                               => test2 runned! ([ 3.0]Sec.) -> 2_due[35986]
[33486]                     [04:55:630]  .  .  .  .  .  .  .=> test3 runned! ([ 3.0]Sec.) -> 3_due[36486]
[34699] [04:56:843]                                         => test1 runned! ([ 3.0]Sec.) -> 1_due[37699]
[35986]           [04:58:130]  .  .  .  .  .  .  .  .  .  . => test2 runned! ([ 3.0]Sec.) -> 2_due[38986]
[36229]                               [04:58:373]           => test4 runned! ([ 7.5]Sec.) -> 4_due[43729]
[36486]                     [04:58:630]  .  .  .  .  .  .  .=> test3 runned! ([ 3.0]Sec.) -> 3_due[39486]
[37699] [04:59:843]                                         => test1 runned! ([ 3.0]Sec.) -> 1_due[40699]


***************************************************************************
*********************** timer32bit() Rolled Over ***************************
****************** next Rolloverin 1 hour and 6 minutes *******************
***************************************************************************


[38986]           [05:01:130]  .  .  .  .  .  .  .  .  .  . => test2 runned! ([ 3.0]Sec.) -> 2_due[41986]
[39486]                     [05:01:630]                     => test3 runned! ([ 3.0]Sec.) -> 3_due[42486]
[40699] [05:02:843]  .  .  .  .  .  .  .  .  .  .  .  .  .  => test1 runned! ([ 3.0]Sec.) -> 1_due[43699]
[40739]                                         [05:02:883] => test5 runned! ([12.0]Sec.) -> 5_due[52739]
[41986]           [05:04:130]  .  .  .  .  .  .  .  .  .  . => test2 runned! ([ 3.0]Sec.) -> 2_due[44986]
[42486]                     [05:04:630]                     => test3 runned! ([ 3.0]Sec.) -> 3_due[45486]
[43699] [05:05:843]  .  .  .  .  .  .  .  .  .  .  .  .  .  => test1 runned! ([ 3.0]Sec.) -> 1_due[46699]
[43729]                               [05:05:873]           => test4 runned! ([ 7.5]Sec.) -> 4_due[51229]
[44986]           [05:07:130]  .  .  .  .  .  .  .  .  .  . => test2 runned! ([ 3.0]Sec.) -> 2_due[47986]
[45486]                     [05:07:630]                     => test3 runned! ([ 3.0]Sec.) -> 3_due[48486]
[46699] [05:08:843]  .  .  .  .  .  .  .  .  .  .  .  .  .  => test1 runned! ([ 3.0]Sec.) -> 1_due[49699]
[47986]           [05:10:130]                               => test2 runned! ([ 3.0]Sec.) -> 2_due[50986]
[48486]                     [05:10:630]  .  .  .  .  .  .  .=> test3 runned! ([ 3.0]Sec.) -> 3_due[51486]
[49699] [05:11:843]                                         => test1 runned! ([ 3.0]Sec.) -> 1_due[52699]
[50986]           [05:13:130]  .  .  .  .  .  .  .  .  .  . => test2 runned! ([ 3.0]Sec.) -> 2_due[53986]
[51229]                               [05:13:373]           => test4 runned! ([ 7.5]Sec.) -> 4_due[58729]
[51486]                     [05:13:630]  .  .  .  .  .  .  .=> test3 runned! ([ 3.0]Sec.) -> 3_due[54486]
[52699] [05:14:843]                                         => test1 runned! ([ 3.0]Sec.) -> 1_due[55699]
[52739]                                         [05:14:883] => test5 runned! ([12.0]Sec.) -> 5_due[64739]
[53986]           [05:16:130]                               => test2 runned! ([ 3.0]Sec.) -> 2_due[56986]
[54486]                     [05:16:630]  .  .  .  .  .  .  .=> test3 runned! ([ 3.0]Sec.) -> 3_due[57486]
[55699] [05:17:843]                                         => test1 runned! ([ 3.0]Sec.) -> 1_due[58699]
[56986]           [05:19:130]  .  .  .  .  .  .  .  .  .  . => test2 runned! ([ 3.0]Sec.) -> 2_due[59986]
[57486]                     [05:19:630]                     => test3 runned! ([ 3.0]Sec.) -> 3_due[60486]
[58699] [05:20:843]  .  .  .  .  .  .  .  .  .  .  .  .  .  => test1 runned! ([ 3.0]Sec.) -> 1_due[61699]
[58729]                               [05:20:873]           => test4 runned! ([ 7.5]Sec.) -> 4_due[  693]
[59986]           [05:22:130]  .  .  .  .  .  .  .  .  .  . => test2 runned! ([ 3.0]Sec.) -> 2_due[62986]
[60486]                     [05:22:630]                     => test3 runned! ([ 3.0]Sec.) -> 3_due[63486]
[61699] [05:23:843]  .  .  .  .  .  .  .  .  .  .  .  .  .  => test1 runned! ([ 3.0]Sec.) -> 1_due[64699]
[62986]           [05:25:130]                               => test2 runned! ([ 3.0]Sec.) -> 2_due[  450]
[63486]                     [05:25:630]  .  .  .  .  .  .  .=> test3 runned! ([ 3.0]Sec.) -> 3_due[  950]
[64699] [05:26:843]                                         => test1 runned! ([ 3.0]Sec.) -> 1_due[ 2163]
[64739]                                         [05:26:883] => test5 runned! ([12.0]Sec.) -> 5_due[11203]

[    0] ***** timer16Bit() has rolled-over! *****

[    0] timerTest1: Time past/left [  837/ 2163]ms  next due after [ 2160]!
[    0] timerTest2: Time past/left [ 2550/  450]ms  next due after [  450]!
[    7] timerTest3: Time past/left [ 2057/  943]ms  next due after [  950]!
[   13] timerTest4: Time past/left [ 6820/  680]ms  next due after [  690]!
[   20] timerTest5: Time past/left [    0/   11]sec next due after [11200]!

[  450]           [05:28:130]                               => test2 runned! ([ 3.0]Sec.) -> 2_due[ 3450]
[  693]                               [05:28:373]  .  .  .  => test4 runned! ([ 7.5]Sec.) -> 4_due[ 8193]
[  950]                     [05:28:630]                     => test3 runned! ([ 3.0]Sec.) -> 3_due[ 3950]
[ 2163] [05:29:843]  .  .  .  .  .  .  .  .  .  .  .  .  .  => test1 runned! ([ 3.0]Sec.) -> 1_due[ 5163]
[ 3450]           [05:31:130]                               => test2 runned! ([ 3.0]Sec.) -> 2_due[ 6450]
[ 3950]                     [05:31:630]  .  .  .  .  .  .  .=> test3 runned! ([ 3.0]Sec.) -> 3_due[ 6950]
[ 5163] [05:32:843]                                         => test1 runned! ([ 3.0]Sec.) -> 1_due[ 8163]
[ 6450]           [05:34:130]  .  .  .  .  .  .  .  .  .  . => test2 runned! ([ 3.0]Sec.) -> 2_due[ 9450]
[ 6950]                     [05:34:630]                     => test3 runned! ([ 3.0]Sec.) -> 3_due[ 9950]
[ 8163] [05:35:843]  .  .  .  .  .  .  .  .  .  .  .  .  .  => test1 runned! ([ 3.0]Sec.) -> 1_due[11163]
[ 8193]                               [05:35:873]           => test4 runned! ([ 7.5]Sec.) -> 4_due[15693]
[ 9450]           [05:37:130]  .  .  .  .  .  .  .  .  .  . => test2 runned! ([ 3.0]Sec.) -> 2_due[12450]
[ 9950]                     [05:37:630]                     => test3 runned! ([ 3.0]Sec.) -> 3_due[12950]
[11163] [05:38:843]  .  .  .  .  .  .  .  .  .  .  .  .  .  => test1 runned! ([ 3.0]Sec.) -> 1_due[14163]
[11203]                                         [05:38:883] => test5 runned! ([12.0]Sec.) -> 5_due[23203]
[12450]           [05:40:130]  .  .  .  .  .  .  .  .  .  . => test2 runned! ([ 3.0]Sec.) -> 2_due[15450]
[12950]                     [05:40:630]                     => test3 runned! ([ 3.0]Sec.) -> 3_due[15950]

[13336] test1 counted[99] times run in [113] events --> ? (14 off)
[13336] test2 counted[92] times run in [113] events --> ? (21 off)
[13337] test3 counted[113] times run in [113] events --> EQUAL
[13342] test4 counted[41] times run in [45] events --> ? (4 off)
[13348] test5 counted[26] times run in [28] events --> ? (2 off)

[13354] timerTest1: Time past/left [ 2191/  809]ms  next due after [14160]!
[13361] timerTest2: Time past/left [  911/ 2089]ms  next due after [15450]!
[13367] timerTest3: Time past/left [  417/ 2583]ms  next due after [15950]!
      .
      .
      .
      .
[19501]                               [06:52:717]  .  .  .  => test4 runned! ([ 7.5]Sec.) -> 4_due[27001]
[20971] [06:54:187]                                         => test1 runned! ([ 3.0]Sec.) -> 1_due[23971]
[21011]                                         [06:54:227] => test5 runned! ([12.0]Sec.) -> 5_due[33011]
[21914]           [06:55:130]                               => test2 runned! ([ 3.0]Sec.) -> 2_due[24914]
[22414]                     [06:55:630]  .  .  .  .  .  .  .=> test3 runned! ([ 3.0]Sec.) -> 3_due[25414]
[23971] [06:57:187]                                         => test1 runned! ([ 3.0]Sec.) -> 1_due[26971]
[24914]           [06:58:130]  .  .  .  .  .  .  .  .  .  . => test2 runned! ([ 3.0]Sec.) -> 2_due[27914]
[25414]                     [06:58:630]                     => test3 runned! ([ 3.0]Sec.) -> 3_due[28414]
[26971] [07:00:187]  .  .  .  .  .  .  .  .  .  .  .  .  .  => test1 runned! ([ 3.0]Sec.) -> 1_due[29971]
[27001]                               [07:00:217]           => test4 runned! ([ 7.5]Sec.) -> 4_due[34501]
[27914]           [07:01:130]  .  .  .  .  .  .  .  .  .  . => test2 runned! ([ 3.0]Sec.) -> 2_due[30914]
[28414]                     [07:01:630]                     => test3 runned! ([ 3.0]Sec.) -> 3_due[31414]
[29971] [07:03:187]  .  .  .  .  .  .  .  .  .  .  .  .  .  => test1 runned! ([ 3.0]Sec.) -> 1_due[32971]
[30914]           [07:04:130]                               => test2 runned! ([ 3.0]Sec.) -> 2_due[33914]
[31414]                     [07:04:630]  .  .  .  .  .  .  .=> test3 runned! ([ 3.0]Sec.) -> 3_due[34414]
[32971] [07:06:187]                                         => test1 runned! ([ 3.0]Sec.) -> 1_due[35971]
[33011]                                         [07:06:227] => test5 runned! ([12.0]Sec.) -> 5_due[45011]
[33914]           [07:07:130]                               => test2 runned! ([ 3.0]Sec.) -> 2_due[36914]
[34414]                     [07:07:630]  .  .  .  .  .  .  .=> test3 runned! ([ 3.0]Sec.) -> 3_due[37414]
[34501]                               [07:07:717]           => test4 runned! ([ 7.5]Sec.) -> 4_due[42001]
[35971] [07:09:187]  .  .  .  .  .  .  .  .  .  .  .  .  .  => test1 runned! ([ 3.0]Sec.) -> 1_due[38971]

[36800] timerTest1: Time past/left [  829/ 2171]ms  next due after [38970]!
[36800] timerTest2: Time past/left [ 2887/  113]ms  next due after [36910]!
[36803] timerTest3: Time past/left [ 2389/  611]ms  next due after [37410]!
[36809] timerTest4: Time past/left [ 2308/ 5192]ms  next due after [42000]!
[36816] timerTest5: Time past/left [    3/    8]sec next due after [45010]!


[36823] hold ... 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1 .. continue
************************* using Random Delays from here on ***********************

[51828] startWaiting: Time left [      0]ms, [    0]sec., [ 0]min.

[51831] timerTest1: Time past/left [ 3000/    0]ms  next due after [51830]!
[51838] timerTest2: Time past/left [ 3000/    0]ms  next due after [51830]!
[51845] timerTest3: Time past/left [ 3000/    0]ms  next due after [51840]!
[51851] timerTest4: Time past/left [ 7500/    0]ms  next due after [51850]!
[51858] timerTest5: Time past/left [   12/    0]sec next due after [51850]!


[52014] [07:25:230]                                         => test1 runned! ([16.0]Sec.) -> 1_due[55014]
[52025]                     [07:25:241]  .  .  .  .  .  .  .=> test3 runned! ([17.6]Sec.) -> 3_due[40414]
[52035]                               [07:25:251]           => test4 runned! ([17.5]Sec.) -> 4_due[59535]
[52045]                                         [07:25:261] => test5 runned! ([19.0]Sec.) -> 5_due[64045]
[52203]                     [07:25:419]                     => test3 runned! ([ 0.2]Sec.) -> 3_due[43414]
[52372]                     [07:25:588]  .  .  .  .  .  .  .=> test3 runned! ([ 0.2]Sec.) -> 3_due[46414]
[52613]                     [07:25:829]                     => test3 runned! ([ 0.2]Sec.) -> 3_due[49414]
[52728]                     [07:25:944]  .  .  .  .  .  .  .=> test3 runned! ([ 0.1]Sec.) -> 3_due[52414]
[52948]                     [07:26:164]                     => test3 runned! ([ 0.2]Sec.) -> 3_due[55414]
[54951]           [07:28:167]  .  .  .  .  .  .  .  .  .  . => test2 runned! ([21.0]Sec.) -> 2_due[57914]
[55042] [07:28:258]                                         => test1 runned! ([ 3.0]Sec.) -> 1_due[58042]
[55427]                     [07:28:643]  .  .  .  .  .  .  .=> test3 runned! ([ 2.5]Sec.) -> 3_due[58414]
[57930]           [07:31:146]                               => test2 runned! ([ 3.0]Sec.) -> 2_due[60914]
[58180] [07:31:396]  .  .  .  .  .  .  .  .  .  .  .  .  .  => test1 runned! ([ 3.1]Sec.) -> 1_due[61180]
[58587]                     [07:31:803]                     => test3 runned! ([ 3.2]Sec.) -> 3_due[61414]
[59640]                               [07:32:856]  .  .  .  => test4 runned! ([ 7.6]Sec.) -> 4_due[ 1604]
[60990]           [07:34:206]                               => test2 runned! ([ 3.1]Sec.) -> 2_due[63914]
[61215] [07:34:431]  .  .  .  .  .  .  .  .  .  .  .  .  .  => test1 runned! ([ 3.0]Sec.) -> 1_due[64215]
[61497]                     [07:34:713]                     => test3 runned! ([ 2.9]Sec.) -> 3_due[64414]
[63945]           [07:37:161]  .  .  .  .  .  .  .  .  .  . => test2 runned! ([ 3.0]Sec.) -> 2_due[ 1378]
[64058]                                         [07:37:274] => test5 runned! ([12.0]Sec.) -> 5_due[10522]
[64309] [07:37:525]  .  .  .  .  .  .  .  .  .  .  .  .  .  => test1 runned! ([ 3.1]Sec.) -> 1_due[ 1773]
[64635]                     [07:37:851]                     => test3 runned! ([ 3.1]Sec.) -> 3_due[ 1878]

[    9] ***** timer16Bit() has rolled-over! *****

[    9] timerTest1: Time past/left [ 1236/ 1764]ms  next due after [ 1770]!
[    9] timerTest2: Time past/left [ 1631/ 1369]ms  next due after [ 1370]!
[   16] timerTest3: Time past/left [ 1138/ 1862]ms  next due after [ 1870]!
[   22] timerTest4: Time past/left [ 5918/ 1582]ms  next due after [ 1600]!
[   29] timerTest5: Time past/left [    1/   10]sec next due after [10520]!

[ 1450]           [07:40:202]  .  .  .  .  .  .  .  .  .  . => test2 runned! ([ 3.0]Sec.) -> 2_due[ 4378]
[ 1653]                               [07:40:405]           => test4 runned! ([ 7.5]Sec.) -> 4_due[ 9153]
[ 1817] [07:40:569]  .  .  .  .  .  .  .  .  .  .  .  .  .  => test1 runned! ([ 3.0]Sec.) -> 1_due[ 4817]
[ 1941]                     [07:40:693]                     => test3 runned! ([ 2.8]Sec.) -> 3_due[ 4878]
[ 4984] [07:43:736]  .  .  .  .  .  .  .  .  .  .  .  .  .  => test1 runned! ([ 3.2]Sec.) -> 1_due[ 7984]
[ 4994]                     [07:43:746]                     => test3 runned! ([ 3.1]Sec.) -> 3_due[ 7878]
[ 7465]           [07:46:217]  .  .  .  .  .  .  .  .  .  . => test2 runned! ([ 6.0]Sec.) -> 2_due[10378]
[ 8005] [07:46:757]                                         => test1 runned! ([ 3.0]Sec.) -> 1_due[11005]
[ 8016]                     [07:46:768]  .  .  .  .  .  .  .=> test3 runned! ([ 3.0]Sec.) -> 3_due[10878]
[ 9278]                               [07:48:031]           => test4 runned! ([ 7.6]Sec.) -> 4_due[16778]
[10524]           [07:49:276]  .  .  .  .  .  .  .  .  .  . => test2 runned! ([ 3.1]Sec.) -> 2_due[13378]
[10534]                                         [07:49:286] => test5 runned! ([12.0]Sec.) -> 5_due[22534]
[11015] [07:49:767]  .  .  .  .  .  .  .  .  .  .  .  .  .  => test1 runned! ([ 3.0]Sec.) -> 1_due[14015]
[11025]                     [07:49:777]                     => test3 runned! ([ 3.0]Sec.) -> 3_due[13878]
[13495]           [07:52:247]  .  .  .  .  .  .  .  .  .  . => test2 runned! ([ 3.0]Sec.) -> 2_due[16378]
[13990]                     [07:52:742]                     => test3 runned! ([ 3.0]Sec.) -> 3_due[16878]
[14230] [07:52:982]  .  .  .  .  .  .  .  .  .  .  .  .  .  => test1 runned! ([ 3.2]Sec.) -> 1_due[17230]
[16469]           [07:55:221]                               => test2 runned! ([ 3.0]Sec.) -> 2_due[19378]
[16950]                     [07:55:702]  .  .  .  .  .  .  .=> test3 runned! ([ 3.0]Sec.) -> 3_due[19878]
[16960]                               [07:55:712]           => test4 runned! ([ 7.7]Sec.) -> 4_due[24460]
[17233] [07:55:985]  .  .  .  .  .  .  .  .  .  .  .  .  .  => test1 runned! ([ 3.0]Sec.) -> 1_due[20233]
[19449]           [07:58:201]                               => test2 runned! ([ 3.0]Sec.) -> 2_due[22378]
[20083]                     [07:58:835]  .  .  .  .  .  .  .=> test3 runned! ([ 3.1]Sec.) -> 3_due[22878]
[20303] [07:59:055]                                         => test1 runned! ([ 3.1]Sec.) -> 1_due[23303]
[22428]           [08:01:180]  .  .  .  .  .  .  .  .  .  . => test2 runned! ([ 3.0]Sec.) -> 2_due[25378]
[22624]                                         [08:01:376] => test5 runned! ([12.1]Sec.) -> 5_due[34624]
[22922]                     [08:01:674]  .  .  .  .  .  .  .=> test3 runned! ([ 2.8]Sec.) -> 3_due[25878]
[23323] [08:02:075]                                         => test1 runned! ([ 3.0]Sec.) -> 1_due[26322]
[24514]                               [08:03:266]  .  .  .  => test4 runned! ([ 7.6]Sec.) -> 4_due[32014]
[25416]           [08:04:168]                               => test2 runned! ([ 3.0]Sec.) -> 2_due[28378]
[25982]                     [08:04:734]  .  .  .  .  .  .  .=> test3 runned! ([ 3.1]Sec.) -> 3_due[28878]
[26467] [08:05:219]                                         => test1 runned! ([ 3.1]Sec.) -> 1_due[29467]

[27424] test1 counted[141] times run in [161] events --> ? (20 off)
[27425] test2 counted[131] times run in [161] events --> ? (30 off)
[27425] test3 counted[161] times run in [161] events --> EQUAL
[27431] test4 counted[59] times run in [64] events --> ? (5 off)
[27437] test5 counted[37] times run in [40] events --> ? (3 off)

[27443] timerTest1: Time past/left [  976/ 2024]ms  next due after [29460]!
[27449] timerTest2: Time past/left [ 2071/  929]ms  next due after [28370]!
[27456] timerTest3: Time past/left [ 1578/ 1422]ms  next due after [28870]!
[27463] timerTest4: Time past/left [ 2949/ 4551]ms  next due after [32010]!
[27469] timerTest5: Time past/left [    4/    7]sec next due after [34620]!

[27476] wait ... wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww.. continue

[32116] startHolding: Time left [  84213]ms, [   84]sec, [ 1]min.
[32117] timerTest1: Time past/left [ 3000/    0]ms  next due after [32110]!
[32118] timerTest2: Time past/left [ 3000/    0]ms  next due after [32110]!
[32125] timerTest3: Time past/left [ 3000/    0]ms  next due after [32120]!
[32131] timerTest4: Time past/left [ 7500/    0]ms  next due after [32130]!
[32138] timerTest5: Time past/left [    9/    2]sec next due after [34620]!


[32352] [08:11:104]  .  .  .  .  .  .  .  .  .  .  .  .  .  => test1 runned! ([ 5.9]Sec.) -> 1_due[35352]
[32363]                     [08:11:115]                     => test3 runned! ([ 6.4]Sec.) -> 3_due[31878]
[32373]                               [08:11:125]  .  .  .  => test4 runned! ([ 7.9]Sec.) -> 4_due[39873]
[32529]                     [08:11:281]                     => test3 runned! ([ 0.2]Sec.) -> 3_due[34878]
[34401]           [08:13:153]  .  .  .  .  .  .  .  .  .  . => test2 runned! ([ 9.0]Sec.) -> 2_due[37378]
[34747]                                         [08:13:499] => test5 runned! ([12.1]Sec.) -> 5_due[46747]
[34952]                     [08:13:704]  .  .  .  .  .  .  .=> test3 runned! ([ 2.4]Sec.) -> 3_due[37878]
[35537] [08:14:289]                                         => test1 runned! ([ 3.2]Sec.) -> 1_due[38537]
[37423]           [08:16:175]  .  .  .  .  .  .  .  .  .  . => test2 runned! ([ 3.0]Sec.) -> 2_due[40378]
[37990]                     [08:16:742]                     => test3 runned! ([ 3.0]Sec.) -> 3_due[40878]
[38637] [08:17:389]  .  .  .  .  .  .  .  .  .  .  .  .  .  => test1 runned! ([ 3.1]Sec.) -> 1_due[41637]
[39970]                               [08:18:722]           => test4 runned! ([ 7.6]Sec.) -> 4_due[47470]
[40452]           [08:19:204]  .  .  .  .  .  .  .  .  .  . => test2 runned! ([ 3.0]Sec.) -> 2_due[43378]
[40924]                     [08:19:676]                     => test3 runned! ([ 2.9]Sec.) -> 3_due[43878]
[41713] [08:20:465]  .  .  .  .  .  .  .  .  .  .  .  .  .  => test1 runned! ([ 3.1]Sec.) -> 1_due[44713]
[43452]           [08:22:204]                               => test2 runned! ([ 3.0]Sec.) -> 2_due[46378]
[43886]                     [08:22:638]  .  .  .  .  .  .  .=> test3 runned! ([ 3.0]Sec.) -> 3_due[46878]
[44820] [08:23:572]                                         => test1 runned! ([ 3.1]Sec.) -> 1_due[47820]
[46431]           [08:25:183]  .  .  .  .  .  .  .  .  .  . => test2 runned! ([ 3.0]Sec.) -> 2_due[49378]
[46880]                     [08:25:632]                     => test3 runned! ([ 3.0]Sec.) -> 3_due[49878]
[46890]                                         [08:25:642] => test5 runned! ([12.1]Sec.) -> 5_due[58890]
[47560]                               [08:26:312]           => test4 runned! ([ 7.6]Sec.) -> 4_due[55060]
[47849] [08:26:601]  .  .  .  .  .  .  .  .  .  .  .  .  .  => test1 runned! ([ 3.0]Sec.) -> 1_due[50849]
[49422]           [08:28:174]                               => test2 runned! ([ 3.0]Sec.) -> 2_due[52378]
[50086]                     [08:28:838]  .  .  .  .  .  .  .=> test3 runned! ([ 3.2]Sec.) -> 3_due[52878]
[50874] [08:29:626]                                         => test1 runned! ([ 3.0]Sec.) -> 1_due[53874]
[52515]           [08:31:267]  .  .  .  .  .  .  .  .  .  . => test2 runned! ([ 3.1]Sec.) -> 2_due[55378]
[52885]                     [08:31:637]                     => test3 runned! ([ 2.8]Sec.) -> 3_due[55878]
[54051] [08:32:803]  .  .  .  .  .  .  .  .  .  .  .  .  .  => test1 runned! ([ 3.2]Sec.) -> 1_due[57051]
[55174]                               [08:33:926]           => test4 runned! ([ 7.6]Sec.) -> 4_due[62674]
[55384]           [08:34:136]  .  .  .  .  .  .  .  .  .  . => test2 runned! ([ 2.9]Sec.) -> 2_due[58378]
[56020]                     [08:34:772]                     => test3 runned! ([ 3.1]Sec.) -> 3_due[58878]
[57136] [08:35:888]  .  .  .  .  .  .  .  .  .  .  .  .  .  => test1 runned! ([ 3.1]Sec.) -> 1_due[60136]
[58397]           [08:37:149]                               => test2 runned! ([ 3.0]Sec.) -> 2_due[61378]
[58959]                     [08:37:711]  .  .  .  .  .  .  .=> test3 runned! ([ 2.9]Sec.) -> 3_due[61878]
[58970]                                         [08:37:722] => test5 runned! ([12.1]Sec.) -> 5_due[ 5434]
[60336] [08:39:088]  .  .  .  .  .  .  .  .  .  .  .  .  .  => test1 runned! ([ 3.2]Sec.) -> 1_due[63336]
[61405]           [08:40:157]                               => test2 runned! ([ 3.0]Sec.) -> 2_due[64378]
[61883]                     [08:40:635]  .  .  .  .  .  .  .=> test3 runned! ([ 2.9]Sec.) -> 3_due[64878]
[62704]                               [08:41:456]           => test4 runned! ([ 7.5]Sec.) -> 4_due[ 4668]
[63456] [08:42:208]  .  .  .  .  .  .  .  .  .  .  .  .  .  => test1 runned! ([ 3.1]Sec.) -> 1_due[  920]
[64387]           [08:43:140]                               => test2 runned! ([ 3.0]Sec.) -> 2_due[ 1842]
[64883]                     [08:43:635]  .  .  .  .  .  .  .=> test3 runned! ([ 3.0]Sec.) -> 3_due[ 2342]

[  215] ***** timer16Bit() has rolled-over! *****

[  215] timerTest1: Time past/left [ 2295/  705]ms  next due after [  920]!
[  215] timerTest2: Time past/left [ 1373/ 1627]ms  next due after [ 1840]!
[  222] timerTest3: Time past/left [  880/ 2120]ms  next due after [ 2340]!
[  228] timerTest4: Time past/left [ 3060/ 4440]ms  next due after [ 4660]!
[  235] timerTest5: Time past/left [    6/    5]sec next due after [ 5430]!

[ 1027] [08:45:315]                                         => test1 runned! ([ 3.1]Sec.) -> 1_due[ 4027]
[ 1848]           [08:46:136]  .  .  .  .  .  .  .  .  .  . => test2 runned! ([ 3.0]Sec.) -> 2_due[ 4842]
[ 2380]                     [08:46:668]                     => test3 runned! ([ 3.0]Sec.) -> 3_due[ 5342]
[ 4064] [08:48:352]  .  .  .  .  .  .  .  .  .  .  .  .  .  => test1 runned! ([ 3.0]Sec.) -> 1_due[ 7064]
[ 4688]                               [08:48:976]           => test4 runned! ([ 7.5]Sec.) -> 4_due[12188]
[ 4990]           [08:49:278]  .  .  .  .  .  .  .  .  .  . => test2 runned! ([ 3.1]Sec.) -> 2_due[ 7842]
[ 5422]                     [08:49:710]                     => test3 runned! ([ 3.0]Sec.) -> 3_due[ 8342]
[ 5460]                                         [08:49:748] => test5 runned! ([12.0]Sec.) -> 5_due[17460]
[ 7160] [08:51:448]                                         => test1 runned! ([ 3.1]Sec.) -> 1_due[10160]

[ 7682] test1 counted[155] times run in [177] events --> ? (22 off)
[ 7682] test2 counted[144] times run in [177] events --> ? (33 off)
[ 7683] test3 counted[176] times run in [177] events --> ? (1 off)
[ 7689] test4 counted[65] times run in [70] events --> ? (5 off)
[ 7695] test5 counted[41] times run in [44] events --> ? (3 off)

[ 7701] timerTest1: Time past/left [  541/ 2459]ms  next due after [10160]!
[ 7707] timerTest2: Time past/left [ 2865/  135]ms  next due after [ 7840]!
[ 7714] timerTest3: Time past/left [ 2372/  628]ms  next due after [ 8340]!
[ 7721] timerTest4: Time past/left [ 3033/ 4467]ms  next due after [12180]!
[ 7727] timerTest5: Time past/left [    2/    9]sec next due after [17450]!

[ 7734] wait ... wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww.. continue

[12154] startHolding: Time left [  38639]ms, [   38]sec, [ 0]min.
[12154] timerTest1: Time past/left [ 3000/    0]ms  next due after [12150]!
[12156] timerTest2: Time past/left [ 3000/    0]ms  next due after [12150]!
[12162] timerTest3: Time past/left [ 3000/    0]ms  next due after [12160]!
[12169] timerTest4: Time past/left [ 7481/   19]ms  next due after [12180]!
[12176] timerTest5: Time past/left [    6/    5]sec next due after [17460]!


[12330] [08:56:618]  .  .  .  .  .  .  .  .  .  .  .  .  .  => test1 runned! ([ 5.2]Sec.) -> 1_due[15330]
[12340]                     [08:56:628]                     => test3 runned! ([ 6.9]Sec.) -> 3_due[11342]
[12350]                               [08:56:638]  .  .  .  => test4 runned! ([ 7.7]Sec.) -> 4_due[19850]
[12475]                     [08:56:763]                     => test3 runned! ([ 0.1]Sec.) -> 3_due[14342]
[13984]           [08:58:272]  .  .  .  .  .  .  .  .  .  . => test2 runned! ([ 9.0]Sec.) -> 2_due[16842]
[14440]                     [08:58:728]                     => test3 runned! ([ 2.0]Sec.) -> 3_due[17342]
[15512] [08:59:800]  .  .  .  .  .  .  .  .  .  .  .  .  .  => test1 runned! ([ 3.2]Sec.) -> 1_due[18512]
[16925]           [09:01:213]                               => test2 runned! ([ 2.9]Sec.) -> 2_due[19842]
[17354]                     [09:01:642]  .  .  .  .  .  .  .=> test3 runned! ([ 2.9]Sec.) -> 3_due[20342]
[17510]                                         [09:01:798] => test5 runned! ([12.1]Sec.) -> 5_due[29510]
[18636] [09:02:924]  .  .  .  .  .  .  .  .  .  .  .  .  .  => test1 runned! ([ 3.1]Sec.) -> 1_due[21636]
[20077]                               [09:04:365]           => test4 runned! ([ 7.7]Sec.) -> 4_due[27577]
[20475]                     [09:04:763]  .  .  .  .  .  .  .=> test3 runned! ([ 3.1]Sec.) -> 3_due[23342]
[21689] [09:05:977]                                         => test1 runned! ([ 3.0]Sec.) -> 1_due[24689]
[22853]           [09:07:141]  .  .  .  .  .  .  .  .  .  . => test2 runned! ([ 5.9]Sec.) -> 2_due[25842]
[23369]                     [09:07:657]                     => test3 runned! ([ 2.9]Sec.) -> 3_due[26342]
[24703] [09:08:991]  .  .  .  .  .  .  .  .  .  .  .  .  .  => test1 runned! ([ 3.0]Sec.) -> 1_due[27703]
[25940]           [09:10:228]                               => test2 runned! ([ 3.1]Sec.) -> 2_due[28842]
[26502]                     [09:10:790]  .  .  .  .  .  .  .=> test3 runned! ([ 3.1]Sec.) -> 3_due[29342]
[27630]                               [09:11:918]           => test4 runned! ([ 7.6]Sec.) -> 4_due[35130]
[27823] [09:12:111]  .  .  .  .  .  .  .  .  .  .  .  .  .  => test1 runned! ([ 3.1]Sec.) -> 1_due[30823]
[28887]           [09:13:175]                               => test2 runned! ([ 2.9]Sec.) -> 2_due[31842]
[29351]                     [09:13:639]  .  .  .  .  .  .  .=> test3 runned! ([ 2.8]Sec.) -> 3_due[32342]
[29589]                                         [09:13:877] => test5 runned! ([12.1]Sec.) -> 5_due[41589]
[30842] [09:15:130]  .  .  .  .  .  .  .  .  .  .  .  .  .  => test1 runned! ([ 3.0]Sec.) -> 1_due[33842]
[31843]           [09:16:131]                               => test2 runned! ([ 3.0]Sec.) -> 2_due[34842]
[32553]                     [09:16:841]  .  .  .  .  .  .  .=> test3 runned! ([ 3.2]Sec.) -> 3_due[35342]
[34004] [09:18:292]                                         => test1 runned! ([ 3.2]Sec.) -> 1_due[37004]
[34948]           [09:19:236]  .  .  .  .  .  .  .  .  .  . => test2 runned! ([ 3.1]Sec.) -> 2_due[37842]
[35307]                               [09:19:595]           => test4 runned! ([ 7.7]Sec.) -> 4_due[42807]
[35549]                     [09:19:837]  .  .  .  .  .  .  .=> test3 runned! ([ 3.0]Sec.) -> 3_due[38342]
[37018] [09:21:306]                                         => test1 runned! ([ 3.0]Sec.) -> 1_due[40018]
[38532]                     [09:22:820]  .  .  .  .  .  .  .=> test3 runned! ([ 3.0]Sec.) -> 3_due[41342]
[40086] [09:24:374]                                         => test1 runned! ([ 3.1]Sec.) -> 1_due[43086]
[40870]           [09:25:158]  .  .  .  .  .  .  .  .  .  . => test2 runned! ([ 5.9]Sec.) -> 2_due[43842]
[41411]                     [09:25:699]                     => test3 runned! ([ 2.9]Sec.) -> 3_due[44342]
[41758]                                         [09:26:047] => test5 runned! ([12.2]Sec.) -> 5_due[53758]
[43050]                               [09:27:338]           => test4 runned! ([ 7.7]Sec.) -> 4_due[50550]
[43126] [09:27:414]  .  .  .  .  .  .  .  .  .  .  .  .  .  => test1 runned! ([ 3.0]Sec.) -> 1_due[46126]
[43934]           [09:28:222]                               => test2 runned! ([ 3.1]Sec.) -> 2_due[46842]
[44355]                     [09:28:643]  .  .  .  .  .  .  .=> test3 runned! ([ 2.9]Sec.) -> 3_due[47342]
[46231] [09:30:519]                                         => test1 runned! ([ 3.1]Sec.) -> 1_due[49231]
[46851]           [09:31:139]  .  .  .  .  .  .  .  .  .  . => test2 runned! ([ 2.9]Sec.) -> 2_due[49842]
[47429]                     [09:31:717]                     => test3 runned! ([ 3.1]Sec.) -> 3_due[50342]
[49311] [09:33:599]  .  .  .  .  .  .  .  .  .  .  .  .  .  => test1 runned! ([ 3.1]Sec.) -> 1_due[52311]
[49843]           [09:34:131]                               => test2 runned! ([ 3.0]Sec.) -> 2_due[52842]
[50477]                     [09:34:765]  .  .  .  .  .  .  .=> test3 runned! ([ 3.0]Sec.) -> 3_due[53342]
[50586]                               [09:34:874]           => test4 runned! ([ 7.5]Sec.) -> 4_due[58086]

[50836] timerTest1: Time past/left [ 1525/ 1475]ms  next due after [52310]!
[50837] timerTest2: Time past/left [  995/ 2005]ms  next due after [52840]!
[50839] timerTest3: Time past/left [  497/ 2503]ms  next due after [53340]!
[50845] timerTest4: Time past/left [  259/ 7241]ms  next due after [58080]!
[50852] timerTest5: Time past/left [    9/    2]sec next due after [53750]!


[50859] hold ... 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1 .. continue
*********************** using NO random delays! from here on *********************

[  329] startWaiting: Time left [      0]ms, [    0]sec., [ 0]min.

[  332] timerTest1: Time past/left [ 3000/    0]ms  next due after [  330]!
[  339] timerTest2: Time past/left [ 3000/    0]ms  next due after [  330]!
[  346] timerTest3: Time past/left [ 3000/    0]ms  next due after [  340]!
[  352] timerTest4: Time past/left [ 7500/    0]ms  next due after [  350]!
[  359] timerTest5: Time past/left [   12/    0]sec next due after [  350]!


[  366] [09:50:190]  .  .  .  .  .  .  .  .  .  .  .  .  .  => test1 runned! ([16.6]Sec.) -> 1_due[ 3366]
[  386]           [09:50:211]                               => test2 runned! ([16.1]Sec.) -> 2_due[ 2306]
[  397]                     [09:50:221]  .  .  .  .  .  .  .=> test3 runned! ([15.5]Sec.) -> 3_due[56342]
[  407]                               [09:50:231]           => test4 runned! ([15.4]Sec.) -> 4_due[ 7907]
[  417]                                         [09:50:241] => test5 runned! ([24.2]Sec.) -> 5_due[12417]
[  427]                     [09:50:251]                     => test3 runned! ([ 0.0]Sec.) -> 3_due[59342]
[  437]                     [09:50:261]  .  .  .  .  .  .  .=> test3 runned! ([ 0.0]Sec.) -> 3_due[62342]
[  447]                     [09:50:271]                     => test3 runned! ([ 0.0]Sec.) -> 3_due[65342]
[  457]                     [09:50:281]  .  .  .  .  .  .  .=> test3 runned! ([ 0.0]Sec.) -> 3_due[ 2806]
[ 2306]           [09:52:130]                               => test2 runned! ([ 1.9]Sec.) -> 2_due[ 5306]
[ 2806]                     [09:52:630]  .  .  .  .  .  .  .=> test3 runned! ([ 2.3]Sec.) -> 3_due[ 5806]
[ 3366] [09:53:190]                                         => test1 runned! ([ 3.0]Sec.) -> 1_due[ 6366]
[ 5306]           [09:55:130]  .  .  .  .  .  .  .  .  .  . => test2 runned! ([ 3.0]Sec.) -> 2_due[ 8306]
[ 5806]                     [09:55:630]                     => test3 runned! ([ 3.0]Sec.) -> 3_due[ 8806]
[ 6366] [09:56:190]  .  .  .  .  .  .  .  .  .  .  .  .  .  => test1 runned! ([ 3.0]Sec.) -> 1_due[ 9366]
[ 7907]                               [09:57:731]           => test4 runned! ([ 7.5]Sec.) -> 4_due[15407]
[ 8306]           [09:58:130]  .  .  .  .  .  .  .  .  .  . => test2 runned! ([ 3.0]Sec.) -> 2_due[11306]
[ 8806]                     [09:58:630]                     => test3 runned! ([ 3.0]Sec.) -> 3_due[11806]
[ 9366] [09:59:190]  .  .  .  .  .  .  .  .  .  .  .  .  .  => test1 runned! ([ 3.0]Sec.) -> 1_due[12366]
[11306]           [10:01:130]                               => test2 runned! ([ 3.0]Sec.) -> 2_due[14306]
[11806]                     [10:01:630]  .  .  .  .  .  .  .=> test3 runned! ([ 3.0]Sec.) -> 3_due[14806]
[12366] [10:02:190]                                         => test1 runned! ([ 3.0]Sec.) -> 1_due[15366]
[12417]                                         [10:02:241] => test5 runned! ([12.0]Sec.) -> 5_due[24417]
[14306]           [10:04:130]                               => test2 runned! ([ 3.0]Sec.) -> 2_due[17306]
[14806]                     [10:04:630]  .  .  .  .  .  .  .=> test3 runned! ([ 3.0]Sec.) -> 3_due[17806]
[15366] [10:05:190]                                         => test1 runned! ([ 3.0]Sec.) -> 1_due[18366]
[15407]                               [10:05:231]  .  .  .  => test4 runned! ([ 7.5]Sec.) -> 4_due[22907]
[17306]           [10:07:130]                               => test2 runned! ([ 3.0]Sec.) -> 2_due[20306]
[17806]                     [10:07:630]  .  .  .  .  .  .  .=> test3 runned! ([ 3.0]Sec.) -> 3_due[20806]
[18366] [10:08:190]                                         => test1 runned! ([ 3.0]Sec.) -> 1_due[21366]
[20306]           [10:10:130]  .  .  .  .  .  .  .  .  .  . => test2 runned! ([ 3.0]Sec.) -> 2_due[23306]
[20806]                     [10:10:630]                     => test3 runned! ([ 3.0]Sec.) -> 3_due[23806]
[21366] [10:11:190]  .  .  .  .  .  .  .  .  .  .  .  .  .  => test1 runned! ([ 3.0]Sec.) -> 1_due[24366]
[22907]                               [10:12:731]           => test4 runned! ([ 7.5]Sec.) -> 4_due[30407]
[23306]           [10:13:130]  .  .  .  .  .  .  .  .  .  . => test2 runned! ([ 3.0]Sec.) -> 2_due[26306]
[23806]                     [10:13:630]                     => test3 runned! ([ 3.0]Sec.) -> 3_due[26806]
[24366] [10:14:190]  .  .  .  .  .  .  .  .  .  .  .  .  .  => test1 runned! ([ 3.0]Sec.) -> 1_due[27366]
[24417]                                         [10:14:241] => test5 runned! ([12.0]Sec.) -> 5_due[36417]
[26306]           [10:16:130]  .  .  .  .  .  .  .  .  .  . => test2 runned! ([ 3.0]Sec.) -> 2_due[29306]
[26806]                     [10:16:630]                     => test3 runned! ([ 3.0]Sec.) -> 3_due[29806]
[27366] [10:17:190]  .  .  .  .  .  .  .  .  .  .  .  .  .  => test1 runned! ([ 3.0]Sec.) -> 1_due[30366]
[29306]           [10:19:130]                               => test2 runned! ([ 3.0]Sec.) -> 2_due[32306]
[29806]                     [10:19:630]  .  .  .  .  .  .  .=> test3 runned! ([ 3.0]Sec.) -> 3_due[32806]
[30366] [10:20:190]                                         => test1 runned! ([ 3.0]Sec.) -> 1_due[33366]
[30407]                               [10:20:231]  .  .  .  => test4 runned! ([ 7.5]Sec.) -> 4_due[37907]
[32306]           [10:22:130]                               => test2 runned! ([ 3.0]Sec.) -> 2_due[35306]
[32806]                     [10:22:630]  .  .  .  .  .  .  .=> test3 runned! ([ 3.0]Sec.) -> 3_due[35806]
[33366] [10:23:190]                                         => test1 runned! ([ 3.0]Sec.) -> 1_due[36366]
[35306]           [10:25:130]  .  .  .  .  .  .  .  .  .  . => test2 runned! ([ 3.0]Sec.) -> 2_due[38306]
[35806]                     [10:25:630]                     => test3 runned! ([ 3.0]Sec.) -> 3_due[38806]
[36366] [10:26:190]  .  .  .  .  .  .  .  .  .  .  .  .  .  => test1 runned! ([ 3.0]Sec.) -> 1_due[39366]
[36417]                                         [10:26:241] => test5 runned! ([12.0]Sec.) -> 5_due[48417]
[37907]                               [10:27:731]  .  .  .  => test4 runned! ([ 7.5]Sec.) -> 4_due[45407]
[38306]           [10:28:130]                               => test2 runned! ([ 3.0]Sec.) -> 2_due[41306]
[38806]                     [10:28:630]  .  .  .  .  .  .  .=> test3 runned! ([ 3.0]Sec.) -> 3_due[41806]
[39366] [10:29:190]                                         => test1 runned! ([ 3.0]Sec.) -> 1_due[42366]
[41306]           [10:31:130]  .  .  .  .  .  .  .  .  .  . => test2 runned! ([ 3.0]Sec.) -> 2_due[44306]

[41366] test1 counted[182] times run in [210] events --> ? (28 off)
[41366] test2 counted[170] times run in [210] events --> ? (40 off)
[41367] test3 counted[209] times run in [210] events --> ? (1 off)
[41373] test4 counted[77] times run in [84] events --> ? (7 off)
[41379] test5 counted[48] times run in [52] events --> ? (4 off)

[41385] timerTest1: Time past/left [ 2019/  981]ms  next due after [42360]!
[41391] timerTest2: Time past/left [   85/ 2915]ms  next due after [44300]!
[41398] timerTest3: Time past/left [ 2592/  408]ms  next due after [41800]!
[41405] timerTest4: Time past/left [ 3498/ 4002]ms  next due after [45400]!
[41411] timerTest5: Time past/left [    4/    7]sec next due after [48410]!

[41418] wait ... wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww.. continue

[45422] startHolding: Time left [  84943]ms, [   84]sec, [ 1]min.
[45423] timerTest1: Time past/left [ 3000/    0]ms  next due after [45420]!
[45425] timerTest2: Time past/left [ 3000/    0]ms  next due after [45420]!
[45431] timerTest3: Time past/left [ 3000/    0]ms  next due after [45430]!
[45438] timerTest4: Time past/left [ 7500/    0]ms  next due after [45430]!
[45445] timerTest5: Time past/left [    9/    2]sec next due after [48410]!


[45453] [10:35:277]                                         => test1 runned! ([ 6.1]Sec.) -> 1_due[48453]
[45472]                     [10:35:296]  .  .  .  .  .  .  .=> test3 runned! ([ 6.7]Sec.) -> 3_due[44806]
[45482]                               [10:35:306]           => test4 runned! ([ 7.6]Sec.) -> 4_due[52982]
[45492]                     [10:35:316]  .  .  .  .  .  .  .=> test3 runned! ([ 0.0]Sec.) -> 3_due[47806]
[47306]           [10:37:130]                               => test2 runned! ([ 6.0]Sec.) -> 2_due[50306]
[47806]                     [10:37:630]  .  .  .  .  .  .  .=> test3 runned! ([ 2.3]Sec.) -> 3_due[50806]
[48417]                                         [10:38:241] => test5 runned! ([12.0]Sec.) -> 5_due[60417]
[48453] [10:38:277]  .  .  .  .  .  .  .  .  .  .  .  .  .  => test1 runned! ([ 3.0]Sec.) -> 1_due[51453]
[50306]           [10:40:130]                               => test2 runned! ([ 3.0]Sec.) -> 2_due[53306]
[50806]                     [10:40:630]  .  .  .  .  .  .  .=> test3 runned! ([ 3.0]Sec.) -> 3_due[53806]
[51453] [10:41:277]                                         => test1 runned! ([ 3.0]Sec.) -> 1_due[54453]
[52982]                               [10:42:806]  .  .  .  => test4 runned! ([ 7.5]Sec.) -> 4_due[60482]
[53306]           [10:43:130]                               => test2 runned! ([ 3.0]Sec.) -> 2_due[56306]
[53806]                     [10:43:630]  .  .  .  .  .  .  .=> test3 runned! ([ 3.0]Sec.) -> 3_due[56806]
[54453] [10:44:277]                                         => test1 runned! ([ 3.0]Sec.) -> 1_due[57453]
[56306]           [10:46:130]  .  .  .  .  .  .  .  .  .  . => test2 runned! ([ 3.0]Sec.) -> 2_due[59306]
[56806]                     [10:46:630]                     => test3 runned! ([ 3.0]Sec.) -> 3_due[59806]
[57453] [10:47:277]  .  .  .  .  .  .  .  .  .  .  .  .  .  => test1 runned! ([ 3.0]Sec.) -> 1_due[60453]
[59306]           [10:49:130]                               => test2 runned! ([ 3.0]Sec.) -> 2_due[62306]
[59806]                     [10:49:630]  .  .  .  .  .  .  .=> test3 runned! ([ 3.0]Sec.) -> 3_due[62806]
[60417]                                         [10:50:241] => test5 runned! ([12.0]Sec.) -> 5_due[ 6881]
[60453] [10:50:277]  .  .  .  .  .  .  .  .  .  .  .  .  .  => test1 runned! ([ 3.0]Sec.) -> 1_due[63453]
[60482]                               [10:50:306]           => test4 runned! ([ 7.5]Sec.) -> 4_due[ 2446]
[62306]           [10:52:130]  .  .  .  .  .  .  .  .  .  . => test2 runned! ([ 3.0]Sec.) -> 2_due[65306]
[62806]                     [10:52:630]                     => test3 runned! ([ 3.0]Sec.) -> 3_due[  270]
[63453] [10:53:277]  .  .  .  .  .  .  .  .  .  .  .  .  .  => test1 runned! ([ 3.0]Sec.) -> 1_due[  917]
[65306]           [10:55:130]                               => test2 runned! ([ 3.0]Sec.) -> 2_due[ 2770]

[    0] ***** timer16Bit() has rolled-over! *****

[    0] timerTest1: Time past/left [ 2083/  917]ms  next due after [  910]!
[    0] timerTest2: Time past/left [  230/ 2770]ms  next due after [ 2770]!
[    7] timerTest3: Time past/left [ 2737/  263]ms  next due after [  270]!
[   13] timerTest4: Time past/left [ 5067/ 2433]ms  next due after [ 2440]!
[   20] timerTest5: Time past/left [    5/    6]sec next due after [ 6880]!

[  270]                     [10:55:630]  .  .  .  .  .  .  .=> test3 runned! ([ 3.0]Sec.) -> 3_due[ 3270]
[  917] [10:56:277]                                         => test1 runned! ([ 3.0]Sec.) -> 1_due[ 3917]
[ 2446]                               [10:57:806]  .  .  .  => test4 runned! ([ 7.5]Sec.) -> 4_due[ 9946]
[ 2770]           [10:58:130]                               => test2 runned! ([ 3.0]Sec.) -> 2_due[ 5770]
[ 3270]                     [10:58:630]  .  .  .  .  .  .  .=> test3 runned! ([ 3.0]Sec.) -> 3_due[ 6270]
[ 3917] [10:59:277]                                         => test1 runned! ([ 3.0]Sec.) -> 1_due[ 6917]
[ 5770]           [11:01:130]  .  .  .  .  .  .  .  .  .  . => test2 runned! ([ 3.0]Sec.) -> 2_due[ 8770]
[ 6270]                     [11:01:630]                     => test3 runned! ([ 3.0]Sec.) -> 3_due[ 9270]
[ 6881]                                         [11:02:241] => test5 runned! ([12.0]Sec.) -> 5_due[18881]
[ 6917] [11:02:277]                                         => test1 runned! ([ 3.0]Sec.) -> 1_due[ 9917]
