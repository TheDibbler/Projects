/* Data gathering for solar and indoor based hydroponics

  Equipment used:
  
  Arduino Uno R3
  
  Adafruit BMP085 Breakout board ( Barometric pressure, temparture )
  Adafruit TSL2561 Breakout board ( Visible/IR light measurement )
  Adafruit DHT22/AM2302 ( Humidity, Temperature )
  
  
  Project Goal: Measure relevant environmental data for construction
                or use of enclosed environments for hydroponics.
                
  Version: 0.1
  
*/

#include <Wire.h>
#include "DHT.h"
#include "TSL2561.h"


#define DHTPIN 2        // which digital pin is it plugged into?
#define DHTTYPE DHT22   // which DHT sensor is it?



TSL2561 tsl(TSL2561_ADDR_FLOAT); //Initalize TSL2561
DHT dht(DHTPIN, DHTTYPE);  // Initalize DHT22/AM2302




void setup() {
  
  Serial.begin(9600);  // Set serial baud rate

  tsl.begin();
  tsl.setGain(TSL2561_GAIN_16X);
  tsl.setTiming(TSL2561_INTEGRATIONTIME_13MS);

}
void loop() {
  
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  
  uint32_t lum = tsl.getFullLuminosity();
  uint16_t ir, full;
  ir = lum >> 16;
  full = lum & 0xFFFF;
  
  Serial.print("IR: ");
  Serial.print(ir);
  Serial.print(", ");
  Serial.print("Vis: ");
  Serial.print(full-ir);
  Serial.print(", ");
  Serial.print("Lux: ");
  Serial.print(tsl.calculateLux(full, ir));
  Serial.print(", ");
  
  Serial.print("Temp1: ");
  Serial.print(t);
  Serial.print(" C, ");
 
  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.println("% ");
  

 
  delay(1000);
}

