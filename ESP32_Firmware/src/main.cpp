#include <Arduino.h>
#include <TFT_eSPI.h>
#include <WiFi.h>
// Add the AWS IoT Library
#include <WiFiClientSecure.h>
#include <MQTTClient.h>
#include "secrets.h"

// Button definitions
const char BUTTON_0 = 0;
const char BUTTON_1 = 35;

// display library instance
TFT_eSPI tft = TFT_eSPI();
char buff[512];


// AWS IoT instance
WiFiClientSecure net = WiFiClientSecure();
MQTTClient client = MQTTClient(1024);

char* HOST_ADDRESS = "https://abc.com";
char* CLIENT_ID = "that thingo";
char payload[512];
char rcvdPayload[512];


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
  WiFi.begin(SSID, PASSWORD);
  while (WiFi.status() != WL_CONNECTED){
    delay(200);
    Serial.print(".");
  }

  Serial.println();
  Serial.println("WiFi Connected!");

  tft.print(WiFi.localIP());

  // Prepare credentials
  net.setCACert(AWS_CERT_CA);
  net.setCertificate(AWS_CERT_CRT);
  net.setPrivateKey(AWS_CERT_PRIVATE);

  sleep(3);
}

int counter = 0;

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


  counter++;
  sleep(1);
}