#include <Arduino.h>
#include <TFT_eSPI.h>
// Add the WiFi library and our secrets definition
#include <WiFi.h>
#include "secrets.h"
// Button definitions
const char BUTTON_0 = 0;
const char BUTTON_1 = 35;

// display library instance
TFT_eSPI tft = TFT_eSPI();
char buff[512];

// WiFi Parameters are define in the secrets header file

void setup() {
  Serial.begin(115200);
  Serial.println("Hello World");

  pinMode(BUTTON_0, INPUT_PULLUP);
  pinMode(BUTTON_1, INPUT_PULLUP);

  Serial.print("Initialise LCD");
  
  tft.init();
  tft.setRotation(3);
  tft.fillScreen(TFT_WHITE);
  tft.setCursor(0, 0, 2);
  tft.setTextSize(2);
  tft.setTextColor(TFT_RED);
  tft.println(" Hello World ");

  Serial.println("Connecting to WiFi");

  // Initialise the WiFi library with network parameters  
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED){
    delay(200);
    Serial.print(".");
  }

  // Output a carridge return
  Serial.println();
  // There are better string formatters and dedicated serial debugging tools for logging
  // Today we are keeping things simple and matching the style of other resources
  Serial.println("WiFi Connected!");

  // Lets update the user with information on the LCD
  tft.print(WiFi.localIP());
  sleep(3);
}


void loop() {
  // Simple multi line string formatting
  Serial.print("loop ");
  Serial.println(counter);
  
  tft.fillScreen(TFT_BLUE);
  tft.setCursor(5, 0, 2);
  tft.setTextSize(2);
  tft.print("IP: ");
  tft.println(WiFi.localIP());
  tft.print("Channel: ");
  tft.println(WiFi.channel());
  tft.setTextSize(2);
  tft.println("MAC: ");
  tft.print(WiFi.macAddress());


  sleep(1);
}