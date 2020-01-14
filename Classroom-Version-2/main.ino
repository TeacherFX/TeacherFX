#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>
Adafruit_BME280 bme;

#define SEALEVELPRESSURE_HPA (1013.25) //Setting sea level pressure, can be used to estimate altitude above sea level

unsigned long delayTime;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  bool status;

  // default settings
  // (you can also pass in a Wire library object like &Wire2)
  status = bme.begin(0x76);  
  if (!status) {
    Serial.println("Could not find a valid BME280 sensor, check wiring!");
    while (1);
  }
  
  Serial.println("-- Default Test --");
  delayTime = 1000;

  Serial.println();

}

void loop() {
  // put your main code here, to run repeatedly:
  int val = analogRead(36);  // read the input pin
  Serial.print("Soil Moisture: ");
  Serial.print(val);
  Serial.println();
  printValues();
  delay(2000);

}


void printValues() {
  Serial.print("Temperature = ");
  Serial.print(bme.readTemperature());
  Serial.println(" *C");
  
  Serial.print("Pressure = ");
  Serial.print(bme.readPressure() / 100.0F);
  Serial.println(" hPa");
  
  Serial.print("Humidity = ");
  Serial.print(bme.readHumidity());
  Serial.println(" %");

    Serial.println();
}

  
