#include <Arduino.h>

// Define the pin connections for the A4988 driver
#define DIR_PIN 14
#define STEP_PIN 27
#define ENABLE_PIN 26

// Define the number of steps per revolution of the stepper motor
const int stepsPerRevolution = 200;

void setup() {
  // Initialize the serial port
  Serial.begin(9600);
  
  // Set the A4988 driver pins as outputs
  pinMode(DIR_PIN, OUTPUT);
  pinMode(STEP_PIN, OUTPUT);
  pinMode(ENABLE_PIN, OUTPUT);
  
  // Disable the A4988 driver
  digitalWrite(ENABLE_PIN, HIGH);
}

void loop() {
  // Rotate the stepper motor clockwise for one revolution
  rotate(stepsPerRevolution, true);
  delay(1000);
  
  // Rotate the stepper motor counterclockwise for one revolution
  rotate(stepsPerRevolution, false);
  delay(1000);
}

void rotate(int steps, bool clockwise) {
  // Set the direction of rotation
  digitalWrite(DIR_PIN, clockwise ? HIGH : LOW);
  
  // Step the motor the specified number of steps
  for (int i = 0; i < steps; i++) {
    digitalWrite(STEP_PIN, HIGH);
    delayMicroseconds(500);
    digitalWrite(STEP_PIN, LOW);
    delayMicroseconds(500);
  }
}
