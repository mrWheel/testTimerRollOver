=======================
Date: 21-02-2020  15:14
=======================

//---TEST 1----CATCH_UP_MISSED_EVENTS---------------------------------------
// t1     t2     t3     t4     t5     t6     t7     t8     t9     t10    t11
//                            <processor>
//                            <  bussy  >
// d1<int>d2<int>d3<int>d4 ..............d5.d6.d7<->d8<int>d9<int>d10 enz
//
Test1 moet dus de gemiste "due's" inhalen.
In het test-log (over ruim een uur hier op github) zul je zien hoe ik dat 
gebruik en waarom dit nodig is!
In het figuurtje hierboven "mist" test1 t5 en t6, maar haalt deze weer in
tot na t7 de ingestelde interval weer gebruikt wordt.

//---TEST 2-------------------------------------------------------------------
// t1     t2     t3     t4     t5     t6     t7     t8     t9     t10    t11
//                            <processor>
//                            <  bussy  >
// --- geen idee ---
//
Test2 ???

//---TEST 3-------------------------------------------------------------------
// t1     t2     t3     t4     t5     t6     t7     t8     t9     t10    t11
//                            <processor>
//                            <  bussy  >
// d1<int>d2<int>d3<int>d4 ..............d5<int>d6<int>d7<int>d8<int>d9 enz
//
Test3 vuurt direct na een lange pauze (omdat de processor met andere, 
tijdrovende, zaken bezig was) maar herstelt daarna de interval.
In het figuurtje hierboven "mist" test3 t5 en t6, maar de eerstvolgende
keer dat het due-event gevuurd wordt (d5) wordt d6 pas gevuurd nadat
de interval is verstreken.




Stresstest for safeTimersFastRO.h macro's 

Due_Test1[ 3000]ms Due_Test2[ 3000]ms Due_Test3[ 3000]ms 
...Test1_type[1]   ...Test2_type[2]   ...Test3_type[0]   

[  110] StartTime[00:00:110]
[ 3110] [00:03:110]                     => test1 runned! ([ 3.1]Sec.) -> 1_due[ 6110]
[ 3610]           [00:03:610]           => test2 runned! ([ 3.6]Sec.) -> 2_due[ 6610]
[ 4110]                     [00:04:110] => test3 runned! ([ 4.1]Sec.) -> 3_due[ 7110]
[ 6110] [00:06:110]                     => test1 runned! ([ 3.0]Sec.) -> 1_due[ 9110]
[ 6610]           [00:06:610]           => test2 runned! ([ 3.0]Sec.) -> 2_due[ 9610]
[ 7110]                     [00:07:110] => test3 runned! ([ 3.0]Sec.) -> 3_due[10110]
[ 9110] [00:09:110]                     => test1 runned! ([ 3.0]Sec.) -> 1_due[12110]
[ 9610]           [00:09:610]           => test2 runned! ([ 3.0]Sec.) -> 2_due[12610]
[10110]                     [00:10:110] => test3 runned! ([ 3.0]Sec.) -> 3_due[13110]
[12110] [00:12:110]                     => test1 runned! ([ 3.0]Sec.) -> 1_due[15110]
[12610]           [00:12:610]           => test2 runned! ([ 3.0]Sec.) -> 2_due[15610]
[13110]                     [00:13:110] => test3 runned! ([ 3.0]Sec.) -> 3_due[16110]
[15110] [00:15:110]                     => test1 runned! ([ 3.0]Sec.) -> 1_due[18110]
[15610]           [00:15:610]           => test2 runned! ([ 3.0]Sec.) -> 2_due[18610]
[16110]                     [00:16:110] => test3 runned! ([ 3.0]Sec.) -> 3_due[19110]
[18110] [00:18:110]                     => test1 runned! ([ 3.0]Sec.) -> 1_due[21110]
[18610]           [00:18:610]           => test2 runned! ([ 3.0]Sec.) -> 2_due[21610]
[19110]                     [00:19:110] => test3 runned! ([ 3.0]Sec.) -> 3_due[22110]
[21110] [00:21:110]                     => test1 runned! ([ 3.0]Sec.) -> 1_due[24110]
[21610]           [00:21:610]           => test2 runned! ([ 3.0]Sec.) -> 2_due[24610]
[22110]                     [00:22:110] => test3 runned! ([ 3.0]Sec.) -> 3_due[25110]
[24110] [00:24:110]                     => test1 runned! ([ 3.0]Sec.) -> 1_due[27110]
[24610]           [00:24:610]           => test2 runned! ([ 3.0]Sec.) -> 2_due[27610]
[25110]                     [00:25:110] => test3 runned! ([ 3.0]Sec.) -> 3_due[28110]
[27110] [00:27:110]                     => test1 runned! ([ 3.0]Sec.) -> 1_due[30110]
[27610]           [00:27:610]           => test2 runned! ([ 3.0]Sec.) -> 2_due[30610]
[28110]                     [00:28:110] => test3 runned! ([ 3.0]Sec.) -> 3_due[31110]
[30110] [00:30:110]                     => test1 runned! ([ 3.0]Sec.) -> 1_due[33110]
[30610]           [00:30:610]           => test2 runned! ([ 3.0]Sec.) -> 2_due[33610]
[31110]                     [00:31:110] => test3 runned! ([ 3.0]Sec.) -> 3_due[34110]
[33110] [00:33:110]                     => test1 runned! ([ 3.0]Sec.) -> 1_due[36110]
[33610]           [00:33:610]           => test2 runned! ([ 3.0]Sec.) -> 2_due[36610]
[34110]                     [00:34:110] => test3 runned! ([ 3.0]Sec.) -> 3_due[37110]
[36110] [00:36:110]                     => test1 runned! ([ 3.0]Sec.) -> 1_due[39110]
[36610]           [00:36:610]           => test2 runned! ([ 3.0]Sec.) -> 2_due[39610]
[37110]                     [00:37:110] => test3 runned! ([ 3.0]Sec.) -> 3_due[40110]
[39110] [00:39:110]                     => test1 runned! ([ 3.0]Sec.) -> 1_due[42110]
[39610]           [00:39:610]           => test2 runned! ([ 3.0]Sec.) -> 2_due[42610]
[40110]                     [00:40:110] => test3 runned! ([ 3.0]Sec.) -> 3_due[43110]

[41110] test1 counted[13] times run in [13] events --> EQUAL
[41110] test2 counted[13] times run in [13] events --> EQUAL
[41111] test3 counted[13] times run in [13] events --> EQUAL

[41115] wait ... wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww.. continue

[45119] startHolding: Time left [  84990]ms, [   84]sec, [ 1]min.
[45120] timerTest1: Time past/left [  475/ 2525]ms  next due after [47640]!
[45122] timerTest2: Time past/left [ 2977/   23]ms  next due after [45140]!
[45129] timerTest3: Time past/left [ 2484/  516]ms  next due after [45640]!

