#include "model.h"  // Including the ML model header file

#define LM35_PIN A0  // LM35 connected to Analog pin A0

void setup() {
  Serial.begin(9600);  // Initialize serial communication
}

void loop() {
  int sensorValue = analogRead(LM35_PIN);    // Read analog value from the LM35
  float voltage = (sensorValue / 1024.0) * 5000;  // Convert to millivolts
  float temperature = voltage / 10.0;             // LM35 gives 10mV per °C

  // Prepare the input as an array
  float x[1] = { temperature };

  // Predict moisture using the model
  float moisture = predict(x);

  // Print temperature and predicted moisture
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.print(" °C, Predicted Moisture: ");
  Serial.println(moisture);

  delay(1000);  // Delay between readings
}
