# 🌡️ Merjenje temperature in vlage

---

## 📖 1. Opis delovanja

Projekt meri temperaturo in relativno vlago zraka z uporabo senzorja DHT22. Izmerjene podatke Arduino Nano obdela in jih v realnem času prikazuje na OLED zaslonu SSD1306.

Za bolj stabilne rezultate program uporablja povprečenje več meritev (smoothing), kar zmanjša manjša nihanja prikazanih vrednosti. Naprava je nameščena v 3D-tiskanem ohišju in se napaja s štirimi AA baterijami, zato je primerna za prenosno uporabo.

---
## ⚙️ 2. Kosovnica (BOM)
Uporabila sva:
- Arduino Nano
- DHT22 senzor temperature in vlage
- OLED SSD1306 zaslon (I2C)
- povezovalne žice
- univerzalna perforirana ploščica (perfboard)
- stikalo ON/OFF
- držalo za 4x AA baterije
- 4x AA baterije
- 3D tiskano ohišje
- vijaki in matice M3

---

## 🔌 3. Vezava (shema)

![Vezava](Slika_vezja.png)

---

## 🧱 4. Načrt ohišja

### Ohišje:
![Ohišje](Ohisje_mre.png)


### Pokrov:
![Pokrov](Pokrov_mre.png)


### Okvir:
![okvir](slika_okvira.png)

---

## 📐 5. Izračuni

Pri projektu niso potrebni kompleksni izračuni.  
Uporabljen je digitalni senzor, ki podatke podaja neposredno.

---

## 💻 6. Program

Koda se nahaja v:

```text
code/temp_vlaga_oled_dht.ino
```

## 🎥 7. Video delovanja

Video delovanja projekta:

---

## 📄 8. Poročilo (A-test)

## Test vlage:
![test1](github_test_vlaga.jpg)

## Rezultati merjenja vlage:

| Meritev | Mx [%] | mx [%] |
|----------|---------|---------|
| 1 | 1 | 1,82 |
| 2 | 0 | 0,00 |
| 3 | 1 | 1,79 |
| 4 | 2 | 2,04 |
| 5 | 1 | 2,08 |
| 6 | 1 | 2,13 |
| 7 | 1 | 1,32 |
| 8 | 0 | 0,00 |
| 9 | 1 | 2,56 |
| 10 | 0 | 0,00 |

| Parameter | Vrednost |
|------------|----------|
| Največja meja napake Mx | 2 % |
| Največja relativna meja napake mx | 2,56 % |
| Deklarirana meja napake | ±5 % |
| Ocena instrumenta | Instrument je zanesljiv znotraj deklarirane meje napake. |

## Test temperature:
![test2](github_test_temp..jpg)

## Rezultati merjenja temperature:

| Meritev | Mx [°C] | mx [%] |
|----------|----------|---------|
| 1 | 0,4 | 1,50 |
| 2 | 0,2 | 0,74 |
| 3 | 0,2 | 0,74 |
| 4 | 0,2 | 0,75 |
| 5 | 0,1 | 0,43 |
| 6 | 0,1 | 0,43 |
| 7 | 0,2 | 4,00 |
| 8 | 0,1 | 1,85 |
| 9 | 0,2 | 0,63 |
| 10 | 0,3 | 0,67 |

| Parameter | Vrednost |
|------------|----------|
| Največja meja napake Mx | 0,4 °C |
| Največja relativna meja napake mx | 4,00 % |
| Deklarirana meja napake | ±1,0 °C |
| Ocena instrumenta | Instrument je zanesljiv znotraj deklarirane meje napake. |

---

## 📊 9. Natančnost in komentar

Senzor DHT22 ima:

* ± 1,0 °C natančnost temperature
* ± 5 % natančnost relativne vlage

Po vklopu naprave senzor potrebuje nekaj sekund za stabilizacijo meritev. V tem času se lahko prikazane vrednosti nekoliko razlikujejo od dejanskih. Ko se senzor stabilizira, prikazuje pravilne in zanesljive meritve.

