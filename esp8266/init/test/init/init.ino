#include "DHT.h"
#include <ESP8266WiFi.h>
#include <SPI.h>
#define DHTPIN 2     // what digital pin we're connected to
#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321
#define CS_PIN 15
DHT dht(DHTPIN, DHTTYPE);


void setup() {
  Serial.begin(9600);
  pinMode(A0, INPUT);
  dht.begin();
}

void loop() {
    delay(2000);
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();

  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
/*-------------------------------------------------------------------------------------------*/
int l = 1024 - analogRead(A0);
/*-------------------------------------------------------------------------------------------*/
  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.print(" *C\t");
  Serial.print("Luminosity: ");
  Serial.print(l);
  Serial.print("\n");
}
