#include <Arduino.h>

// Define simple names for the hardware buttons
// 1 - Easier to remember
// 2 - If we change the connection in the future we only need to make one change in the code
const char BUTTON_0 = 0;
const char BUTTON_1 = 35;

// Code in 'setup()' is run once when the microcontroller is powered up
// This is where configuration and initialisation of the hardware is typically performed

void setup() {
    // Enable the default serial port and set the baud rate to 115,200 bps
    Serial.begin(115200);

    // Configure the IO pins as inputs
    // Inputs cannot "float" they need an anchor
    // This is in the form of a pull up resistor built into the chip that we can enable 
    pinMode(BUTTON_0, INPUT_PULLUP);
    pinMode(BUTTON_1, INPUT_PULLUP);

    // Inputs cannot "float" they need an anchor
    // This is in the form of a pull up resistor built into the chip that we can enable 

    // Push text to the serial port, probably still the most common debugging technique 
    Serial.println("Hello World");

    // Burn clock cycles and do nothing for 2 seconds
    sleep(2);
}

// Code in 'loop()' runs forver.... (ideally)
// With a lack of service managers, cron, task schedulers or other OS features
// An endless loop keeps the controller functioning
void loop() {
  Serial.println("loop");

  // read the digital input BUTTON_0
  if(digitalRead(BUTTON_0) == false){
    // What is with the inverted logic?
    // Because we have PULLUP resistors enable and the buttons are a type called 'Normally Open'
    // This means when the button is not pressed the weak pull up resistor supplys 3.3v to the input, a logic 1
    // When we press the button, it connects the pin directly to ground/0v and we get a logic 0
    // So the logic in our code is reversed, this is not uncommon for microcontrollers. It is often easier to design
    //   a circuit layout the connects buttons to ground instead of 3.3v when pressed thanks to 'ground planes'

    Serial.println("Button 0 is pressed");
  }

  // read the digital input BUTTON_1
  if (digitalRead(BUTTON_1) == false){
      Serial.println("Button 1 is pressed");
  }

  sleep(1);
}