[45135] [00:45:136]                     => test1 runned! ([ 6.0]Sec.) -> 1_due[45110]
[45154]           [00:45:154]           => test2 runned! ([ 5.5]Sec.) -> 2_due[45610]
[45162]                     [00:45:162] => test3 runned! ([ 5.1]Sec.) -> 3_due[48162]
[45171] [00:45:171]                     => test1 runned! ([ 0.0]Sec.) -> 1_due[48110]
[45610]           [00:45:610]           => test2 runned! ([ 0.5]Sec.) -> 2_due[48610]
[48110] [00:48:110]                     => test1 runned! ([ 2.9]Sec.) -> 1_due[51110]
[48162]                     [00:48:162] => test3 runned! ([ 3.0]Sec.) -> 3_due[51162]
[48610]           [00:48:610]           => test2 runned! ([ 3.0]Sec.) -> 2_due[51610]
[51110] [00:51:110]                     => test1 runned! ([ 3.0]Sec.) -> 1_due[54110]
[51162]                     [00:51:162] => test3 runned! ([ 3.0]Sec.) -> 3_due[54162]
[51610]           [00:51:610]           => test2 runned! ([ 3.0]Sec.) -> 2_due[54610]
[54110] [00:54:110]                     => test1 runned! ([ 3.0]Sec.) -> 1_due[57110]
[54162]                     [00:54:162] => test3 runned! ([ 3.0]Sec.) -> 3_due[57162]
[54610]           [00:54:610]           => test2 runned! ([ 3.0]Sec.) -> 2_due[57610]
[57110] [00:57:110]                     => test1 runned! ([ 3.0]Sec.) -> 1_due[60110]
[57162]                     [00:57:162] => test3 runned! ([ 3.0]Sec.) -> 3_due[60162]
[57610]           [00:57:610]           => test2 runned! ([ 3.0]Sec.) -> 2_due[60610]
[60110] [01:00:110]                     => test1 runned! ([ 3.0]Sec.) -> 1_due[63110]
[60162]                     [01:00:162] => test3 runned! ([ 3.0]Sec.) -> 3_due[63162]
[60610]           [01:00:610]           => test2 runned! ([ 3.0]Sec.) -> 2_due[63610]
[63110] [01:03:110]                     => test1 runned! ([ 3.0]Sec.) -> 1_due[  574]
[63162]                     [01:03:162] => test3 runned! ([ 3.0]Sec.) -> 3_due[  626]
[63610]           [01:03:610]           => test2 runned! ([ 3.0]Sec.) -> 2_due[ 1074]

[    0] ***** timer16Bit() has rolled-over! *****
[    0] timerTest1: Time past/left [ 2426/  574]ms  next due after [  570]!
[    0] timerTest2: Time past/left [ 1926/ 1074]ms  next due after [ 1070]!
[    7] timerTest3: Time past/left [ 2381/  619]ms  next due after [  620]!

[  574] [01:06:110]                     => test1 runned! ([ 3.0]Sec.) -> 1_due[ 3574]
[  626]                     [01:06:162] => test3 runned! ([ 3.0]Sec.) -> 3_due[ 3626]
[ 1074]           [01:06:610]           => test2 runned! ([ 3.0]Sec.) -> 2_due[ 4074]
[ 3574] [01:09:110]                     => test1 runned! ([ 3.0]Sec.) -> 1_due[ 6574]
[ 3626]                     [01:09:162] => test3 runned! ([ 3.0]Sec.) -> 3_due[ 6626]
[ 4074]           [01:09:610]           => test2 runned! ([ 3.0]Sec.) -> 2_due[ 7074]
[ 6574] [01:12:110]                     => test1 runned! ([ 3.0]Sec.) -> 1_due[ 9574]
[ 6626]                     [01:12:162] => test3 runned! ([ 3.0]Sec.) -> 3_due[ 9626]
[ 7074]           [01:12:610]           => test2 runned! ([ 3.0]Sec.) -> 2_due[10074]
[ 9574] [01:15:110]                     => test1 runned! ([ 3.0]Sec.) -> 1_due[12574]
[ 9626]                     [01:15:162] => test3 runned! ([ 3.0]Sec.) -> 3_due[12626]
[10074]           [01:15:610]           => test2 runned! ([ 3.0]Sec.) -> 2_due[13074]
[12574] [01:18:110]                     => test1 runned! ([ 3.0]Sec.) -> 1_due[15574]
[12626]                     [01:18:162] => test3 runned! ([ 3.0]Sec.) -> 3_due[15626]
[13074]           [01:18:610]           => test2 runned! ([ 3.0]Sec.) -> 2_due[16074]
[15574] [01:21:110]                     => test1 runned! ([ 3.0]Sec.) -> 1_due[18574]
[15626]                     [01:21:162] => test3 runned! ([ 3.0]Sec.) -> 3_due[18626]
[16074]           [01:21:610]           => test2 runned! ([ 3.0]Sec.) -> 2_due[19074]
[18574] [01:24:110]                     => test1 runned! ([ 3.0]Sec.) -> 1_due[21574]
[18626]                     [01:24:162] => test3 runned! ([ 3.0]Sec.) -> 3_due[21626]
[19074]           [01:24:610]           => test2 runned! ([ 3.0]Sec.) -> 2_due[22074]

[20599] test1 counted[28] times run in [28] events --> EQUAL
[20600] test2 counted[28] times run in [28] events --> EQUAL
[20600] test3 counted[27] times run in [28] events --> ? (1 off)

[20605] wait ... wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww.. continue

[24609] startHolding: Time left [  39965]ms, [   39]sec, [ 0]min.
[24609] timerTest1: Time past/left [  500/ 2500]ms  next due after [27100]!
[24611] timerTest2: Time past/left [    3/ 2997]ms  next due after [27600]!
[24618] timerTest3: Time past/left [  457/ 2543]ms  next due after [27160]!

[24625] [01:30:161]                     => test1 runned! ([ 6.0]Sec.) -> 1_due[24574]
[24644]           [01:30:180]           => test2 runned! ([ 5.6]Sec.) -> 2_due[25074]
[24652]                     [01:30:188] => test3 runned! ([ 6.0]Sec.) -> 3_due[27652]
[24660] [01:30:196]                     => test1 runned! ([ 0.0]Sec.) -> 1_due[27574]
[25074]           [01:30:610]           => test2 runned! ([ 0.4]Sec.) -> 2_due[28074]
[27574] [01:33:110]                     => test1 runned! ([ 2.9]Sec.) -> 1_due[30574]
[27652]                     [01:33:188] => test3 runned! ([ 3.0]Sec.) -> 3_due[30652]
[28074]           [01:33:610]           => test2 runned! ([ 3.0]Sec.) -> 2_due[31074]
[30574] [01:36:110]                     => test1 runned! ([ 3.0]Sec.) -> 1_due[33574]
[30652]                     [01:36:188] => test3 runned! ([ 3.0]Sec.) -> 3_due[33652]
[31074]           [01:36:610]           => test2 runned! ([ 3.0]Sec.) -> 2_due[34074]
[33574] [01:39:110]                     => test1 runned! ([ 3.0]Sec.) -> 1_due[36574]
[33652]                     [01:39:188] => test3 runned! ([ 3.0]Sec.) -> 3_due[36652]
[34074]           [01:39:610]           => test2 runned! ([ 3.0]Sec.) -> 2_due[37074]
[36574] [01:42:110]                     => test1 runned! ([ 3.0]Sec.) -> 1_due[39574]
[36652]                     [01:42:188] => test3 runned! ([ 3.0]Sec.) -> 3_due[39652]
[37074]           [01:42:610]           => test2 runned! ([ 3.0]Sec.) -> 2_due[40074]
[39574] [01:45:110]                     => test1 runned! ([ 3.0]Sec.) -> 1_due[42574]
[39652]                     [01:45:188] => test3 runned! ([ 3.0]Sec.) -> 3_due[42652]
[40074]           [01:45:610]           => test2 runned! ([ 3.0]Sec.) -> 2_due[43074]
[42574] [01:48:110]                     => test1 runned! ([ 3.0]Sec.) -> 1_due[45574]
[42652]                     [01:48:188] => test3 runned! ([ 3.0]Sec.) -> 3_due[45652]
[43074]           [01:48:610]           => test2 runned! ([ 3.0]Sec.) -> 2_due[46074]
[45574] [01:51:110]                     => test1 runned! ([ 3.0]Sec.) -> 1_due[48574]
[45652]                     [01:51:188] => test3 runned! ([ 3.0]Sec.) -> 3_due[48652]
[46074]           [01:51:610]           => test2 runned! ([ 3.0]Sec.) -> 2_due[49074]
[48574] [01:54:110]                     => test1 runned! ([ 3.0]Sec.) -> 1_due[51574]
[48652]                     [01:54:188] => test3 runned! ([ 3.0]Sec.) -> 3_due[51652]
[49074]           [01:54:610]           => test2 runned! ([ 3.0]Sec.) -> 2_due[52074]
[51574] [01:57:110]                     => test1 runned! ([ 3.0]Sec.) -> 1_due[54574]
[51652]                     [01:57:188] => test3 runned! ([ 3.0]Sec.) -> 3_due[54652]
[52074]           [01:57:610]           => test2 runned! ([ 3.0]Sec.) -> 2_due[55074]
[54574] [02:00:110]                     => test1 runned! ([ 3.0]Sec.) -> 1_due[57574]
[54652]                     [02:00:188] => test3 runned! ([ 3.0]Sec.) -> 3_due[57652]
[55074]           [02:00:610]           => test2 runned! ([ 3.0]Sec.) -> 2_due[58074]
[57574] [02:03:110]                     => test1 runned! ([ 3.0]Sec.) -> 1_due[60574]
[57652]                     [02:03:188] => test3 runned! ([ 3.0]Sec.) -> 3_due[60652]
[58074]           [02:03:610]           => test2 runned! ([ 3.0]Sec.) -> 2_due[61074]
[60574] [02:06:110]                     => test1 runned! ([ 3.0]Sec.) -> 1_due[63574]
[60652]                     [02:06:188] => test3 runned! ([ 3.0]Sec.) -> 3_due[63652]
[61074]           [02:06:610]           => test2 runned! ([ 3.0]Sec.) -> 2_due[64074]
[63574] [02:09:110]                     => test1 runned! ([ 3.0]Sec.) -> 1_due[ 1038]
[63652]                     [02:09:188] => test3 runned! ([ 3.0]Sec.) -> 3_due[ 1116]
[64074]           [02:09:610]           => test2 runned! ([ 3.0]Sec.) -> 2_due[ 1538]

