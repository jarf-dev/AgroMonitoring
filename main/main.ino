//Include auxiliar modules
#include "auxiliar.h"

//Set DS1302 RTC module
#include <virtuabotixRTC.h>
//Set module pins on CLK: 6 , DAT: 7, Reset: 8
virtuabotixRTC myRTC(6, 7, 8);

void setup() {

  Serial.begin(9600);
  
}

void loop() {

  //update time measure
  myRTC.updateTime();
  //get a time log
  String timeLog= String(myRTC.dayofmonth) + "/" + String(myRTC.month) + "/" + String(myRTC.year) + " - " + myRTC.hours + ":" + myRTC.minutes  + ":" + myRTC.seconds;
  //print out time log
  Serial.println(timeLog);
  
  //print temperature and humidity measure (only available every 2 seconds)
  tempMeasuring(myRTC.seconds);

  //wait a second between measurements.
  delay(1000);
}
