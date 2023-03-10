#include <Arduino.h>

// Define the pin connections for the Sharp 2y0a21 sensor
#define SHARP_PIN A0

void setup() {
  // Initialize the serial port
  Serial.begin(115200);
  
  // Set the Sharp 2y0a21 pin as input
  pinMode(SHARP_PIN, INPUT);
}

void loop() {
  // Read the analog value from the Sharp 2y0a21 sensor
  int sensorValue = analogRead(SHARP_PIN);
  //print the value to the serial monitor
  Serial.println(sensorValue);
  //converts the value to voltage
  float voltage = sensorValue * (3.3 / 4096.0);
  //print the voltage to the serial monitor
  Serial.println(voltage);
  // Convert the analog value to distance in cm
  float distance = 29.988 * pow(voltage , -1.173);
  
  // Print the distance to the serial port
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  
  // Wait for 100ms before reading the sensor again
  delay(100);
}