[64574] hold ... 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1 .. continue
****************************** Random Delays ******************************

[14042] startWaiting: Time left [  17014]ms, [   17]sec., [ 0]min.
[14044] timerTest1: Time past/left [ 1471/ 1529]ms  next due after [15570]!
[14051] timerTest2: Time past/left [  978/ 2022]ms  next due after [16070]!
[14058] timerTest3: Time past/left [ 1407/ 1593]ms  next due after [15650]!

[14182] [02:25:254]                     => test1 runned! ([16.1]Sec.) -> 1_due[ 4038]
[14191]           [02:25:263]           => test2 runned! ([15.7]Sec.) -> 2_due[16538]
[14199]                     [02:25:271] => test3 runned! ([16.1]Sec.) -> 3_due[17199]
[14635] [02:25:707]                     => test1 runned! ([ 0.4]Sec.) -> 1_due[ 7038]
[15024] [02:26:096]                     => test1 runned! ([ 0.4]Sec.) -> 1_due[10038]
[15217] [02:26:289]                     => test1 runned! ([ 0.2]Sec.) -> 1_due[13038]
[15525] [02:26:597]                     => test1 runned! ([ 0.3]Sec.) -> 1_due[16038]
[16043] [02:27:115]                     => test1 runned! ([ 0.5]Sec.) -> 1_due[19038]
[16692]           [02:27:764]           => test2 runned! ([ 2.5]Sec.) -> 2_due[19538]
[17559]                     [02:28:631] => test3 runned! ([ 3.4]Sec.) -> 3_due[20559]
[19204] [02:30:276]                     => test1 runned! ([ 3.2]Sec.) -> 1_due[22038]
[19675]           [02:30:747]           => test2 runned! ([ 3.0]Sec.) -> 2_due[22538]
[20638]                     [02:31:710] => test3 runned! ([ 3.1]Sec.) -> 3_due[23638]
[22369] [02:33:441]                     => test1 runned! ([ 3.2]Sec.) -> 1_due[25038]
[22708]           [02:33:780]           => test2 runned! ([ 3.0]Sec.) -> 2_due[25538]
[23695]                     [02:34:767] => test3 runned! ([ 3.1]Sec.) -> 3_due[26695]
[25156] [02:36:228]                     => test1 runned! ([ 2.8]Sec.) -> 1_due[28038]
[25563]           [02:36:635]           => test2 runned! ([ 2.9]Sec.) -> 2_due[28538]
[26927]                     [02:37:999] => test3 runned! ([ 3.2]Sec.) -> 3_due[29927]
[28354] [02:39:426]                     => test1 runned! ([ 3.2]Sec.) -> 1_due[31038]
[28698]           [02:39:770]           => test2 runned! ([ 3.1]Sec.) -> 2_due[31538]
[30035]                     [02:41:107] => test3 runned! ([ 3.1]Sec.) -> 3_due[33035]
[31250] [02:42:322]                     => test1 runned! ([ 2.9]Sec.) -> 1_due[34038]
[31546]           [02:42:619]           => test2 runned! ([ 2.8]Sec.) -> 2_due[34538]
[33081]                     [02:44:153] => test3 runned! ([ 3.0]Sec.) -> 3_due[36081]
[34092] [02:45:164]                     => test1 runned! ([ 2.8]Sec.) -> 1_due[37038]
[34694]           [02:45:766]           => test2 runned! ([ 3.1]Sec.) -> 2_due[37538]
[36087]                     [02:47:159] => test3 runned! ([ 3.0]Sec.) -> 3_due[39087]
[37040] [02:48:112]                     => test1 runned! ([ 2.9]Sec.) -> 1_due[40038]
[37662]           [02:48:734]           => test2 runned! ([ 3.0]Sec.) -> 2_due[40538]
[39405]                     [02:50:477] => test3 runned! ([ 3.3]Sec.) -> 3_due[42405]
[40382] [02:51:454]                     => test1 runned! ([ 3.3]Sec.) -> 1_due[43038]
[40889]           [02:51:961]           => test2 runned! ([ 3.2]Sec.) -> 2_due[43538]
[42658]                     [02:53:730] => test3 runned! ([ 3.3]Sec.) -> 3_due[45658]
[43068] [02:54:140]                     => test1 runned! ([ 2.7]Sec.) -> 1_due[46038]
[44003]           [02:55:075]           => test2 runned! ([ 3.1]Sec.) -> 2_due[46538]
[45902]                     [02:56:974] => test3 runned! ([ 3.2]Sec.) -> 3_due[48902]
[46179] [02:57:251]                     => test1 runned! ([ 3.1]Sec.) -> 1_due[49038]
[47008]           [02:58:080]           => test2 runned! ([ 3.0]Sec.) -> 2_due[49538]
[49203] [03:00:275]                     => test1 runned! ([ 3.0]Sec.) -> 1_due[52038]
[49211]                     [03:00:283] => test3 runned! ([ 3.3]Sec.) -> 3_due[52211]
[49659]           [03:00:731]           => test2 runned! ([ 2.7]Sec.) -> 2_due[52538]
[52206] [03:03:278]                     => test1 runned! ([ 3.0]Sec.) -> 1_due[55038]
[52215]                     [03:03:287] => test3 runned! ([ 3.0]Sec.) -> 3_due[55215]
[52782]           [03:03:854]           => test2 runned! ([ 3.1]Sec.) -> 2_due[55538]
[55139] [03:06:211]                     => test1 runned! ([ 2.9]Sec.) -> 1_due[58038]

[55148] test1 counted[62] times run in [62] events --> EQUAL
[55148] test2 counted[57] times run in [62] events --> ? (5 off)
[55148] test3 counted[54] times run in [62] events --> ? (8 off)

[55154] wait ... wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww.. continue

[60013] startHolding: Time left [  84051]ms, [   84]sec, [ 1]min.
[60013] timerTest1: Time past/left [ 2440/  560]ms  next due after [60570]!
[60015] timerTest2: Time past/left [ 1942/ 1058]ms  next due after [61070]!
[60021] timerTest3: Time past/left [ 2271/  729]ms  next due after [60750]!

