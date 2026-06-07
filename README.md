# 🌡️ Merjenje temperature in vlage

---

## 📖 1. Opis delovanja

Projekt meri temperaturo in relativno vlago z uporabo senzorja DHT22.  
Podatki se v realnem času prikazujejo na OLED zaslonu SSD1306.  
Za bolj stabilne rezultate se uporablja povprečenje meritev (smoothing).

---

## ⚙️ 2. Kosovnica (BOM)

- Arduino nano
- DHT22 senzor
- OLED SSD1306 (I2C)
- povezovalne žice
- 4x AA baterije

---

## 🔌 3. Vezava (shema)

![Vezava](Slika_vezja.png)

---

## 🧱 4. Načrt ohišja

### Ohišje
![Ohišje](Ohisje_mre.png)

### Pokrov
![Pokrov](Pokrov_mre.png)

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
Test vlage:
![test1](github_test_vlaga.jpg)


Test temperature:
![test2](github_test_temp..jpg)


---

## 📊 9. Natančnost in komentar

Senzor DHT22 ima:

- ± 1.0 °C natančnost temperature
- ± 5 % natančnost vlage

Meritve so bolj stabilne in natančne kot pri senzorji DHT22, lahko pa še vedno rahlo nihajo zaradi okolja ali postavitve.

---

## 🔧 10. Izboljšave

- dodajanje kalibracije
- prikaz grafa meritev
- shranjevanje podatkov
- povezava z Wi-Fi ali Bluetooth
- spletni prikaz podatkov

---

## 🧠 Zaključek
Težave in rešitve

Med izdelavo merilnika temperature in vlage sva naletela na več težav. Največ težav je povzročalo napajanje naprave. Sprva sva uporabljala 9 V baterijo, vendar OLED zaslon ni deloval pravilno. Arduino Nano se je sicer vklopil, zaslon pa je ostal ugasnjen ali pa je deloval nezanesljivo. Po preverjanju vezave sva ugotovila, da 9 V baterija ni zagotavljala dovolj stabilnega napajanja za celoten sistem.
Pojavile so se tudi težave pri povezovanju komponent. Večkrat sva preverjala pravilnost povezav med Arduino Nano, OLED zaslonom in DHT senzorjem. Zaradi velikega števila povezav je prišlo do nekaj napačnih priklopov, ki sva jih odpravila s pregledom vezave in primerjavo s shemo.
Pri testiranju je prišlo tudi do okvare enega Arduino Nano modula. Zaradi napačne vezave oziroma kratkega stika se je mikrokontroler začel pregrevati. Težavo sva rešila z zamenjavo modula in dodatnim preverjanjem povezav pred vsakim novim preizkusom.
Težave so se pojavljale tudi pri branju podatkov z DHT senzorja. Občasno se je na zaslonu izpisalo sporočilo »Error«, ker senzor ni vrnil veljavne meritve. Po preverjanju kode in povezav sva ugotovila, da gre za običajno lastnost senzorja, saj občasno ne uspe pravilno prebrati podatkov. Naprava sicer po naslednji meritvi ponovno normalno deluje.
Veliko časa sva namenila tudi izdelavi in prilagajanju 3D-tiskanega ohišja. Potrebno je bilo večkrat prilagoditi dimenzije odprtin za zaslon, senzor in stikalo, da so se vsi deli pravilno prilegali.
Kljub težavam sva napravo uspešno dokončala. Projekt nama je omogočil pridobitev novih znanj s področja programiranja Arduino naprav, povezovanja elektronskih komponent, odpravljanja napak ter 3D-modeliranja in 3D-tiskanja.
