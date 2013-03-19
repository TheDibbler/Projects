
// Weather-Mon v0.1 Firmware
//


//
// Required Libraries
//

#include <Wire.h>
#include <Adafruit_BMP085.h>
#include "DHT.h"


#define DHTPIN 8          // Pin that DHT is connected to.
#define DHTTYPE DHT22     // Type of DHT sensor being used.



// Setup

Adafruit_BMP085 bmp;

DHT dht(DHTPIN, DHTTYPE);



void setup() {
  Serial.begin(9600);
  bmp.begin();
  dht.begin();
  
  delay(500);
}


// Script

void loop() {
  
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  
  
  Serial.print("{ ");
  Serial.print("sensorName: WeatherMon, ");
  Serial.print("airHumidity: ");
  Serial.print(h);
  Serial.print(", ");
  Serial.print("airTemp: ");
  Serial.print(bmp.readTemperature());
  Serial.print(", ");
  Serial.print("airPressure: ");
  Serial.print(bmp.readPressure());
  Serial.println(" }");
  
  delay(2000);
  
}
