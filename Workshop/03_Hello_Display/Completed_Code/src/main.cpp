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
  

  if(digitalRead(BUTTON_0) == false){
    Serial.println("Button 0 is pressed");
    // Increment the counter
    counter++;
  }

  // read the digital input BUTTON_1
  if (digitalRead(BUTTON_1) == false){
      Serial.println("Button 1 is pressed");
      //decrement the counter
      counter--;
  }
  Serial.print("counter value: ");
  Serial.println(counter);

  // This graphic library is very lightweight
  // There is no DOM, or layers or contextual smarts.
  // It sets pixel values and that is it!
  // This means pixels must be cleared when numbers change 
  tft.fillScreen(TFT_LIGHTGREY);

  // The cursor must be returned back to the start of the screen too
  // X, Y, font style are set with a single command
  tft.setCursor(10,10,1);

  // We also want to make the text more legible
  // This code could also be moved to 'setup()' 
  tft.setTextSize(3);

  // Update the LCD with the counter value
  // The library will automatically interpret the integer value and convert it to a string
  tft.println(counter);

  sleep(1);
}

// Extension options
// How can you stop the display from flickering when there is no activity?
// What happens with button input if sleep time is reduced?
// Adjust the colour of the background slowly over time #PRIDE
