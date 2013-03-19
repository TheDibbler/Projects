
// Weather-Mon v0.3 Firmware
//
// sourced code from: http://www.chipkit.org/forum/viewtopic.php?f=6&t=1386
//         code author: James M. Lynes, Jr.
//         code name: Serial_Poll_Test.pde


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

}


char myAddr = 'Z';
char poll_code = ' ';

// Script


void loop() {

  waitpoll();

  poll_code = readpoll();

  if(poll_code == myAddr) {

    float h = dht.readHumidity();
    float t = dht.readTemperature();

    char tmpH[10];
    char tmpP[10];
    char tmpT[10];
    char tmpT2[10];

//    String jsonData;
    String sqlData;

    dtostrf(h,1,2,tmpH);
    dtostrf(t,1,2,tmpT2);
    dtostrf(bmp.readTemperature(),1,2,tmpT);
    dtostrf(bmp.readPressure(),1,2,tmpP);

//    jsonData = "{ \"sensorName\": \"WeatherMon\", \"airHumidity\": \"" + String(tmpH) + "\", \"airTemp\": \"" + String(tmpT) + "\", \"airPressure\": \"" + String(tmpP) + "\" } \n";
    sqlData = "( \"WeatherMon\", \"" +  String(tmpT) + "\", \"" + String(tmpH) + "\", \"" + String(tmpP) + "\" ) \n";
    Serial.print(sqlData);

    delay(10);

  }
}
void waitpoll()
{
  // Wait for a poll from the serial port
  // Returns when a character is available
  while(Serial.available() <= 0) {
    delay(1);
  }
} 

char readpoll()
{ 
  char poll_char = ' ';
  poll_char = Serial.read();
  return poll_char;
}

