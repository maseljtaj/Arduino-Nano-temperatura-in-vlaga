#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <DHT.h>

// OLED
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// DHT22
#define DHTPIN 10
#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE);

// KALIBRACIJA
float tempOffset = -0.9;   // temperatura
float humOffset  = 3.0;    // vlaga (+3%)

void setup() {

  // OLED start
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    while (true);
  }

  // DHT22 start
  dht.begin();

  // ZAGON ekran
  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);

  display.setTextSize(2);
  display.setCursor(18, 24);
  display.println("ZAGON");

  display.display();

  delay(1500);
}

void loop() {

  // Branje senzorja + kalibracija
  float temp = dht.readTemperature() + tempOffset;
  float hum  = dht.readHumidity() + humOffset;

  display.clearDisplay();

  // ERROR
  if (isnan(temp) || isnan(hum)) {

    display.setTextSize(2);
    display.setCursor(18, 24);
    display.println("ERROR");

    display.display();

    delay(2000);
    return;
  }

  // TEMP
  display.setTextSize(1);
  display.setCursor(0, 22);
  display.print("Temp:");

  display.setTextSize(2);
  display.setCursor(42, 18);

  display.print(temp, 1);

  // °
  display.drawCircle(96, 22, 2, SSD1306_WHITE);

  // C
  display.setCursor(101, 18);
  display.print("C");

  // VLAGA
  display.setTextSize(1);
  display.setCursor(0, 48);
  display.print("Vlaga:");

  display.setTextSize(2);
  display.setCursor(52, 44);

  display.print(hum, 0);
  display.print("%");

  display.display();

  delay(2000);
}
