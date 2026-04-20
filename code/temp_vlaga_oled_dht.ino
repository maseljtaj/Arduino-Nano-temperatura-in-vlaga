#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <DHT.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);
#define DHTPIN 3
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

float tempSmooth = 0;
float humSmooth = 0;

void setup() {
  dht.begin();
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
}
void loop() {

  float t = dht.readTemperature();
  float h = dht.readHumidity();
  if (isnan(t) || isnan(h)) return;
  
  // ===== SMOOTHING =====
  tempSmooth = (tempSmooth * 0.8) + (t * 0.2);
  humSmooth  = (humSmooth * 0.8) + (h * 0.2);

  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 5);
  display.print("T:");
  display.print(tempSmooth,1);
  display.print((char)247);
  display.print("C");
  display.setCursor(0, 35);
  display.print("H:");
  display.print(humSmooth,0);
  display.print("%");
  display.display();
  delay(2000);
}