[60258] [03:11:330]                     => test1 runned! ([ 5.1]Sec.) -> 1_due[61038]
[60267]           [03:11:339]           => test2 runned! ([ 7.5]Sec.) -> 2_due[61538]
[60275]                     [03:11:347] => test3 runned! ([ 8.1]Sec.) -> 3_due[63275]
[61166] [03:12:238]                     => test1 runned! ([ 0.9]Sec.) -> 1_due[64038]
[61623]           [03:12:695]           => test2 runned! ([ 1.4]Sec.) -> 2_due[64538]
[63562]                     [03:14:634] => test3 runned! ([ 3.3]Sec.) -> 3_due[ 1026]
[64271] [03:15:343]                     => test1 runned! ([ 3.1]Sec.) -> 1_due[ 1502]
[64606]           [03:15:678]           => test2 runned! ([ 3.0]Sec.) -> 2_due[ 2002]

[  354] ***** timer16Bit() has rolled-over! *****
[  355] timerTest1: Time past/left [ 1853/ 1147]ms  next due after [ 1500]!
[  355] timerTest2: Time past/left [ 1353/ 1647]ms  next due after [ 2000]!
[  361] timerTest3: Time past/left [ 2335/  665]ms  next due after [ 1020]!

[ 1278]                     [03:17:886] => test3 runned! ([ 3.3]Sec.) -> 3_due[ 4278]
[ 1737] [03:18:345]                     => test1 runned! ([ 3.0]Sec.) -> 1_due[ 4502]
[ 2053]           [03:18:661]           => test2 runned! ([ 3.0]Sec.) -> 2_due[ 5002]
[ 4598] [03:21:206]                     => test1 runned! ([ 2.9]Sec.) -> 1_due[ 7502]
[ 4606]                     [03:21:214] => test3 runned! ([ 3.3]Sec.) -> 3_due[ 7606]
[ 5272]           [03:21:880]           => test2 runned! ([ 3.2]Sec.) -> 2_due[ 8002]
[ 7621] [03:24:229]                     => test1 runned! ([ 3.0]Sec.) -> 1_due[10502]
[ 7630]                     [03:24:238] => test3 runned! ([ 3.0]Sec.) -> 3_due[10630]
[ 8303]           [03:24:911]           => test2 runned! ([ 3.0]Sec.) -> 2_due[11002]
[10585] [03:27:193]                     => test1 runned! ([ 3.0]Sec.) -> 1_due[13502]
[10942]                     [03:27:550] => test3 runned! ([ 3.3]Sec.) -> 3_due[13942]
[11408]           [03:28:016]           => test2 runned! ([ 3.1]Sec.) -> 2_due[14002]
[13599] [03:30:207]                     => test1 runned! ([ 3.0]Sec.) -> 1_due[16502]
[14029]           [03:30:637]           => test2 runned! ([ 2.6]Sec.) -> 2_due[17002]
[14037]                     [03:30:645] => test3 runned! ([ 3.1]Sec.) -> 3_due[17037]
[16650] [03:33:258]                     => test1 runned! ([ 3.0]Sec.) -> 1_due[19502]
[17046]           [03:33:654]           => test2 runned! ([ 3.0]Sec.) -> 2_due[20002]
[17055]                     [03:33:663] => test3 runned! ([ 3.0]Sec.) -> 3_due[20055]
[19567] [03:36:175]                     => test1 runned! ([ 2.9]Sec.) -> 1_due[22502]
[20345]           [03:36:953]           => test2 runned! ([ 3.3]Sec.) -> 2_due[23002]
[20354]                     [03:36:962] => test3 runned! ([ 3.3]Sec.) -> 3_due[23354]
[22536] [03:39:144]                     => test1 runned! ([ 3.0]Sec.) -> 1_due[25502]
[23267]           [03:39:875]           => test2 runned! ([ 2.9]Sec.) -> 2_due[26002]
[23751]                     [03:40:359] => test3 runned! ([ 3.4]Sec.) -> 3_due[26751]
[25956] [03:42:564]                     => test1 runned! ([ 3.4]Sec.) -> 1_due[28502]
[26089]           [03:42:697]           => test2 runned! ([ 2.8]Sec.) -> 2_due[29002]
[26810]                     [03:43:418] => test3 runned! ([ 3.1]Sec.) -> 3_due[29810]
[28570] [03:45:178]                     => test1 runned! ([ 2.6]Sec.) -> 1_due[31502]
[29212]           [03:45:820]           => test2 runned! ([ 3.1]Sec.) -> 2_due[32002]
[29866]                     [03:46:474] => test3 runned! ([ 3.1]Sec.) -> 3_due[32866]
[31851] [03:48:459]                     => test1 runned! ([ 3.3]Sec.) -> 1_due[34502]
[32133]           [03:48:741]           => test2 runned! ([ 2.9]Sec.) -> 2_due[35002]
[32970]                     [03:49:578] => test3 runned! ([ 3.1]Sec.) -> 3_due[35970]
[34660] [03:51:268]                     => test1 runned! ([ 2.8]Sec.) -> 1_due[37502]
[35193]           [03:51:801]           => test2 runned! ([ 3.1]Sec.) -> 2_due[38002]

[35676] test1 counted[77] times run in [77] events --> EQUAL
[35677] test2 counted[72] times run in [77] events --> ? (5 off)
[35677] test3 counted[67] times run in [77] events --> ? (10 off)

[35683] wait ... wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww.. continue

[39886] startHolding: Time left [  38641]ms, [   38]sec, [ 0]min.
[39887] timerTest1: Time past/left [ 2850/  150]ms  next due after [40030]!
[39888] timerTest2: Time past/left [ 2351/  649]ms  next due after [40530]!
[39895] timerTest3: Time past/left [ 1390/ 1610]ms  next due after [41500]!

[39999] [03:56:607]                     => test1 runned! ([ 5.3]Sec.) -> 1_due[40502]
[40008]           [03:56:616]           => test2 runned! ([ 4.8]Sec.) -> 2_due[41002]
[40016]                     [03:56:624] => test3 runned! ([ 7.0]Sec.) -> 3_due[43016]
[40585] [03:57:193]                     => test1 runned! ([ 0.6]Sec.) -> 1_due[43502]
[41175]           [03:57:783]           => test2 runned! ([ 1.2]Sec.) -> 2_due[44002]
[43106]                     [03:59:714] => test3 runned! ([ 3.1]Sec.) -> 3_due[46106]
[43863] [04:00:471]                     => test1 runned! ([ 3.3]Sec.) -> 1_due[46502]
[44210]           [04:00:818]           => test2 runned! ([ 3.0]Sec.) -> 2_due[47002]
[46341]                     [04:02:949] => test3 runned! ([ 3.2]Sec.) -> 3_due[49341]
[46848] [04:03:456]                     => test1 runned! ([ 3.0]Sec.) -> 1_due[49502]
[47063]           [04:03:671]           => test2 runned! ([ 2.9]Sec.) -> 2_due[50002]
[49351]                     [04:05:959] => test3 runned! ([ 3.0]Sec.) -> 3_due[52351]
[49552] [04:06:160]                     => test1 runned! ([ 2.7]Sec.) -> 1_due[52502]
[50349]           [04:06:957]           => test2 runned! ([ 3.3]Sec.) -> 2_due[53002]
[52681] [04:09:289]                     => test1 runned! ([ 3.1]Sec.) -> 1_due[55502]
[52690]                     [04:09:298] => test3 runned! ([ 3.3]Sec.) -> 3_due[55690]
[53100]           [04:09:708]           => test2 runned! ([ 2.8]Sec.) -> 2_due[56002]
[55602] [04:12:210]                     => test1 runned! ([ 2.9]Sec.) -> 1_due[58502]
[55884]                     [04:12:492] => test3 runned! ([ 3.2]Sec.) -> 3_due[58884]
[56052]           [04:12:660]           => test2 runned! ([ 3.0]Sec.) -> 2_due[59002]
[58627] [04:15:235]                     => test1 runned! ([ 3.0]Sec.) -> 1_due[61502]
[58999]                     [04:15:607] => test3 runned! ([ 3.1]Sec.) -> 3_due[61999]
[59400]           [04:16:008]           => test2 runned! ([ 3.3]Sec.) -> 2_due[62002]
[61681] [04:18:289]                     => test1 runned! ([ 3.0]Sec.) -> 1_due[64502]
[62196]           [04:18:804]           => test2 runned! ([ 2.8]Sec.) -> 2_due[65002]
[62204]                     [04:18:812] => test3 runned! ([ 3.2]Sec.) -> 3_due[65204]
[64514] [04:21:122]                     => test1 runned! ([ 2.8]Sec.) -> 1_due[ 1966]
[65073]           [04:21:681]           => test2 runned! ([ 2.9]Sec.) -> 2_due[ 2466]
[65428]                     [04:22:037] => test3 runned! ([ 3.2]Sec.) -> 3_due[ 2892]

