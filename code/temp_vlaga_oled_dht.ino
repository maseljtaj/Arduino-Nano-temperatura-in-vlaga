#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <DHT.h>

// OLED nastavitve
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// DHT22 nastavitve
#define DHTPIN 10
#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE);

void setup() {

  // zagon OLED
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    while (true);
  }

  // zagon DHT22
  dht.begin();

  // začetni ekran
  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);

  display.setTextSize(2);
  display.setCursor(10, 20);
  display.println("ZAGON");

  display.display();

  delay(2000);
}

void loop() {

  delay(3000);

  float temp = dht.readTemperature();
  float hum = dht.readHumidity();

  display.clearDisplay();

  // če DHT22 ne dela
  if (isnan(temp) || isnan(hum)) {

    display.setTextSize(1);
    display.setCursor(0, 25);
    display.println("DHT22 ERROR");

    display.display();
    return;
  }

  // temperatura
  display.setTextSize(2);
  display.setCursor(0, 0);

  display.print("Temp:");
  display.print(temp, 1);
  display.print("C");

  // vlaga
  display.setCursor(0, 35);

  display.print("Vlaga:");
  display.print(hum, 0);
  display.print("%");

  display.display();
}
