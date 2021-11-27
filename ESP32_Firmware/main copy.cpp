#include <Arduino.h>
#include <TFT_eSPI.h>

TFT_eSPI tft = TFT_eSPI();

char buff[512];
static const char* TAG = "MAIN";

void setup() {
  Serial.begin(115200);
  ESP_LOGI(TAG, "Booting");

  tft.init();
  tft.setRotation(0);
  tft.fillScreen(TFT_WHITE);
  tft.setTextSize(2);
  tft.setTextColor(TFT_GREEN);
  tft.setCursor(0, 0);
  tft.setTextDatum(MC_DATUM);
  tft.setTextSize(1);

  tft.setSwapBytes(true);
  sleep(3);
}

void loop() {
  // put your main code here, to run repeatedly:
  ESP_LOGI(TAG, "RED");
  tft.fillScreen(TFT_RED);
  sleep(3);
  ESP_LOGI(TAG, "BLUE");
  tft.fillScreen(TFT_BLUE);
  sleep(3);
  ESP_LOGI(TAG, "GREEN");
  tft.fillScreen(TFT_GREEN);
  sleep(3);

}