[  100] ***** timer16Bit() has rolled-over! *****
[  100] timerTest1: Time past/left [ 1135/ 1865]ms  next due after [ 1960]!
[  101] timerTest2: Time past/left [  635/ 2365]ms  next due after [ 2460]!
[  107] timerTest3: Time past/left [  215/ 2785]ms  next due after [ 2890]!

[ 1999] [04:24:143]                     => test1 runned! ([ 3.0]Sec.) -> 1_due[ 4966]
[ 2564]           [04:24:708]           => test2 runned! ([ 3.0]Sec.) -> 2_due[ 5466]
[ 2923]                     [04:25:067] => test3 runned! ([ 3.0]Sec.) -> 3_due[ 5923]
[ 5137] [04:27:281]                     => test1 runned! ([ 3.1]Sec.) -> 1_due[ 7966]
[ 5483]           [04:27:627]           => test2 runned! ([ 2.9]Sec.) -> 2_due[ 8466]
[ 5959]                     [04:28:103] => test3 runned! ([ 3.0]Sec.) -> 3_due[ 8959]
[ 8197] [04:30:341]                     => test1 runned! ([ 3.1]Sec.) -> 1_due[10966]
[ 8711]           [04:30:855]           => test2 runned! ([ 3.2]Sec.) -> 2_due[11466]
[ 9197]                     [04:31:341] => test3 runned! ([ 3.2]Sec.) -> 3_due[12197]
[11158] [04:33:302]                     => test1 runned! ([ 3.0]Sec.) -> 1_due[13966]
[11472]           [04:33:616]           => test2 runned! ([ 2.8]Sec.) -> 2_due[14466]
[12405]                     [04:34:549] => test3 runned! ([ 3.2]Sec.) -> 3_due[15405]

[13091] hold ... 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1 .. continue
*************************** NO random delays! *****************************

[28094] startWaiting: Time left [  18239]ms, [   18]sec., [ 0]min.
[28097] timerTest1: Time past/left [ 2596/  404]ms  next due after [28500]!
[28103] timerTest2: Time past/left [ 2103/  897]ms  next due after [29000]!
[28110] timerTest3: Time past/left [ 1170/ 1830]ms  next due after [29940]!

[28117] [04:50:261]                     => test1 runned! ([17.0]Sec.) -> 1_due[16966]
[28136]           [04:50:280]           => test2 runned! ([16.7]Sec.) -> 2_due[29466]
[28144]                     [04:50:288] => test3 runned! ([15.7]Sec.) -> 3_due[31144]
[28152] [04:50:296]                     => test1 runned! ([ 0.0]Sec.) -> 1_due[19966]
[28161] [04:50:305]                     => test1 runned! ([ 0.0]Sec.) -> 1_due[22966]
[28169] [04:50:313]                     => test1 runned! ([ 0.0]Sec.) -> 1_due[25966]
[28177] [04:50:321]                     => test1 runned! ([ 0.0]Sec.) -> 1_due[28966]
[28966] [04:51:110]                     => test1 runned! ([ 0.8]Sec.) -> 1_due[31966]
[29466]           [04:51:610]           => test2 runned! ([ 1.3]Sec.) -> 2_due[32466]
[31144]                     [04:53:288] => test3 runned! ([ 3.0]Sec.) -> 3_due[34144]
[31966] [04:54:110]                     => test1 runned! ([ 3.0]Sec.) -> 1_due[34966]
[32466]           [04:54:610]           => test2 runned! ([ 3.0]Sec.) -> 2_due[35466]
[34144]                     [04:56:288] => test3 runned! ([ 3.0]Sec.) -> 3_due[37144]
[34966] [04:57:110]                     => test1 runned! ([ 3.0]Sec.) -> 1_due[37966]
[35466]           [04:57:610]           => test2 runned! ([ 3.0]Sec.) -> 2_due[38466]
[37144]                     [04:59:288] => test3 runned! ([ 3.0]Sec.) -> 3_due[40144]
[37966] [05:00:110]                     => test1 runned! ([ 3.0]Sec.) -> 1_due[40966]
[38466]           [05:00:610]           => test2 runned! ([ 3.0]Sec.) -> 2_due[41466]
[40144]                     [05:02:288] => test3 runned! ([ 3.0]Sec.) -> 3_due[43144]
[40966] [05:03:110]                     => test1 runned! ([ 3.0]Sec.) -> 1_due[43966]
[41466]           [05:03:610]           => test2 runned! ([ 3.0]Sec.) -> 2_due[44466]
[43144]                     [05:05:288] => test3 runned! ([ 3.0]Sec.) -> 3_due[46144]
[43966] [05:06:110]                     => test1 runned! ([ 3.0]Sec.) -> 1_due[46966]
[44466]           [05:06:610]           => test2 runned! ([ 3.0]Sec.) -> 2_due[47466]
[46144]                     [05:08:288] => test3 runned! ([ 3.0]Sec.) -> 3_due[49144]
[46966] [05:09:110]                     => test1 runned! ([ 3.0]Sec.) -> 1_due[49966]
[47466]           [05:09:610]           => test2 runned! ([ 3.0]Sec.) -> 2_due[50466]
[49144]                     [05:11:288] => test3 runned! ([ 3.0]Sec.) -> 3_due[52144]
[49966] [05:12:110]                     => test1 runned! ([ 3.0]Sec.) -> 1_due[52966]
[50466]           [05:12:610]           => test2 runned! ([ 3.0]Sec.) -> 2_due[53466]
[52144]                     [05:14:288] => test3 runned! ([ 3.0]Sec.) -> 3_due[55144]
[52966] [05:15:110]                     => test1 runned! ([ 3.0]Sec.) -> 1_due[55966]
[53466]           [05:15:610]           => test2 runned! ([ 3.0]Sec.) -> 2_due[56466]
[55144]                     [05:17:288] => test3 runned! ([ 3.0]Sec.) -> 3_due[58144]
[55966] [05:18:110]                     => test1 runned! ([ 3.0]Sec.) -> 1_due[58966]
[56466]           [05:18:610]           => test2 runned! ([ 3.0]Sec.) -> 2_due[59466]
[58144]                     [05:20:288] => test3 runned! ([ 3.0]Sec.) -> 3_due[61144]
[58966] [05:21:110]                     => test1 runned! ([ 3.0]Sec.) -> 1_due[61966]
[59466]           [05:21:610]           => test2 runned! ([ 3.0]Sec.) -> 2_due[62466]
[61144]                     [05:23:288] => test3 runned! ([ 3.0]Sec.) -> 3_due[64144]
[61966] [05:24:110]                     => test1 runned! ([ 3.0]Sec.) -> 1_due[64966]
[62466]           [05:24:610]           => test2 runned! ([ 3.0]Sec.) -> 2_due[65466]
[64144]                     [05:26:288] => test3 runned! ([ 3.0]Sec.) -> 3_due[ 1608]
[64966] [05:27:110]                     => test1 runned! ([ 3.0]Sec.) -> 1_due[ 2430]
[65466]           [05:27:610]           => test2 runned! ([ 3.0]Sec.) -> 2_due[ 2930]

