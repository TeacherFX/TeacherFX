#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>
Adafruit_BME280 bme;

#define SEALEVELPRESSURE_HPA (1013.25) //Setting the pressure of sea level, this can be used to estimate altitude using pressure

unsigned long delayTime;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);                    //Recommend leaving this at 115200 so if there is a boot fail you can see it as ESP32 operates on 115200
  bool status;

  status = bme.begin(0x76);                //This returns a 1 if the BME is working, and 0 if not
  if (!status) {                           //If !status means "If Not Status" where status is a 1 or a 0 as per the previous line.
    Serial.println("Could not find a valid BME280 sensor, check wiring!");
    delay(2000);                           //Delay in milliseconds
    while (1);                             //This creates a loop until the BME is detected
  }
  
  Serial.println("-- Default Test --");
  delayTime = 1000;

  Serial.println();

}

void loop() {
  // put your main code here, to run repeatedly:
  int val = analogRead(36);  //This is the signal pin connected to the soil moisture sensor
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

  
