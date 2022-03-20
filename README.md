# V0.4
Programa patobulinta ir leidžia sugeneruoti naują studentų failą arba atlikti spartos analizę su 1000, 10000, 100000, 1000000, 10000000 įrašų.  

![Screenshot 2022-03-20 092714](https://user-images.githubusercontent.com/99315244/159152772-7b550ec3-74ef-4d20-ac8e-f13044180326.png)  

*Header failai:*  
  **file.h** - duomenų nuskaitymo iš failo funkcijos prototipas.  
  **functions.h**  - tarpinių (įvesties, išvesties ir t.t.).  
  **libraries_and_std.h** - bibliotekos, funkcijų prototipai ir std naudojamų komandų aprašas.  
  **manual.h** - ranka įvedamų duomenų funkcijos prototipas.  
  **struct.h** - studento struktūros failo nuskaitymui ir skaičiavimams.  
*Source failai:*  
**main.cpp** - pagrindinė funkcija iš kurios kreipiamasi į visas kitas funkcijas pagal naudotojo poreikį. Galima pasirinkti duomenis nuskaityti iš failo arba vesti ranka.  
**create_file.cpp** - studentų failo pagal vartotojo nustatymus generavimo funkcija.  
**file.cpp** - duomenų nuskaitymo iš failo funkcija. Patikrina, ar egzistuoja failas, iš kurio nuskaitomi duomenys, patikrina, ar failas netuščias ir apie tai infomuoja naudotoją. Jei viskas gerai, nuskaito duomenis.  
**manual.cpp** - leidžia vartotojui ranka vesti studento duomenis arba generuoti pažymius atsitiktinai.  
**functions.cpp** - tarpinės: vidurkio, medianos, įvesties, išvesties į konsolę ir t.t., funkcijos. 