[    0] ***** timer16Bit() has rolled-over! *****
[    0] timerTest1: Time past/left [  570/ 2430]ms  next due after [ 2430]!
[    0] timerTest2: Time past/left [   70/ 2930]ms  next due after [ 2930]!
[    6] timerTest3: Time past/left [ 1398/ 1602]ms  next due after [ 1600]!

[ 1608]                     [05:29:288] => test3 runned! ([ 3.0]Sec.) -> 3_due[ 4608]
[ 2430] [05:30:110]                     => test1 runned! ([ 3.0]Sec.) -> 1_due[ 5430]
[ 2930]           [05:30:610]           => test2 runned! ([ 3.0]Sec.) -> 2_due[ 5930]

[ 3581] test1 counted[110] times run in [110] events --> EQUAL
[ 3581] test2 counted[101] times run in [110] events --> ? (9 off)
[ 3582] test3 counted[94] times run in [110] events --> ? (16 off)

[ 3588] wait ... wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww.. continue

[ 7592] startHolding: Time left [  84989]ms, [   84]sec, [ 1]min.
[ 7592] timerTest1: Time past/left [ 2627/  373]ms  next due after [ 7960]!
[ 7594] timerTest2: Time past/left [ 2129/  871]ms  next due after [ 8460]!
[ 7601] timerTest3: Time past/left [  458/ 2542]ms  next due after [10140]!

[ 7608] [05:35:288]                     => test1 runned! ([ 5.2]Sec.) -> 1_due[ 8430]
[ 7626]           [05:35:307]           => test2 runned! ([ 4.7]Sec.) -> 2_due[ 8930]
[ 7635]                     [05:35:315] => test3 runned! ([ 6.0]Sec.) -> 3_due[10635]
[ 8430] [05:36:110]                     => test1 runned! ([ 0.8]Sec.) -> 1_due[11430]
[ 8930]           [05:36:610]           => test2 runned! ([ 1.3]Sec.) -> 2_due[11930]
[10635]                     [05:38:315] => test3 runned! ([ 3.0]Sec.) -> 3_due[13635]
[11430] [05:39:110]                     => test1 runned! ([ 3.0]Sec.) -> 1_due[14430]
[11930]           [05:39:610]           => test2 runned! ([ 3.0]Sec.) -> 2_due[14930]
[13635]                     [05:41:315] => test3 runned! ([ 3.0]Sec.) -> 3_due[16635]
[14430] [05:42:110]                     => test1 runned! ([ 3.0]Sec.) -> 1_due[17430]
[14930]           [05:42:610]           => test2 runned! ([ 3.0]Sec.) -> 2_due[17930]
[16635]                     [05:44:315] => test3 runned! ([ 3.0]Sec.) -> 3_due[19635]
[17430] [05:45:110]                     => test1 runned! ([ 3.0]Sec.) -> 1_due[20430]
[17930]           [05:45:610]           => test2 runned! ([ 3.0]Sec.) -> 2_due[20930]
[19635]                     [05:47:315] => test3 runned! ([ 3.0]Sec.) -> 3_due[22635]
[20430] [05:48:110]                     => test1 runned! ([ 3.0]Sec.) -> 1_due[23430]
[20930]           [05:48:610]           => test2 runned! ([ 3.0]Sec.) -> 2_due[23930]
[22635]                     [05:50:315] => test3 runned! ([ 3.0]Sec.) -> 3_due[25635]
[23430] [05:51:110]                     => test1 runned! ([ 3.0]Sec.) -> 1_due[26430]
[23930]           [05:51:610]           => test2 runned! ([ 3.0]Sec.) -> 2_due[26930]
[25635]                     [05:53:315] => test3 runned! ([ 3.0]Sec.) -> 3_due[28635]
[26430] [05:54:110]                     => test1 runned! ([ 3.0]Sec.) -> 1_due[29430]
[26930]           [05:54:610]           => test2 runned! ([ 3.0]Sec.) -> 2_due[29930]
[28635]                     [05:56:315] => test3 runned! ([ 3.0]Sec.) -> 3_due[31635]
[29430] [05:57:110]                     => test1 runned! ([ 3.0]Sec.) -> 1_due[32430]
[29930]           [05:57:610]           => test2 runned! ([ 3.0]Sec.) -> 2_due[32930]
[31635]                     [05:59:315] => test3 runned! ([ 3.0]Sec.) -> 3_due[34635]
[32430] [06:00:110]                     => test1 runned! ([ 3.0]Sec.) -> 1_due[35430]
[32930]           [06:00:610]           => test2 runned! ([ 3.0]Sec.) -> 2_due[35930]
[34635]                     [06:02:315] => test3 runned! ([ 3.0]Sec.) -> 3_due[37635]
[35430] [06:03:110]                     => test1 runned! ([ 3.0]Sec.) -> 1_due[38430]
[35930]           [06:03:610]           => test2 runned! ([ 3.0]Sec.) -> 2_due[38930]
[37635]                     [06:05:315] => test3 runned! ([ 3.0]Sec.) -> 3_due[40635]
[38430] [06:06:110]                     => test1 runned! ([ 3.0]Sec.) -> 1_due[41430]
[38930]           [06:06:610]           => test2 runned! ([ 3.0]Sec.) -> 2_due[41930]
[40635]                     [06:08:315] => test3 runned! ([ 3.0]Sec.) -> 3_due[43635]
[41430] [06:09:110]                     => test1 runned! ([ 3.0]Sec.) -> 1_due[44430]
[41930]           [06:09:610]           => test2 runned! ([ 3.0]Sec.) -> 2_due[44930]
[43635]                     [06:11:315] => test3 runned! ([ 3.0]Sec.) -> 3_due[46635]
[44430] [06:12:110]                     => test1 runned! ([ 3.0]Sec.) -> 1_due[47430]
[44930]           [06:12:610]           => test2 runned! ([ 3.0]Sec.) -> 2_due[47930]
[46635]                     [06:14:315] => test3 runned! ([ 3.0]Sec.) -> 3_due[49635]
[47430] [06:15:110]                     => test1 runned! ([ 3.0]Sec.) -> 1_due[50430]
[47930]           [06:15:610]           => test2 runned! ([ 3.0]Sec.) -> 2_due[50930]

[48608] test1 counted[125] times run in [125] events --> EQUAL
[48608] test2 counted[116] times run in [125] events --> ? (9 off)
[48608] test3 counted[108] times run in [125] events --> ? (17 off)

[48614] wait ... wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww.. continue

[52618] startHolding: Time left [  39962]ms, [   39]sec, [ 0]min.
[52619] timerTest1: Time past/left [ 2654/  346]ms  next due after [52960]!
[52621] timerTest2: Time past/left [ 2156/  844]ms  next due after [53460]!
[52628] timerTest3: Time past/left [  458/ 2542]ms  next due after [55170]!

