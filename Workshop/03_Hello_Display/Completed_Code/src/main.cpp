#include <Arduino.h>
// Include the TFT display library
#include <TFT_eSPI.h>

// Button definitions
const char BUTTON_0 = 0;
const char BUTTON_1 = 35;

// display library instance
TFT_eSPI tft = TFT_eSPI();
char buff[512];



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
  sleep(3);

}

int counter = 0;

void loop() {
  // Simple multi line string formatting
  Serial.print("loop ");
  Serial.println(counter);
  
  // Interacting with the display writes individual pixels with no context
  // So existing pixels will remain set if we dont refresh them
  // The easiest way to do this is by filling the entire background again and writing everything fresh
  tft.fillScreen(TFT_GREEN);

  // Things look cramped in the top corner
  // Lets move the cursor out a little bit and make the text larger
  tft.setCursor(20, 20, 2);
  tft.setTextSize(3);

  // Lets write the counter to the display
  tft.println(counter);

  counter++;
  sleep(1);
}

// Extension options
// Use the button imputs to select between 4 different colours
// Adjust the colour of the background slowly over time #PRIDE