Pri meritvah je bilo opaziti manjša nihanja vrednosti, kar je običajno za tovrstne senzorje. Na rezultate lahko vplivajo spremembe temperature okolice, gibanje zraka, bližina virov toplote ter sama postavitev senzorja v ohišju.

Za bolj stabilen prikaz podatkov se v programu uporablja povprečenje več zaporednih meritev (smoothing). Tako so prikazane vrednosti bolj mirne in lažje berljive.

Meritve so dovolj natančne za spremljanje temperature in vlage v prostoru ter za izobraževalne in hobi projekte.


---

## 🔧 10. Izboljšave

- dodajanje kalibracije
- prikaz grafa meritev
- shranjevanje podatkov (EEPROM)
- povezava z Wi-Fi ali Bluetooth (ESP)
- spletni prikaz podatkov

---
## 🧠 Zaključek

### Težave in rešitve

Med izdelavo merilnika temperature in vlage sva naletela na več težav. Največ težav je povzročalo napajanje naprave. Sprva sva uporabljala 9 V baterijo, vendar OLED zaslon ni deloval pravilno. Arduino Nano se je sicer vklopil, zaslon pa je ostal ugasnjen ali pa je deloval nezanesljivo. Po preverjanju vezave sva ugotovila, da 9 V baterija ni zagotavljala dovolj stabilnega napajanja za celoten sistem. Težavo sva rešila z uporabo držala za 4x AA baterije, ki je zagotavljalo bolj stabilno napetost.

Pojavile so se tudi težave pri povezovanju komponent. Večkrat sva preverjala pravilnost povezav med Arduino Nano, OLED zaslonom in DHT22 senzorjem. Zaradi velikega števila povezav je prišlo do nekaj napačnih priklopov, ki sva jih odpravila s pregledom vezave in primerjavo s shemo.

Pri testiranju je prišlo tudi do okvare enega Arduino Nano modula. Zaradi napačne vezave oziroma kratkega stika se je mikrokontroler začel pregrevati. Težavo sva rešila z zamenjavo modula in dodatnim preverjanjem povezav pred vsakim novim preizkusom.

Težave so se pojavljale tudi pri branju podatkov z DHT22 senzorja. Občasno se je na zaslonu izpisalo sporočilo »Error«, ker senzor ni vrnil veljavne meritve. Po preverjanju kode in povezav sva ugotovila, da gre za običajno lastnost senzorja, saj občasno ne uspe pravilno prebrati podatkov. Naprava po naslednji meritvi ponovno normalno deluje.

Po vklopu naprave je bilo potrebno počakati nekaj sekund, da se je senzor stabiliziral in začel prikazovati pravilne meritve temperature in vlage.

Veliko časa sva namenila tudi izdelavi in prilagajanju 3D-tiskanega ohišja. Potrebno je bilo večkrat prilagoditi dimenzije odprtin za zaslon, senzor, stikalo in baterijsko držalo, da so se vsi deli pravilno prilegali.

### Končni komentar

Projekt sva uspešno dokončala in dosegla zastavljene cilje. Izdelana naprava zanesljivo meri temperaturo in relativno vlago ter rezultate v realnem času prikazuje na OLED zaslonu.

Med izdelavo sva pridobila veliko praktičnega znanja s področja programiranja mikrokontrolerjev Arduino, povezovanja elektronskih komponent, odpravljanja napak, načrtovanja vezij ter 3D-modeliranja in 3D-tiskanja. Projekt nama je pokazal, kako pomembna sta pravilno načrtovanje napajanja in natančno preverjanje povezav med komponentami.

Končni izdelek deluje zanesljivo, je enostaven za uporabo in predstavlja dobro osnovo za nadaljnje nadgradnje, kot so brezžični prenos podatkov, shranjevanje meritev ali spletni prikaz rezultatov.