[52635] [06:20:315]                     => test1 runned! ([ 5.2]Sec.) -> 1_due[53430]
[52653]           [06:20:333]           => test2 runned! ([ 4.7]Sec.) -> 2_due[53930]
[52662]                     [06:20:342] => test3 runned! ([ 6.0]Sec.) -> 3_due[55662]
[53430] [06:21:110]                     => test1 runned! ([ 0.8]Sec.) -> 1_due[56430]
[53930]           [06:21:610]           => test2 runned! ([ 1.3]Sec.) -> 2_due[56930]
[55662]                     [06:23:342] => test3 runned! ([ 3.0]Sec.) -> 3_due[58662]
[56430] [06:24:110]                     => test1 runned! ([ 3.0]Sec.) -> 1_due[59430]
[56930]           [06:24:610]           => test2 runned! ([ 3.0]Sec.) -> 2_due[59930]
[58662]                     [06:26:342] => test3 runned! ([ 3.0]Sec.) -> 3_due[61662]
[59430] [06:27:110]                     => test1 runned! ([ 3.0]Sec.) -> 1_due[62430]
[59930]           [06:27:610]           => test2 runned! ([ 3.0]Sec.) -> 2_due[62930]
[61662]                     [06:29:342] => test3 runned! ([ 3.0]Sec.) -> 3_due[64662]
[62430] [06:30:110]                     => test1 runned! ([ 3.0]Sec.) -> 1_due[65430]
[62930]           [06:30:610]           => test2 runned! ([ 3.0]Sec.) -> 2_due[  394]
[64662]                     [06:32:342] => test3 runned! ([ 3.0]Sec.) -> 3_due[ 2126]
[65430] [06:33:110]                     => test1 runned! ([ 3.0]Sec.) -> 1_due[ 2894]

[    0] ***** timer16Bit() has rolled-over! *****
[    0] timerTest1: Time past/left [  106/ 2894]ms  next due after [ 2890]!
[    0] timerTest2: Time past/left [ 2606/  394]ms  next due after [  390]!
[    6] timerTest3: Time past/left [  881/ 2119]ms  next due after [ 2120]!

[  394]           [06:33:610]           => test2 runned! ([ 3.0]Sec.) -> 2_due[ 3394]
[ 2126]                     [06:35:342] => test3 runned! ([ 3.0]Sec.) -> 3_due[ 5126]
[ 2894] [06:36:110]                     => test1 runned! ([ 3.0]Sec.) -> 1_due[ 5894]
[ 3394]           [06:36:610]           => test2 runned! ([ 3.0]Sec.) -> 2_due[ 6394]
[ 5126]                     [06:38:342] => test3 runned! ([ 3.0]Sec.) -> 3_due[ 8126]
[ 5894] [06:39:110]                     => test1 runned! ([ 3.0]Sec.) -> 1_due[ 8894]
[ 6394]           [06:39:610]           => test2 runned! ([ 3.0]Sec.) -> 2_due[ 9394]
[ 8126]                     [06:41:342] => test3 runned! ([ 3.0]Sec.) -> 3_due[11126]
[ 8894] [06:42:110]                     => test1 runned! ([ 3.0]Sec.) -> 1_due[11894]
[ 9394]           [06:42:610]           => test2 runned! ([ 3.0]Sec.) -> 2_due[12394]
[11126]                     [06:44:342] => test3 runned! ([ 3.0]Sec.) -> 3_due[14126]
[11894] [06:45:110]                     => test1 runned! ([ 3.0]Sec.) -> 1_due[14894]
[12394]           [06:45:610]           => test2 runned! ([ 3.0]Sec.) -> 2_due[15394]
[14126]                     [06:47:342] => test3 runned! ([ 3.0]Sec.) -> 3_due[17126]
[14894] [06:48:110]                     => test1 runned! ([ 3.0]Sec.) -> 1_due[17894]
[15394]           [06:48:610]           => test2 runned! ([ 3.0]Sec.) -> 2_due[18394]
[17126]                     [06:50:342] => test3 runned! ([ 3.0]Sec.) -> 3_due[20126]
[17894] [06:51:110]                     => test1 runned! ([ 3.0]Sec.) -> 1_due[20894]
[18394]           [06:51:610]           => test2 runned! ([ 3.0]Sec.) -> 2_due[21394]
[20126]                     [06:53:342] => test3 runned! ([ 3.0]Sec.) -> 3_due[23126]
[20894] [06:54:110]                     => test1 runned! ([ 3.0]Sec.) -> 1_due[23894]
[21394]           [06:54:610]           => test2 runned! ([ 3.0]Sec.) -> 2_due[24394]
[23126]                     [06:56:342] => test3 runned! ([ 3.0]Sec.) -> 3_due[26126]
[23894] [06:57:110]                     => test1 runned! ([ 3.0]Sec.) -> 1_due[26894]
[24394]           [06:57:610]           => test2 runned! ([ 3.0]Sec.) -> 2_due[27394]
[26126]                     [06:59:342] => test3 runned! ([ 3.0]Sec.) -> 3_due[29126]
[26894] [07:00:110]                     => test1 runned! ([ 3.0]Sec.) -> 1_due[29894]

[27045] hold ... 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1 .. continue
****************************** Random Delays ******************************

[42049] startWaiting: Time left [  17017]ms, [   17]sec., [ 0]min.
[42051] timerTest1: Time past/left [  622/ 2378]ms  next due after [44420]!
[42058] timerTest2: Time past/left [  129/ 2871]ms  next due after [44920]!
[42065] timerTest3: Time past/left [ 1404/ 1596]ms  next due after [43660]!

[42416] [07:15:632]                     => test1 runned! ([15.5]Sec.) -> 1_due[32894]
[42425]           [07:15:641]           => test2 runned! ([18.0]Sec.) -> 2_due[45394]
[42433]                     [07:15:649] => test3 runned! ([16.3]Sec.) -> 3_due[45433]
[42747] [07:15:963]                     => test1 runned! ([ 0.3]Sec.) -> 1_due[35894]
[43228] [07:16:444]                     => test1 runned! ([ 0.5]Sec.) -> 1_due[38894]
[43439] [07:16:655]                     => test1 runned! ([ 0.2]Sec.) -> 1_due[41894]
[43622] [07:16:838]                     => test1 runned! ([ 0.2]Sec.) -> 1_due[44894]
[45069] [07:18:285]                     => test1 runned! ([ 1.4]Sec.) -> 1_due[47894]
[45424]           [07:18:640]           => test2 runned! ([ 3.0]Sec.) -> 2_due[48394]
[45433]                     [07:18:649] => test3 runned! ([ 3.0]Sec.) -> 3_due[48433]
[48319] [07:21:535]                     => test1 runned! ([ 3.2]Sec.) -> 1_due[50894]
[48571]           [07:21:787]           => test2 runned! ([ 3.1]Sec.) -> 2_due[51394]
[48579]                     [07:21:795] => test3 runned! ([ 3.1]Sec.) -> 3_due[51579]
[51184] [07:24:400]                     => test1 runned! ([ 2.9]Sec.) -> 1_due[53894]
[51644]           [07:24:860]           => test2 runned! ([ 3.1]Sec.) -> 2_due[54394]
[51653]                     [07:24:869] => test3 runned! ([ 3.1]Sec.) -> 3_due[54652]
[54338] [07:27:554]                     => test1 runned! ([ 3.1]Sec.) -> 1_due[56894]
[54437]           [07:27:653]           => test2 runned! ([ 2.8]Sec.) -> 2_due[57394]
[54790]                     [07:28:006] => test3 runned! ([ 3.1]Sec.) -> 3_due[57790]
[57126] [07:30:342]                     => test1 runned! ([ 2.8]Sec.) -> 1_due[59894]
[57486]           [07:30:702]           => test2 runned! ([ 3.0]Sec.) -> 2_due[60394]
[58096]                     [07:31:312] => test3 runned! ([ 3.3]Sec.) -> 3_due[61095]
[60044] [07:33:260]                     => test1 runned! ([ 2.9]Sec.) -> 1_due[62894]
[60545]           [07:33:761]           => test2 runned! ([ 3.1]Sec.) -> 2_due[63394]
[61106]                     [07:34:322] => test3 runned! ([ 3.0]Sec.) -> 3_due[64106]
[63158] [07:36:374]                     => test1 runned! ([ 3.1]Sec.) -> 1_due[  358]
[63507]           [07:36:723]           => test2 runned! ([ 3.0]Sec.) -> 2_due[  858]
[64176]                     [07:37:392] => test3 runned! ([ 3.1]Sec.) -> 3_due[ 1640]

