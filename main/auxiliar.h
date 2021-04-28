//Import general modules
#include <math.h>

//Set DTH sensor
#include "DHT.h"
//Set sensor pin on 2
#define DHTPIN 2 
//Set on DHT22
#define DHTTYPE DHT22
//Initialize DHT sensor
DHT dht(DHTPIN, DHTTYPE);

void tempMeasuring(int second){
  dht.begin();

  if (fmod(second,2)==0){
      
      float h = dht.readHumidity();
      // Read temperature as Celsius the default (isFahrenheit = false)
       float t = dht.readTemperature();
  
      // Check if any reads failed and exit early (to try again).
      if (isnan(h) || isnan(t) ) {
        Serial.println(F("Failed to read from DHT sensor!"));
        return;
      }

      String humTempLog= "Hum: " + String(h) + "%, Temp: " + String(t) +"ºC";

      Serial.println(humTempLog);
    }
  
  }
