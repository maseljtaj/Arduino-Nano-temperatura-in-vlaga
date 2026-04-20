# 🌡️ Arduino Nano – Merjenje temperature in vlage

## 📖 1. Opis delovanja

Projekt meri temperaturo in relativno vlago z uporabo senzorja DHT11.
Podatki se v realnem času prikazujejo na OLED zaslonu (SSD1306).
Za bolj stabilne rezultate se uporablja povprečenje (smoothing).

---

## ⚙️ 2. Kosovnica (BOM)

* Arduino Nano
* DHT11 senzor
* OLED SSD1306 (I2C)
* povezovalne žice

---

## 🔌 3. Vezava (shema)

![Vezava](Slika-vezave.png)

---

## 🧱 4. Načrt ohišja
(dodaj sliko iz OneShape ali napiši: ni izdelano)

---

## 📐 5. Izračuni
Pri projektu niso potrebni kompleksni izračuni.
Uporabljen je digitalni senzor, ki podatke podaja neposredno.

---
## 💻 6. Program
Koda se nahaja v:
```
code/temp_vlaga_oled_dht.ino
```

---

## 🎥 7. Video delovanja

(dodaj YouTube link)

---

## 📄 8. Poročilo (A-test)
(dodaj PDF datoteko v repo)

---
## 📊 9. Natančnost in komentar

Senzor DHT11 ima:
* ±2°C natančnost temperature
* ±5% natančnost vlage

Meritve lahko rahlo nihajo zaradi okolja in lastnosti senzorja.
---

## 🔧 10. Izboljšave

* uporaba bolj natančnega senzorja (DHT22 ali BME280)
* dodajanje kalibracije
* prikaz grafa meritev
* shranjevanje podatkov
---

## 🧠 Zaključek

Projekt uspešno prikazuje temperaturo in vlago v realnem času.
Primeren je za učenje dela s senzorji in prikazovalniki.
---