[  156] ***** timer16Bit() has rolled-over! *****
[  156] timerTest1: Time past/left [ 2798/  202]ms  next due after [  350]!
[  157] timerTest2: Time past/left [ 2299/  701]ms  next due after [  850]!
[  163] timerTest3: Time past/left [ 1523/ 1477]ms  next due after [ 1640]!

[  576] [07:39:328]                     => test1 runned! ([ 2.9]Sec.) -> 1_due[ 3358]
[  923]           [07:39:675]           => test2 runned! ([ 3.0]Sec.) -> 2_due[ 3858]
[ 1684]                     [07:40:436] => test3 runned! ([ 3.0]Sec.) -> 3_due[ 4684]
[ 3401] [07:42:153]                     => test1 runned! ([ 2.8]Sec.) -> 1_due[ 6358]
[ 3998]           [07:42:750]           => test2 runned! ([ 3.1]Sec.) -> 2_due[ 6858]
[ 4684]                     [07:43:436] => test3 runned! ([ 3.0]Sec.) -> 3_due[ 7684]
[ 6618] [07:45:370]                     => test1 runned! ([ 3.2]Sec.) -> 1_due[ 9358]
[ 6899]           [07:45:651]           => test2 runned! ([ 2.9]Sec.) -> 2_due[ 9858]
[ 7972]                     [07:46:724] => test3 runned! ([ 3.3]Sec.) -> 3_due[10972]
[ 9560] [07:48:312]                     => test1 runned! ([ 2.9]Sec.) -> 1_due[12358]
[10149]           [07:48:901]           => test2 runned! ([ 3.3]Sec.) -> 2_due[12858]
[11045]                     [07:49:797] => test3 runned! ([ 3.1]Sec.) -> 3_due[14045]
[12359] [07:51:111]                     => test1 runned! ([ 2.8]Sec.) -> 1_due[15358]
[13183]           [07:51:935]           => test2 runned! ([ 3.0]Sec.) -> 2_due[15858]
[14255]                     [07:53:007] => test3 runned! ([ 3.2]Sec.) -> 3_due[17254]
[15402] [07:54:154]                     => test1 runned! ([ 3.0]Sec.) -> 1_due[18358]
[15944]           [07:54:696]           => test2 runned! ([ 2.8]Sec.) -> 2_due[18858]
[17446]                     [07:56:198] => test3 runned! ([ 3.2]Sec.) -> 3_due[20446]

[17951] test1 counted[158] times run in [158] events --> EQUAL
[17951] test2 counted[144] times run in [158] events --> ? (14 off)
[17951] test3 counted[136] times run in [158] events --> ? (22 off)

[17957] wait ... wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww.. continue

[22486] startHolding: Time left [  84049]ms, [   84]sec, [ 1]min.
[22486] timerTest1: Time past/left [ 1593/ 1407]ms  next due after [23890]!
[22488] timerTest2: Time past/left [ 1095/ 1905]ms  next due after [24390]!
[22494] timerTest3: Time past/left [ 2513/  487]ms  next due after [22980]!

[22614] [08:01:366]                     => test1 runned! ([ 7.2]Sec.) -> 1_due[21358]
[22623]           [08:01:375]           => test2 runned! ([ 6.7]Sec.) -> 2_due[24858]
[22631]                     [08:01:383] => test3 runned! ([ 5.2]Sec.) -> 3_due[25631]
[22790] [08:01:542]                     => test1 runned! ([ 0.2]Sec.) -> 1_due[24358]
[24649] [08:03:401]                     => test1 runned! ([ 1.9]Sec.) -> 1_due[27358]
[25059]           [08:03:811]           => test2 runned! ([ 2.4]Sec.) -> 2_due[27858]
[25860]                     [08:04:612] => test3 runned! ([ 3.2]Sec.) -> 3_due[28860]
[27583] [08:06:335]                     => test1 runned! ([ 2.9]Sec.) -> 1_due[30358]
[28019]           [08:06:771]           => test2 runned! ([ 3.0]Sec.) -> 2_due[30858]
[28934]                     [08:07:686] => test3 runned! ([ 3.1]Sec.) -> 3_due[31934]
[30434] [08:09:186]                     => test1 runned! ([ 2.8]Sec.) -> 1_due[33358]
[31201]           [08:09:953]           => test2 runned! ([ 3.2]Sec.) -> 2_due[33858]
[32277]                     [08:11:029] => test3 runned! ([ 3.3]Sec.) -> 3_due[35277]
[33577] [08:12:329]                     => test1 runned! ([ 3.1]Sec.) -> 1_due[36358]
[33932]           [08:12:684]           => test2 runned! ([ 2.7]Sec.) -> 2_due[36858]
[35340]                     [08:14:092] => test3 runned! ([ 3.1]Sec.) -> 3_due[38340]
[36509] [08:15:261]                     => test1 runned! ([ 2.9]Sec.) -> 1_due[39358]
[36990]           [08:15:742]           => test2 runned! ([ 3.1]Sec.) -> 2_due[39858]
[38368]                     [08:17:120] => test3 runned! ([ 3.0]Sec.) -> 3_due[41368]
[39545] [08:18:297]                     => test1 runned! ([ 3.0]Sec.) -> 1_due[42358]
[39948]           [08:18:700]           => test2 runned! ([ 3.0]Sec.) -> 2_due[42858]
[41589]                     [08:20:341] => test3 runned! ([ 3.2]Sec.) -> 3_due[44589]
[42427] [08:21:179]                     => test1 runned! ([ 2.9]Sec.) -> 1_due[45358]
[42948]           [08:21:700]           => test2 runned! ([ 3.0]Sec.) -> 2_due[45858]
[44640]                     [08:23:392] => test3 runned! ([ 3.1]Sec.) -> 3_due[47640]
[45359] [08:24:111]                     => test1 runned! ([ 2.9]Sec.) -> 1_due[48358]
[45880]           [08:24:632]           => test2 runned! ([ 2.9]Sec.) -> 2_due[48858]
[47947]                     [08:26:699] => test3 runned! ([ 3.3]Sec.) -> 3_due[50947]
[48432] [08:27:184]                     => test1 runned! ([ 3.1]Sec.) -> 1_due[51358]
[49157]           [08:27:909]           => test2 runned! ([ 3.3]Sec.) -> 2_due[51858]
[50981]                     [08:29:733] => test3 runned! ([ 3.0]Sec.) -> 3_due[53981]
[51599] [08:30:351]                     => test1 runned! ([ 3.2]Sec.) -> 1_due[54358]
[51957]           [08:30:709]           => test2 runned! ([ 2.8]Sec.) -> 2_due[54858]
[54186]                     [08:32:938] => test3 runned! ([ 3.2]Sec.) -> 3_due[57185]
[54742] [08:33:494]                     => test1 runned! ([ 3.1]Sec.) -> 1_due[57358]
[55167]           [08:33:919]           => test2 runned! ([ 3.2]Sec.) -> 2_due[57858]
[57434] [08:36:186]                     => test1 runned! ([ 2.7]Sec.) -> 1_due[60358]
[57443]                     [08:36:195] => test3 runned! ([ 3.3]Sec.) -> 3_due[60443]
[57859]           [08:36:611]           => test2 runned! ([ 2.7]Sec.) -> 2_due[60858]
[60626] [08:39:378]                     => test1 runned! ([ 3.2]Sec.) -> 1_due[63358]
[60634]                     [08:39:386] => test3 runned! ([ 3.2]Sec.) -> 3_due[63634]
[60955]           [08:39:707]           => test2 runned! ([ 3.1]Sec.) -> 2_due[63858]
[63562] [08:42:314]                     => test1 runned! ([ 2.9]Sec.) -> 1_due[  822]

[63571] test1 counted[174] times run in [174] events --> EQUAL
[63571] test2 counted[158] times run in [174] events --> ? (16 off)
[63571] test3 counted[149] times run in [174] events --> ? (25 off)
